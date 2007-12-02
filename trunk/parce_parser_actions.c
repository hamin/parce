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


#include "parce_parser_token.h"

#include "parce_parser_actions.h"

#include "parce_parser.h"

#include <stdlib.h>
#include <string.h>


extern token *tokenCopy( token *original ) {

	token *result = tokenNew();

	result->type = original->type;
	result->text = strncpy(result->text, original->text, strlen(original->text));
	result->value = original->value; // FIXME: this will only work when copying from a stack object
	result->first = original->first;
	result->next = original->next;
	
	return result;
}

extern token *tokenListAppend( token *head, token *last ) {
	token *oldLast = head->next;
	while (oldLast = oldLast->next)
		;
	oldLast->next = last;
	return head;
}



/** specialized token creation functions for terminal symbols **/

/* multi-character operators */
token *tPtrOp( void ) { return NULL; }

token *tIncOp( void ) { return NULL; }
token *tDecOp( void ) { return NULL; }

token *tBooleanAndOp( void ) { return NULL; }
token *tBooleanOrOp( void ) { return NULL; }
token *tEqualToOp( void ) { return NULL; }
token *tLessOrEqualOp( void ) { return NULL; }
token *tGreaterOrEqualOp( void ) { return NULL; }
token *tNotEqualToOp( void ) { return NULL; }

token *tLeftShiftOp( void ) { return NULL; }
token *tRightShiftOp( void ) { return NULL; }

token *tMultAssignOp( void ) { return NULL; }
token *tDivAssignOp( void ) { return NULL; }
token *tModAssignOp( void ) { return NULL; }
token *tAddAssignOp( void ) { return NULL; }
token *tSubAssignOp( void ) { return NULL; }

token *tLeftAssignOp( void ) { return NULL; }
token *tRightAssignOp( void ) { return NULL; }
token *tAndAssignOp( void ) { return NULL; }
token *tXORAssignOp( void ) { return NULL; }
token *tOrAssignOp( void ) { return NULL; }

/* multi-purpose operators */
token *tStarOp( void ) { return NULL; }
token *tAmpOp( void ) { return NULL; }
token *tExclamOp( void ) { return NULL; }
token *tBarOp( void ) { return NULL; }
token *tSubOp( void ) { return NULL; }

/* arithmetic operators */
token *tAddOp( void ) { return NULL; }
token *tDivOp( void ) { return NULL; }
token *tModOp( void ) { return NULL; }

/* boolean operators */
token *tLessOp( void ) { return NULL; }
token *tGreaterOp( void ) { return NULL; }

/* bitwise operators */
token *tXOROp( void ) { return NULL; }
token *tCompOp( void ) { return NULL; }

/* other single character operators */
token *tAssignOp( void ) { return NULL; }
token *tDotOp( void ) { return NULL; }

/* braces/parentheses */
token *tCurlyL( void ) { return NULL; }
token *tCurlyR( void ) { return NULL; }
token *tSquareL( void ) { return NULL; }
token *tSquareR( void ) { return NULL; }
token *tParenL( void ) { return NULL; }
token *tParenR( void ) { return NULL; }

/* punctuation marks */
token *tComma( void ) { return NULL; }
token *tColon( void ) { return NULL; }
token *tSemi( void ) { return NULL; }
token *tQuest( void ) { return NULL; }

/* built in types */
token *tChar( void ) { return NULL; }
token *tShort( void ) { return NULL; }
token *tInt( void ) { return NULL; }
token *tLong( void ) { return NULL; }
token *tSigned( void ) { return NULL; }
token *tUnsigned( void ) { return NULL; }
token *tFloat( void ) { return NULL; }
token *tDouble( void ) { return NULL; }
token *tConst( void ) { return NULL; }
token *tVolatile( void ) { return NULL; }
token *tVoid( void ) { return NULL; }

/* reserved words */
token *tExtern( void ) { return NULL; }
token *tStatic( void ) { return NULL; }
token *tAuto( void ) { return NULL; }
token *tRegister( void ) { return NULL; }

token *tSizeof( void ) { return NULL; }

/* user defined type creation */
token *tTypedef( void ) { return NULL; }
token *tStruct( void ) { return NULL; }
token *tUnion( void ) { return NULL; }
token *tEnum( void ) { return NULL; }

token *tEllipsis( void ) { return NULL; }

/* control flow */
token *tIf( void ) { return NULL; }
token *tElse( void ) { return NULL; }
token *tSwitch( void ) { return NULL; }
token *tCase( void ) { return NULL; }
token *tDefault( void ) { return NULL; }
token *tWhile( void ) { return NULL; }
token *tDo( void ) { return NULL; }
token *tFor( void ) { return NULL; }
token *tGoto( void ) { return NULL; }
token *tContinue( void ) { return NULL; }
token *tBreak( void ) { return NULL; }
token *tReturn( void ) { return NULL; }

/* comments */
token *tBlockComment( void ) { return NULL; }
token *tInLineComment( void ) { return NULL; }


/** objective-c extensions **/
token *tObjCId( void ) { return NULL; }
token *tObjCSelf( void ) { return NULL; }
token *tObjCSuper( void ) { return NULL; }
token *tObjCIn( void ) { return NULL; }
token *tObjCOut( void ) { return NULL; }
token *tObjCInout( void ) { return NULL; }
token *tObjCBycopy( void ) { return NULL; }
token *tObjCByref( void ) { return NULL; }
token *tObjCOneway( void ) { return NULL; }

token *tObjCAtClass( void ) { return NULL; }
token *tObjCAtProtocol( void ) { return NULL; }
token *tObjCAtInterface( void ) { return NULL; }
token *tObjCAtImplementation( void ) { return NULL; }
token *tObjCAtEnd( void ) { return NULL; }

token *tObjCAtPrivate( void ) { return NULL; }
token *tObjCAtPublic( void ) { return NULL; }
token *tObjCAtProtected( void ) { return NULL; }

token *tObjCAtTry( void ) { return NULL; }
token *tObjCAtCatch( void ) { return NULL; }
token *tObjCAtFinally( void ) { return NULL; }
token *tObjCThrow( void ) { return NULL; }

token *tObjCAtDefs( void ) { return NULL; }
token *tObjCAtSynchronized( void ) { return NULL; }
token *tObjCAtSelector( void ) { return NULL; }
token *tObjCAtEncode( void ) { return NULL; }

token *tObjCString( void ) { return NULL; }


// NON-TERMINAL TOKENS

token *gExternalDefinitionList( token *externalDefinitions, token *externalDefinition ) {
	return NULL;
}

token *gDec( token *decSpecs, token *initDeclarators ) {
	return NULL;
}

token *gInitDeclarator( token *typeDeclarator, token *initializer ){ return NULL; }


/* functions */
token *gFunctionDef (token *decSpecs, token *typeDec, token *body ){ return NULL; } // decSpecs may be NULL
token *gFunctionBody ( token *decs, token *compoundStatement ){ return NULL; } // decs may be NULL

/* type specifiers */
token *gStructOrUnionSpec( token *structOrUnion, token *name, token *structDecs ){ return NULL; } // name or structDecs may be NULL (but not both)

/* structure/union elements */
token *gStructDec( token *specQuals, token *declarators ){ return NULL; }
token *gStructDeclarator( token *typeDeclarator, token *initValue ){ return NULL; } // type declarator or initValue may be null (but not both)

/* enumeration elements */
token *gEnumSpec( token *name, token *enumerators ){ return NULL; } // name or enumerators may be NULL (but not both)
token *gEnumerator( token *name, token *initValue ){ return NULL; } // initValue may be NULL

/* type declarations */
token *gTypeDeclarator( token *pointer, token *declarators ){ return NULL; } // pointer may be NULL
token *gArrayDeclarator( token *length ){ return NULL; } // '[' length ']' length may be NULL
token *gListDeclarator( token *parameters ){ return NULL; } // '(' parameters ')' parameters may be NULL, or a list of types or a list of identifiers{ return NULL; } either list may end in an ellipsis
token *gParameterDec( token *specs, token *declarator ){ return NULL; } // declarator is a typeDeclarator or an abstractDeclarator, or may be NULL

token *gStructInitializer( token *assignmentExpr ){ return NULL; }


/** Objective-C **/

/* external definitions */
token *gClassDecs( token *identifiers ){ return NULL; }
token *gProtocolDecs( token *identifiers ){ return NULL; }

token *gClassInterface( token *className, token *superClassName, token *protocolRefs, token *ivars, token *interfaceDecs ){ return NULL; }
token *gCategoryInterface( token *className, token *categoryName, token *protocolRefs, token *interfaceDecs ){ return NULL; }
token *gProtocolDec( token *protocolName, token *protocolRefs, token *interfaceDecs ){ return NULL; }

token *gClassImplementation(token *className, token *methodDefs ){ return NULL; }
token *gCategoryImplementation( token *className, token *categoryName, token *methodDefs ){ return NULL; }

token *gClassMethodDec( token *returnType, token *selector ){ return NULL; }
token *gInstanceMethodDec( token *returnType, token *selector ){ return NULL; }

token *gClassMethodDef( token *returnType, token *selector, token *decs, token *compoundStmt ){ return NULL; }
token *gInstanceMethodDef( token *returnType, token *selector, token *decs, token *compoundStmt ){ return NULL; }

/* type specifiers */
token *gTypeSpec( token *typeSpec, token *protocolRefs ){ return NULL; } // type is either OBJC_ID or CLASS_NAME; protocolRefs is a list of protocol names

token *gStructObjCDefs( token *className ){ return NULL; }
