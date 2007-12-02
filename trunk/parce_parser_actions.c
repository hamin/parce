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

/* FIXME: we really need to cache all of these and just re-use them */
token *tPtrOp( void ) { return tokenNewWithAttributes(PTR_OP, "*", NULL, NULL); }

token *tIncOp( void ) { return tokenNewWithAttributes(INC_OP, "++", NULL, NULL); }
token *tDecOp( void ) { return tokenNewWithAttributes(DEC_OP, "--", NULL, NULL); }

token *tBooleanAndOp( void ) { return tokenNewWithAttributes(AND_OP, "&&", NULL, NULL); }
token *tBooleanOrOp( void ) { return tokenNewWithAttributes(OR_OP, "||", NULL, NULL); }
token *tEqualToOp( void ) { return tokenNewWithAttributes(EQ_OP, "==", NULL, NULL); }
token *tLessOrEqualOp( void ) { return tokenNewWithAttributes(LE_OP, "<=", NULL, NULL); }
token *tGreaterOrEqualOp( void ) { return tokenNewWithAttributes(GE_OP, ">=", NULL, NULL); }
token *tNotEqualToOp( void ) { return tokenNewWithAttributes(NE_OP, "!=", NULL, NULL); }

token *tLeftShiftOp( void ) { return tokenNewWithAttributes(LEFT_OP, "<<", NULL, NULL); }
token *tRightShiftOp( void ) { return tokenNewWithAttributes(RIGHT_OP, ">>", NULL, NULL); }

token *tMultAssignOp( void ) { return tokenNewWithAttributes(MUL_ASSIGN, "*=", NULL, NULL); }
token *tDivAssignOp( void ) { return tokenNewWithAttributes(DIV_ASSIGN, "/=", NULL, NULL); }
token *tModAssignOp( void ) { return tokenNewWithAttributes(MOD_ASSIGN, "%=", NULL, NULL); }
token *tAddAssignOp( void ) { return tokenNewWithAttributes(ADD_ASSIGN, "+=", NULL, NULL); }
token *tSubAssignOp( void ) { return tokenNewWithAttributes(SUB_ASSIGN, "-=", NULL, NULL); }

token *tLeftAssignOp( void ) { return tokenNewWithAttributes(LEFT_ASSIGN, "<<=", NULL, NULL); }
token *tRightAssignOp( void ) { return tokenNewWithAttributes(RIGHT_ASSIGN, ">>=", NULL, NULL); }
token *tAndAssignOp( void ) { return tokenNewWithAttributes(AND_ASSIGN, "&=", NULL, NULL); }
token *tXORAssignOp( void ) { return tokenNewWithAttributes(XOR_ASSIGN, "^=", NULL, NULL); }
token *tOrAssignOp( void ) { return tokenNewWithAttributes(OR_ASSIGN, "|=", NULL, NULL); }

/* multi-purpose operators */
token *tStarOp( void ) { return tokenNewWithAttributes((unsigned int)'*', "*", NULL, NULL); }
token *tAmpOp( void ) { return tokenNewWithAttributes((unsigned int)'&', "&", NULL, NULL); }
token *tExclamOp( void ) { return tokenNewWithAttributes((unsigned int)'!', "!", NULL, NULL); }
token *tBarOp( void ) { return tokenNewWithAttributes((unsigned int)'|', "|", NULL, NULL); }
token *tSubOp( void ) { return tokenNewWithAttributes((unsigned int)'-', "-", NULL, NULL); }

/* arithmetic operators */
token *tAddOp( void ) { return tokenNewWithAttributes((unsigned int)'+', "+", NULL, NULL); }
token *tDivOp( void ) { return tokenNewWithAttributes((unsigned int)'/', "*/", NULL, NULL); }
token *tModOp( void ) { return tokenNewWithAttributes((unsigned int)'%', "%", NULL, NULL); }

/* boolean operators */
token *tLessOp( void ) { return tokenNewWithAttributes((unsigned int)'<', "<", NULL, NULL); }
token *tGreaterOp( void ) { return tokenNewWithAttributes((unsigned int)'>', ">", NULL, NULL); }

/* bitwise operators */
token *tXOROp( void ) { return tokenNewWithAttributes((unsigned int)'^', "^", NULL, NULL); }
token *tCompOp( void ) { return tokenNewWithAttributes((unsigned int)'~', "~", NULL, NULL); }

/* other single character operators */
token *tAssignOp( void ) { return tokenNewWithAttributes((unsigned int)'=', "=", NULL, NULL); }
token *tDotOp( void ) { return tokenNewWithAttributes((unsigned int)'.', ".", NULL, NULL); }

/* braces/parentheses */
token *tCurlyL( void ) { return tokenNewWithAttributes((unsigned int)'{', "{", NULL, NULL); }
token *tCurlyR( void ) { return tokenNewWithAttributes((unsigned int)'}', "}", NULL, NULL); }
token *tSquareL( void ) { return tokenNewWithAttributes((unsigned int)'[', "[", NULL, NULL); }
token *tSquareR( void ) { return tokenNewWithAttributes((unsigned int)']', "]", NULL, NULL); }
token *tParenL( void ) { return tokenNewWithAttributes((unsigned int)'(', "(", NULL, NULL); }
token *tParenR( void ) { return tokenNewWithAttributes((unsigned int)')', ")", NULL, NULL); }

/* punctuation marks */
token *tComma( void ) { return tokenNewWithAttributes((unsigned int)',', ",", NULL, NULL); }
token *tColon( void ) { return tokenNewWithAttributes((unsigned int)':', ":", NULL, NULL); }
token *tSemi( void ) { return tokenNewWithAttributes((unsigned int)';', ";", NULL, NULL); }
token *tQuest( void ) { return tokenNewWithAttributes((unsigned int)'?', "?", NULL, NULL); }

/* built in types */
token *tChar( void ) { return tokenNewWithAttributes(CHAR, "char", NULL, NULL); }
token *tShort( void ) { return tokenNewWithAttributes(SHORT, "short", NULL, NULL); }
token *tInt( void ) { return tokenNewWithAttributes(INT, "int", NULL, NULL); }
token *tLong( void ) { return tokenNewWithAttributes(LONG, "long", NULL, NULL); }
token *tSigned( void ) { return tokenNewWithAttributes(SIGNED, "signed", NULL, NULL); }
token *tUnsigned( void ) { return tokenNewWithAttributes(UNSIGNED, "unsigned", NULL, NULL); }
token *tFloat( void ) { return tokenNewWithAttributes(FLOAT, "float", NULL, NULL); }
token *tDouble( void ) { return tokenNewWithAttributes(DOUBLE, "double", NULL, NULL); }
token *tConst( void ) { return tokenNewWithAttributes(CONST, "const", NULL, NULL); }
token *tVolatile( void ) { return tokenNewWithAttributes(VOLATILE, "volatile", NULL, NULL); }
token *tVoid( void ) { return tokenNewWithAttributes(VOID, "void", NULL, NULL); }

/* reserved words */
token *tExtern( void ) { return tokenNewWithAttributes(EXTERN, "extern", NULL, NULL); }
token *tStatic( void ) { return tokenNewWithAttributes(STATIC, "static", NULL, NULL); }
token *tAuto( void ) { return tokenNewWithAttributes(AUTO, "auto", NULL, NULL); }
token *tRegister( void ) { return tokenNewWithAttributes(REGISTER, "register", NULL, NULL); }

token *tSizeof( void ) { return tokenNewWithAttributes(SIZEOF, "sizeof", NULL, NULL); }

/* user defined type creation */
token *tTypedef( void ) { return tokenNewWithAttributes(TYPEDEF, "typedef", NULL, NULL); }
token *tStruct( void ) { return tokenNewWithAttributes(STRUCT, "struct", NULL, NULL); }
token *tUnion( void ) { return tokenNewWithAttributes(UNION, "union", NULL, NULL); }
token *tEnum( void ) { return tokenNewWithAttributes(ENUM, "enum", NULL, NULL); }

token *tEllipsis( void ) { return tokenNewWithAttributes(ELLIPSIS, "...", NULL, NULL); }

/* control flow */
token *tIf( void ) { return tokenNewWithAttributes(IF, "if", NULL, NULL); }
token *tElse( void ) { return tokenNewWithAttributes(ELSE, "else", NULL, NULL); }
token *tSwitch( void ) { return tokenNewWithAttributes(SWITCH, "switch", NULL, NULL); }
token *tCase( void ) { return tokenNewWithAttributes(CASE, "case", NULL, NULL); }
token *tDefault( void ) { return tokenNewWithAttributes(DEFAULT, "default", NULL, NULL); }
token *tWhile( void ) { return tokenNewWithAttributes(WHILE, "while", NULL, NULL); }
token *tDo( void ) { return tokenNewWithAttributes(DO, "do", NULL, NULL); }
token *tFor( void ) { return tokenNewWithAttributes(FOR, "for", NULL, NULL); }
token *tGoto( void ) { return tokenNewWithAttributes(GOTO, "goto", NULL, NULL); }
token *tContinue( void ) { return tokenNewWithAttributes(CONTINUE, "continue", NULL, NULL); }
token *tBreak( void ) { return tokenNewWithAttributes(BREAK, "break", NULL, NULL); }
token *tReturn( void ) { return tokenNewWithAttributes(RETURN, "return", NULL, NULL); }

/* comments */
token *tBlockComment( void ) { return NULL; }
token *tInLineComment( void ) { return NULL; }

extern token *tConstant( char *text ) { return tokenNewWithAttributes(CONSTANT, text, NULL, NULL); } // FIXME: when to determine the value?
extern token *tStringLiteral( char *text ) { return tokenNewWithAttributes(STRING_LITERAL, text, NULL, NULL); }


/** objective-c extensions **/
token *tObjCId( void ) { return tokenNewWithAttributes(OBJC_ID, "id", NULL, NULL); }
token *tObjCSelf( void ) { return tokenNewWithAttributes(SELF, "self", NULL, NULL); }
token *tObjCSuper( void ) { return tokenNewWithAttributes(SUPER, "super", NULL, NULL); }
token *tObjCIn( void ) { return tokenNewWithAttributes(IN, "in", NULL, NULL); }
token *tObjCOut( void ) { return tokenNewWithAttributes(OUT, "out", NULL, NULL); }
token *tObjCInout( void ) { return tokenNewWithAttributes(INOUT, "inout", NULL, NULL); }
token *tObjCBycopy( void ) { return tokenNewWithAttributes(BYCOPY, "bycopy", NULL, NULL); }
token *tObjCByref( void ) { return tokenNewWithAttributes(BYREF, "byref", NULL, NULL); }
token *tObjCOneway( void ) { return tokenNewWithAttributes(ONEWAY, "oneway", NULL, NULL); }

token *tObjCAtClass( void ) { return tokenNewWithAttributes(AT_CLASS, "@class", NULL, NULL); }
token *tObjCAtProtocol( void ) { return tokenNewWithAttributes(AT_PROTOCOL, "@protocol", NULL, NULL); }
token *tObjCAtInterface( void ) { return tokenNewWithAttributes(AT_INTERFACE, "@interface", NULL, NULL); }
token *tObjCAtImplementation( void ) { return tokenNewWithAttributes(AT_IMPLEMENTATION, "@implementation", NULL, NULL); }
token *tObjCAtEnd( void ) { return tokenNewWithAttributes(AT_END, "@end", NULL, NULL); }

token *tObjCAtPrivate( void ) { return tokenNewWithAttributes(AT_PRIVATE, "@private", NULL, NULL); }
token *tObjCAtPublic( void ) { return tokenNewWithAttributes(AT_PUBLIC, "@public", NULL, NULL); }
token *tObjCAtProtected( void ) { return tokenNewWithAttributes(AT_PROTECTED, "@protected", NULL, NULL); }

token *tObjCAtTry( void ) { return tokenNewWithAttributes(AT_TRY, "@try", NULL, NULL); }
token *tObjCAtCatch( void ) { return tokenNewWithAttributes(AT_CATCH, "@catch", NULL, NULL); }
token *tObjCAtFinally( void ) { return tokenNewWithAttributes(AT_FINALLY, "@finally", NULL, NULL); }
token *tObjCThrow( void ) { return tokenNewWithAttributes(AT_THROW, "@throw", NULL, NULL); }

token *tObjCAtDefs( void ) { return tokenNewWithAttributes(AT_DEFS, "@defs", NULL, NULL); }
token *tObjCAtSynchronized( void ) { return tokenNewWithAttributes(AT_SYNCHRONIZED, "@synchronized", NULL, NULL); }
token *tObjCAtSelector( void ) { return tokenNewWithAttributes(AT_SELECTOR, "@selector", NULL, NULL); }
token *tObjCAtEncode( void ) { return tokenNewWithAttributes(AT_ENCODE, "@encode", NULL, NULL); }

token *tObjCString( char *tokenString ) { return tokenNewWithAttributes(OBJC_STRING_LITERAL, tokenString, NULL, NULL); }


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
