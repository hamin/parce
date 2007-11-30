/*
 *  objc_parser_semantic.c
 *  Codon
 *
 *  Created by Brent Gulanowski on 11/16/07.
 *  Copyright 2007 Bored Astronaut Software. All rights reserved.
 *
 */

#include "objc_parser_token.h"

#include "objc_parser.h"

#include <stdlib.h>
#include <string.h>


/*
 char **keywordsTable = NULL;
 
 void initializeKeywordsTable( void ) {
	 keywordsTable = malloc(sizeof(char *) * 100);
	 
 }
 */


freeFunction valueFree = (freeFunction)NULL;


void tokenSetDeleteFunction ( freeFunction valueFreeFunction ) {
	valueFree = valueFreeFunction;
}


token *tokenNew( void ) {
	token *result = calloc(1,sizeof(token));
	if(NULL == result) {
		perror("objc_parser failed to allocate token");
		exit(1);
	}
	return result;
}

token *tokenNewWithAttributes( int type, char *text, void *value, token *firstChild ) {
	
	token *result = tokenNew();
	
	result->type = type;
	strcpy(result->text, text);
	result->value = value;
	result->first = firstChild;
	
	return result;
}

void tokenRelease( token *aToken ) {
	
	const int type = aToken->type;
	
	if(type != IDENTIFIER &&
	   type != STRING_LITERAL)
		free(aToken->text);
	
	if(NULL != aToken->value)
		valueFree( aToken->value );
	
	if(NULL != aToken->next)
		tokenRelease(aToken->next);
	
	if(NULL != aToken->first)
		tokenRelease(aToken->first);
	
	if(NULL != aToken)
		free(aToken);
}


/** smart setter functions -- these release any existing tokens before replacing them **/
void tokenSetNextSibling( token *aToken ) {
	
	if(NULL != aToken->next)
		tokenRelease(aToken->next);
	
	aToken->next = aToken;
}

void tokenSetFirstChild( token *aToken ) {
	
	if(NULL != aToken->first)
		tokenRelease(aToken->first);
	
	aToken->first = aToken;
}
