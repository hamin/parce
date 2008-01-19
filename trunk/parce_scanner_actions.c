/*
 *  parce: objc_scanner_actions.c
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


#include "parce_scanner_actions.h"

#include "parce_parser_token.h"

#include <stdlib.h>

//#include "parce_parser_context.h" // identifiers (macros, type names, classes, protocols, categories, variables)



void scanInitialize( void ) {
	tokenSetDeleteFunction(free);
}

void scanMacro( YYSTYPE yylval, char *tokenString ) {
return;
}

void scanCommentBlock( YYSTYPE yylval, char *tokenString ) {
	return;
}
void scanCommentLine( YYSTYPE yylval, char *tokenString ) {
	return;
}
void scanWhiteSpace( YYSTYPE yylval, char *tokenString ) {
	return;
}

double scanConstantValue( char *tokenString, const char *formatString ) {
	
	double value = 0.0f;
	
//	sscanf(tokenString, formatString, &value);
	
	return value;
}

int scanConstantShared( YYSTYPE yylval, char *tokenString, const char *formatString ) {
	
	double *doublePtr = malloc(sizeof(double));
	
	yylval->type = CONSTANT;
	yylval->text = tokenString;
	yylval->value = (void *)doublePtr;
	*doublePtr = scanConstantValue(tokenString, formatString);
	return CONSTANT;
}

int scanHexConstant( YYSTYPE yylval, char *tokenString ) {
	return scanConstantShared( yylval, tokenString, "%x" );
	
}
int scanOctalConstant( YYSTYPE yylval, char *tokenString ) {
	return scanConstantShared( yylval, tokenString, "%o" );
}
int scanDecimalConstant( YYSTYPE yylval, char *tokenString ) {
	return scanConstantShared( yylval, tokenString, "%x" );
}
int scanEscapeConstant( YYSTYPE yylval, char *tokenString ) {
	return CONSTANT;
}
int scanFloatEConstant( YYSTYPE yylval, char *tokenString ) {
	return CONSTANT;
}
int scanFloatDotConstant( YYSTYPE yylval, char *tokenString ) {
	return CONSTANT;
}
int scanCString( YYSTYPE yylval, char *tokenString ) {
	
	yylval->type = STRING_LITERAL;
	yylval->text = tokenString;
	
	return STRING_LITERAL;
}
int scanObjCString( YYSTYPE yylval, char *tokenString ) {
	
	yylval->type = OBJC_STRING_LITERAL;
	yylval->text = tokenString;
	
	return OBJC_STRING_LITERAL;
}

/*
 An identifier is stored in a context table as a specialized type determined by the parser, and retrieved on subsequent occurrences
 */

// IDENTIFIER->TYPE_NAME/CLASS_NAME/
int scanType( YYSTYPE yylval, char *tokenString ) {
	
	// check the context stack for a matching type; if found, return associated token type and set yylval
	
	return IDENTIFIER;
}
