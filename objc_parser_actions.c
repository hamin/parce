/*
 *  parce: objc_parser_semantic.m
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

#import <Foundation/Foundation.h>


#import "objc_parser_token.h"

#import "objc_parser_semantic.h"

#import "objc_parser.h"


#pragma mark Custom Symbols
token *tIdentifier(char *text) {
	return NULL; 
}

token *tConstant(char *text) {
	return NULL;
}

token *tString(char *text) {
	return NULL;
}


#pragma mark sizeof
token *tSizeof( void ) {
	return NULL;
}


#pragma mark Multi-character Operators
token *tPtr( void ) {
	return NULL;
}

token *tInc( void ) {
	return NULL;
}

token *tDec( void ) {
	return NULL;
}

token *tLeftShift( void ) {
	return NULL;
}

token *tRightShift( void ) {
	return NULL;
}

token *tLessOrEqual( void ) {
	return NULL;
}

token *tGreaterOrEqual( void ) {
	return NULL;return NULL;
}

token *tEqualTo( void ) {
	return NULL;
}

token *tNotEqualTo( void ) {
	return NULL;
}


token *tBooleanAnd( void ) {
	return NULL;
}

token *tBooleanOr( void ) {
	return NULL;
}

token *tMultAssign( void ) {
	return NULL;
}

token *tDivAssign( void ) {
	return NULL;
}

token *tModAssign( void ) {
	return NULL;
}

token *tAddAssign( void ) {
	return NULL;
}

token *tSubAssign( void ) {
	return NULL;
}

token *tLeftAssign( void ) {
	return NULL;
}

token *tRightAssign( void ) {
	return NULL;
}

token *tAndAssign( void ) {
	return NULL;
}

token *tXORAssign( void ) {
	return NULL;
}

token *tOrAssign( void ) {
	return NULL;
}


token *tTypedef( void ) {
	return NULL;
}

token *tExtern( void ) {
	return NULL;
}

token *tStatic( void ) {
	return NULL;
}

token *tAuto( void ) {
	return NULL;
}

token *tRegister( void ) {
	return NULL;
}


token *tChar( void ) {
	return NULL;
}

token *tShort( void ) {
	return NULL;
}

token *tInt( void ) {
	return NULL;
}

token *tLong( void ) {
	return NULL;
}

token *tSigned( void ) {
	return NULL;
}

token *tUnsigned( void ) {
	return NULL;
}

token *tFloat( void ) {
	return NULL;
}

token *tDouble( void ) {
	return NULL;
}

token *tConst( void ) {
	return NULL;
}

token *tVolatile( void ) {
	return NULL;
}

token *tVoid( void ) {
	return NULL;
}


token *tStruct( void ) {
	return NULL;
}

token *tUnion( void ) {
	return NULL;
}

token *tEnum( void ) {
	return NULL;
}

token *tEllipsis( void ) {
	return NULL;
}


token *tBlockComment( void ) {
	return NULL;
}

token *tInLineComment( void ) {
	return NULL;
}


token *tIf( void ) {
	return NULL;
}

token *tElse( void ) {
	return NULL;
}

token *tSwitch( void ) {
	return NULL;
}

token *tCase( void ) {
	return NULL;
}

token *tDefault( void ) {
	return NULL;
}

token *tWhile( void ) {
	return NULL;
}

token *tDo( void ) {
	return NULL;
}

token *tFor( void ) {
	return NULL;
}

token *tGoto( void ) {
	return NULL;
}

token *tContinue( void ) {
	return NULL;
}

token *tBreak( void ) {
	return NULL;
}

token *tReturn( void ) {
	return NULL;
}



token *tObjCString( void ) {
	return NULL;
}

token *tObjCId( void ) {
	return NULL;
}

token *tObjCSelf( void ) {
	return NULL;
}

token *tObjCSuper( void ) {
	return NULL;
}

token *tObjCIn( void ) {
	return NULL;
}

token *tObjCOut( void ) {
	return NULL;
}

token *tObjCInout( void ) {
	return NULL;
}

token *tObjCBycopy( void ) {
	return NULL;
}

token *tObjCByref( void ) {
	return NULL;
}

token *tObjCOneway( void ) {
	return NULL;
}


token *tObjCAtClass( void ) {
	return NULL;
}

token *tObjCAtProtocol( void ) {
	return NULL;
}

token *tObjCAtImplementation( void ) {
	return NULL;
}

token *tObjCAtInterface( void ) {
	return NULL;
}

token *tObjCAtEnd( void ) {
	return NULL;
}


token *tObjCAtPrivate( void ) {
	return NULL;
}

token *tObjCAtPublic( void ) {
	return NULL;
}

token *tObjCAtProtected( void ) {
	return NULL;
}


token *tObjCAtTry( void ) {
	return NULL;
}

token *tObjCAtCatch( void ) {
	return NULL;
}

token *tObjCAtFinally( void ) {
	return NULL;
}

token *tObjCThrow( void ) {
	return NULL;
}


token *tObjCAtDefs( void ) {
	return NULL;
}

token *tObjCAtSynchronized( void ) {
	return NULL;
}

token *tObjCAtSelector( void ) {
	return NULL;
}

token *tObjCAtEncode( void ) {
	return NULL;
}


token *tObjCClassName( char *text ) {
	return NULL;
}

token *tObjCProtocolName( char *text ) {
	return NULL;
}

token *tObjCCategoryName( char *text ) {
	return NULL;
}


