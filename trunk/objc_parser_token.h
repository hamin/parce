/*
 *  objc_parser_token.h
 *  Codon
 *
 *  Created by Brent Gulanowski on 11/16/07.
 *  Copyright 2007 Bored Astronaut Software. All rights reserved.
 *
 */


// define CUSTOM_TOKEN_TYPE at compile time as a gcc -D flag if you provide a custom token implementation; this token is a node in the abstract syntax tree
#ifndef CUSTOM_TOKEN_TYPE
struct token {
	
	int type; // corresponds to the types in the table defined by Bison for communicating with the scanner
	char *text; // the string from the input file corresponding to this token (optional)
	void *value; // user-defined value (optional); provide a freeFunction for memory release or risk leaks
	struct token *next; // next younger sibling in the list
	struct token *first; // beginning of a list of children
	
};

typedef struct token token;


/** general token lifespan function **/
extern token *tokenNew( void );

// value and firstChild are optional; text is optional (ignored, in fact) for keywords
extern token *tokenNewWithAttributes( int type, char *text, void *value, token *firstChild );
extern void tokenRelease( token *aToken ); // releases firstChild and nextSibling


/** value  **/
typedef void (*freeFunction) ( void * );
extern void tokenSetDeleteFunction ( freeFunction valueFreeFunction );


/** smart setter functions -- these release any existing tokens before replacing them **/
extern void tokenSetNextSibling( token *aToken );
extern void tokenSetFirstChild( token *aToken );
#endif
