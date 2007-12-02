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





/*
#define eatCommentBlock() [[parser scanner] comment:commentBlock()]
#define eatCommentLine() [[parser scanner] comment:commentLine()]
#define eatWhiteSpace() [[parser scanner] whiteSpace:whiteSpace()]
 
#define eat(x) [[CodToken alloc] initWithCode:(x) value:[NSString stringWithUTF8String:yytext]]
#define identifierType() [[parser currentScope] codeForIdentifier:[NSString stringWithUTF8String:yytext]]
 */

void scanMacro(){ return; }

void scanCommentBlock(){ return; }
void scanCommentLine(){ return; }
void scanWhiteSpace(){ return; }

int scanConstant( char *tokenString ){ return CONSTANT; }    // CONSTANT
int scanCString( char *tokenString ){ return STRING_LITERAL; }     // STRING_LITERAL
int scanObjCString( char *tokenString ){ return OBJC_STRING_LITERAL; }  // OBJC_STRING_LITERAL

/*
 An identifier is stored in a context table as a specialized type determined by the parser, and retrieved on subsequent occurrences
 */
int scanType( char *tokenString ){ return IDENTIFIER; }        // IDENTIFIER->TYPE_NAME/CLASS_NAME/
