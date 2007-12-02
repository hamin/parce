/*
 *  parce: objc_parser_semantic.c
 *
 *  Copyright 2007 Bored Astronaut Software. All rights reserved.

Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:

- Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.

- Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
"AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

 */

#include "parce_parser_token.h"

#include "parce_parser.h"

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
