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


token *tokenCopy( token *original ) {

	token *result = tokenNew();

	result->type = original->type;
	result->text = strncpy(result->text, original->text, strlen(original->text));
	result->value = original->value; // FIXME: this will only work when copying from a stack object
	result->first = original->first;
	result->next = original->next;
	
	return result;
}

token *tokenNextSibling( token *aToken ) {
	return aToken->first;
}

token *tokenSetNextSibling( token *aToken, token *next ) {
	
	if(NULL != aToken->next)
		tokenRelease(aToken->next);
	
	aToken->next = next;
	return aToken;
}

token *tokenFirstChild( token *aToken ) {
	return aToken->next;
}

token *tokenSetFirstChild( token *aToken, token *first ) {
	
	if(NULL != aToken->first)
		tokenRelease(aToken->first);
	
	aToken->first = first;
	return aToken;
}

token *tokenListAppend( token *head, token *last ) {
	token *oldLast = head->next;
	while (NULL != oldLast->next)
		oldLast = oldLast->next;
	oldLast->next = last;
	return head;
}

void failWithError(const char *message) {
	// FIXME: implement
}

/** specialized token creation functions for terminal symbols **/

/* multi-character operators */
token *tPtrOp( void ) { return tokenNewWithAttributes(PTR_OP, "->", NULL, NULL); }

token *tIncOp( void ) { return tokenNewWithAttributes(INC_OP, "++", NULL, NULL); }
token *tDecOp( void ) { return tokenNewWithAttributes(DEC_OP, "--", NULL, NULL); }

token *tBooleanAndOp( void ) { return tokenNewWithAttributes(AND_OP, "&&", NULL, NULL); }
token *tBooleanOrOp( void ) { return tokenNewWithAttributes(OR_OP, "||", NULL, NULL); }
token *tEqualToOp( void ) { return tokenNewWithAttributes(EQ_OP, "==", NULL, NULL); }
token *tLessOrEqualOp( void ) { return tokenNewWithAttributes(LE_OP, "<=", NULL, NULL); }
token *tGreaterOrEqualOp( void ) { return tokenNewWithAttributes(GE_OP, ">=", NULL, NULL); }
token *tNotEqualToOp( void ) { return tokenNewWithAttributes(NE_OP, "!=", NULL, NULL); }

token *tShiftLOp( void ) { return tokenNewWithAttributes(LEFT_OP, "<<", NULL, NULL); }
token *tShiftROp( void ) { return tokenNewWithAttributes(RIGHT_OP, ">>", NULL, NULL); }

token *tMulAssignOp( void ) { return tokenNewWithAttributes(MUL_ASSIGN, "*=", NULL, NULL); }
token *tDivAssignOp( void ) { return tokenNewWithAttributes(DIV_ASSIGN, "/=", NULL, NULL); }
token *tModAssignOp( void ) { return tokenNewWithAttributes(MOD_ASSIGN, "%=", NULL, NULL); }
token *tAddAssignOp( void ) { return tokenNewWithAttributes(ADD_ASSIGN, "+=", NULL, NULL); }
token *tSubAssignOp( void ) { return tokenNewWithAttributes(SUB_ASSIGN, "-=", NULL, NULL); }

token *tLeftAssignOp( void ) { return tokenNewWithAttributes(LEFT_ASSIGN, "<<=", NULL, NULL); }
token *tRightAssignOp( void ) { return tokenNewWithAttributes(RIGHT_ASSIGN, ">>=", NULL, NULL); }
token *tAndAssignOp( void ) { return tokenNewWithAttributes(AND_ASSIGN, "&=", NULL, NULL); }
token *tXorAssignOp( void ) { return tokenNewWithAttributes(XOR_ASSIGN, "^=", NULL, NULL); }
token *tOrAssignOp( void ) { return tokenNewWithAttributes(OR_ASSIGN, "|=", NULL, NULL); }

/* multi-purpose operators */
token *tStarOp( void ) { return tokenNewWithAttributes((unsigned int)'*', "*", NULL, NULL); }
token *tAmpOp( void ) { return tokenNewWithAttributes((unsigned int)'&', "&", NULL, NULL); }
token *tExclaimOp( void ) { return tokenNewWithAttributes((unsigned int)'!', "!", NULL, NULL); }
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
token *tXorOp( void ) { return tokenNewWithAttributes((unsigned int)'^', "^", NULL, NULL); }
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
token *tBlockComment( void ) {
	return NULL;
}
token *tInLineComment( void ) {
	return NULL;
}


/* literals */
token *tConstant( char *text ) { return tokenNewWithAttributes(CONSTANT, text, NULL, NULL); } // FIXME: when to determine the value?
token *tStringLiteral( char *text ) { return tokenNewWithAttributes(STRING_LITERAL, text, NULL, NULL); }


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
token *gList( token *first ) {
	return tokenNewWithAttributes(LIST, NULL, NULL, first);
}



token *gTranslationUnit( token *externalDef ) {
	
	// FIXME: create symbol scope table tree
	
	return tokenNewWithAttributes(TRANSLATION_UNIT, NULL, NULL, externalDef);
}

token *gDec( token *decSpecs, token *initDeclarators ) {
	if(NULL != initDeclarators)
		tokenSetNextSibling(decSpecs,
							tokenSetNextSibling(gList(initDeclarators), tSemi()) );
	return tokenNewWithAttributes(DECLARATION, NULL, NULL, decSpecs);
}

token *gInitDeclarator( token *typeDeclarator, token *initializer ) {
	if(NULL != initializer) {
		tokenSetNextSibling(typeDeclarator, tokenSetNextSibling(tAssignOp(), initializer));
	}
	return tokenNewWithAttributes(INIT_DECLARATOR, NULL, NULL, typeDeclarator);
}


/* functions */
token *gFunctionDef (token *decSpecs, token *typeDec, token *body ) {

	// verify that typeDec is correct
	// 1. ensure its first child is an identifier
	token *functionName = typeDec->first;
	if(! IDENTIFIER == functionName->type)
		failWithError("Function signature ill-defined: no name");
	// 2. ensure its second child is a list declarator
	token *listDeclarator = functionName->next;
	if(! LIST_DECLARATOR == listDeclarator->type)
		failWithError("Function signature ill-defined: no parameter list");
	
	// FIXME: Add functionName->text to current symbol scope

	tokenSetNextSibling(typeDec, body);
	
	if(NULL != decSpecs) {
		token *decSpecList = tokenSetNextSibling(gList(decSpecs), typeDec);
		return tokenNewWithAttributes(FUNCTION_DEF, NULL, NULL, decSpecList);
	}
	return tokenNewWithAttributes(FUNCTION_DEF, NULL, NULL, typeDec);
}

token *gFunctionBody ( token *decs, token *compoundStatement ) {
	if(NULL != decs) {
		token *decList = tokenSetNextSibling(gList(decs), compoundStatement);
		return tokenNewWithAttributes(FUNCTION_BODY, NULL, NULL, decList);
	}
	return tokenNewWithAttributes(FUNCTION_BODY, NULL, NULL, compoundStatement);
}


/* type specifiers */
token *gStructOrUnionSpec( token *structOrUnion, token *name, token *structDecs ) {
	
	unsigned int type;
	
	if(STRUCT == structOrUnion->type)
		type = STRUCT_SPEC;
	else
		type = UNION_SPEC;
	
	token *structBody = NULL;
	
	if(NULL != structDecs) {
		structBody =  tokenSetNextSibling(tCurlyL(),
										  tokenSetNextSibling(gList(structDecs), tCurlyR()));
	}
	
	if(NULL != name) {
		
		// FIXME: add name and details to current type scope
		
		if(NULL != structBody) {
			tokenSetNextSibling(name, structBody);
		}
		return tokenNewWithAttributes(type, NULL, NULL, name);
	}	

	return tokenNewWithAttributes(type, NULL, NULL, structBody);	
}

token *gEnumSpec( token *name, token *enumerators ) {

	token *enumeratorList = NULL;
	
	if(NULL != enumerators) {

		// FIXME: add enumerators and their values to local symbol scope

		enumeratorList = gList(enumerators);
	}
	if(NULL == name) {
		return tokenNewWithAttributes(ENUM_SPEC, NULL, NULL, enumeratorList);
	}
	
	// FIXME: add name to local symbol scope
	
	if(NULL != enumeratorList)
		tokenSetNextSibling(name, enumeratorList);
	
	return tokenNewWithAttributes(ENUM_SPEC, NULL, NULL, name);
}

/* structure/union elements */
token *gStructDec( token *specQuals, token *declarators ) {
	
	// FIXME: push new symbol scope

	// FIXME: add declarators to current symbol scope
	
	token *specQualList = gList(specQuals);

	tokenSetNextSibling(specQualList,
						tokenSetNextSibling(gList(declarators), tSemi()));
	
	return tokenNewWithAttributes(STRUCT_DEC, NULL, NULL, specQualList);
}

token *gStructDeclarator( token *typeDeclarator, token *initValue ) {
	if(NULL != typeDeclarator) {
		tokenSetNextSibling(typeDeclarator, initValue);
		return tokenNewWithAttributes(STRUCT_DECLARATOR, NULL, NULL, typeDeclarator);
	}
	return tokenNewWithAttributes(STRUCT_DECLARATOR, NULL, NULL, initValue);
}

/* enumeration elements */
token *gEnumerator( token *name, token *initValue ) {
	if(NULL != initValue)
		tokenSetNextSibling(name, initValue);
	tokenListAppend(name, tParenR());
	return tokenNewWithAttributes(ENUMERATOR, NULL, NULL, tokenSetNextSibling(tParenL(), name));
}

/* type declarations */
token *gTypeDeclarator( token *pointer, token *declarators ) {
	
	token *directDeclarator = declarators;
	while(LIST == directDeclarator->type) {
		directDeclarator = directDeclarator->first;
	}
	
	token *list = gList(declarators);
	if(NULL != pointer) {
		tokenListAppend(pointer, list);
		return tokenNewWithAttributes(TYPE_DECLARATOR, NULL, NULL, pointer);
	}
	return tokenNewWithAttributes(TYPE_DECLARATOR, NULL, NULL, list);
}

token *gArrayDeclarator( token *length ) {
	tokenSetNextSibling(length, tSquareR());
	return tokenNewWithAttributes(ARRAY_DECLARATOR, NULL, NULL, tokenSetNextSibling(tSquareL(), length));
}

token *gListDeclarator( token *parameters ) {
	token *list = gList(parameters);
	tokenListAppend(list, tParenR());
	return tokenNewWithAttributes(LIST_DECLARATOR, NULL, NULL, tokenListAppend(tParenL(), list));
}

token *gParameterDec( token *specs, token *declarator ) {
	token *list = gList(specs);
	if(NULL != declarator)
		tokenSetNextSibling(list, declarator);
	return tokenNewWithAttributes(PARAMETER_DEC, NULL, NULL, list);
}

token *gPointer( token *elements ) {
	return gList(elements);
}

token *gStructInitializer( token *assignmentExpr ) {
	tokenListAppend(assignmentExpr, tCurlyR());
	return tokenNewWithAttributes(STRUCT_INIT, NULL, NULL, tokenListAppend(tCurlyL(), assignmentExpr));
}


/** Objective-C **/

/* external definitions */
token *gClassNameDecs( token *identifiers ) {
	// FIXME: Add identifiers to local scope
	token *nameList = gList(identifiers);
	return tokenNewWithAttributes(CLASS_NAMES, NULL, NULL, tokenSetNextSibling(nameList, tSemi()));
}
token *gProtocolNameDecs( token *identifiers ) {
	// FIXME: Add identifiers to local scope
	token *nameList = gList(identifiers);
	return tokenNewWithAttributes(PROTOCOL_NAMES, NULL, NULL, tokenSetNextSibling(nameList, tSemi()));
}

token *gProtocolRefs( token *identifiers ) {
	token *children = tokenSetNextSibling(tLessOp(),
										  tokenSetNextSibling(identifiers, tGreaterOp()));
	return tokenNewWithAttributes(PROTOCOL_REFS, NULL, NULL, children);
}

token *gInstanceVariables( token *members ) {
	token *children = tokenSetNextSibling(tCurlyL(),
										  tokenSetNextSibling(members, 
															  tCurlyR()));
	return tokenNewWithAttributes(CLASS_IVARS, NULL, NULL, children);
}

token *gClassInterface( token *className, token *superClassName, token *protocolRefs, token *ivars, token *interfaceDecs ) {

	token *interface = tokenSetNextSibling(tObjCAtInterface(), className);
	
	if(NULL != superClassName) {
		tokenSetNextSibling(className, 
							tokenSetNextSibling(tColon(), superClassName));
	}
	
	if(NULL != protocolRefs) {
		token *protocolRefList = gList(protocolRefs);
		protocolRefList = tokenSetNextSibling(tLessOp(),
											  tokenSetNextSibling(protocolRefList, tGreaterOp()));
		tokenListAppend(className, protocolRefList);
	}
	
	if(NULL != ivars) {
		token *ivarList = gList(ivars);
		ivarList = tokenSetNextSibling(tCurlyL(),
									   tokenSetNextSibling(ivarList, tCurlyR()));
		tokenListAppend(className, ivarList);
	}
	
	if(NULL != interfaceDecs) {
		token *interfaceList = gList(interfaceDecs);
		tokenListAppend(className, interfaceList);
	}
	
	tokenListAppend(className, tObjCAtEnd());
	
	return tokenNewWithAttributes(CLASS_INTERFACE, NULL, NULL, interface);
}

token *gCategoryInterface( token *className, token *categoryName, token *protocolRefs, token *interfaceDecs ) {
	
	// FIXME: push categoryName into current context
	
	token *interface = tokenSetNextSibling(tObjCAtInterface(),
										   tokenSetNextSibling(tParenL(),
															   tokenSetNextSibling(className, tParenR())));
	
	token *interfaceDecList = gList(interfaceDecs);
	
	tokenListAppend(className, categoryName);
	if(NULL != protocolRefs) {
		token *protocolRefList = gList(protocolRefs);
		tokenListAppend(categoryName, protocolRefList);
		tokenSetNextSibling(protocolRefList, interfaceDecList);
	}
	else {
		tokenSetNextSibling(categoryName,
							tokenSetNextSibling(interfaceDecList, tObjCAtEnd()));
	}
	
	return tokenNewWithAttributes(CATEGORY_INTERFACE, NULL, NULL, interface);
}

token *gProtocolDec( token *protocolName, token *protocolRefs, token *interfaceDecs ) {

	token *protocolRefList = gList(protocolRefs);
	token *interfaceDecList = gList(interfaceDecs);
	
	token *children = tokenSetNextSibling(tObjCAtProtocol(), 
										  tokenSetNextSibling(protocolName, 
															  tokenSetNextSibling(protocolRefList, 
																				  tokenSetNextSibling(interfaceDecList, tObjCAtEnd()))));
	return tokenNewWithAttributes(PROTOCOL_INTERFACE, NULL, NULL, children);
}

token *gClassImplementation(token *className, token *methodDefs ) {
	
	if(NULL != methodDefs)
		tokenSetNextSibling(className, 
							gList(methodDefs));
	
	token *children = tokenSetNextSibling(tObjCAtImplementation(), 
										  tokenListAppend(className, tObjCAtEnd()));
	
	return tokenNewWithAttributes(CLASS_IMP, NULL, NULL, children);
}

token *gCategoryImplementation( token *className, token *categoryName, token *methodDefs ) {
	
	token *children = tokenSetNextSibling(tObjCAtImplementation(), 
										  tokenSetNextSibling(className, 
															  tokenSetNextSibling(categoryName, 
																				  tokenSetNextSibling(gList(methodDefs), tObjCAtEnd()))));
	return tokenNewWithAttributes(CATEGORY_IMP, NULL, NULL, children);
}

token *methodDecShared( token *returnType, token *selector ) {
	if(NULL != returnType) {
		returnType = tokenSetNextSibling(tParenL(), 
										 tokenSetNextSibling(returnType,
															 tokenSetNextSibling(tParenR(), selector)));
		return tokenNewWithAttributes(CLASS_IMP, NULL, NULL, returnType);
	}
	
	return tokenNewWithAttributes(CLASS_IMP, NULL, NULL, selector);
}

token *gClassMethodDec( token *returnType, token *selector ) {
	return tokenSetNextSibling(tAddOp(), methodDecShared(returnType, selector));
}

token *gInstanceMethodDec( token *returnType, token *selector ) {
	return tokenSetNextSibling(tSubOp(), methodDecShared(returnType, selector));
}

token *methodDefShared( token *returnType, token *selector, token *decs, token *compoundStmt ) {
	
	token *firstHalf = NULL;
	token *secondHalf = NULL;
	
	if(NULL != returnType) {
		firstHalf = tokenSetNextSibling(tParenL(), 
										tokenSetNextSibling(returnType,
															tokenSetNextSibling(tParenR(), selector)));
	}
	else {
		firstHalf = selector;
	}
	
	if(NULL != decs) {
		secondHalf = tokenSetNextSibling(gList(decs), compoundStmt);
	}
	else {
		secondHalf = compoundStmt;
	}
	
	return tokenNewWithAttributes(CLASS_IMP, NULL, NULL, tokenSetNextSibling(firstHalf, secondHalf));
}

token *gClassMethodDef( token *returnType, token *selector, token *decs, token *compoundStmt ) {
	return tokenSetNextSibling(tAddOp(), methodDefShared(returnType, selector, decs, compoundStmt));
}

token *gInstanceMethodDef( token *returnType, token *selector, token *decs, token *compoundStmt ) {
	return tokenSetNextSibling(tSubOp(), methodDefShared(returnType, selector, decs, compoundStmt));
}

/* type specifiers */
token *gTypeSpec( token *typeSpec, token *protocolRefs ) {
	return tokenNewWithAttributes(TYPE_SPEC, NULL, NULL, tokenSetNextSibling(typeSpec, protocolRefs));
}

token *gStructObjCDefs( token *className ) {
	
	// FIXME: check for classname in current scope
	
	token *at_defs = tokenSetNextSibling(tObjCAtDefs(), tokenSetNextSibling(tParenL(), tokenSetNextSibling(className, tParenR())));
	return tokenNewWithAttributes(STRUCT_OBJC_DEFS, NULL, NULL, at_defs);
}


#pragma mark Statements
/** Statements **/
token *gCompound( token *stmtsAndDecs ) {
	token *children = tokenSetNextSibling(tParenL(), tokenSetNextSibling(stmtsAndDecs, tParenR()));
	return tokenNewWithAttributes(STMT_COMPOUND, NULL, NULL, children);
}

token *gIf( token *test, token *trueStmt ) {
	token *testList = tokenSetNextSibling(tParenL(),
										  tokenSetNextSibling(test,
															  tokenSetNextSibling(tParenR(), trueStmt)));
	token *children = tokenSetNextSibling(tIf(), testList);
	return tokenNewWithAttributes(STMT_IF, NULL, NULL, children);
}

token *gIfElse( token *test, token *trueStmt, token *falseStmt ) {
	token *trueAndFalse = tokenSetNextSibling(trueStmt, 
											  tokenSetNextSibling(tElse(),
																  falseStmt));
	token *testList = tokenSetNextSibling(tParenL(),
										  tokenSetNextSibling(test,
															  tokenSetNextSibling(tParenR(),
																				  trueAndFalse)));
	token *children = tokenSetNextSibling(tIf(), testList);
	return tokenNewWithAttributes(STMT_IF, NULL, NULL, children);
}

token *gWhile( token *test, token *stmt ) {
	return NULL;
}

token *gFor( token *init, token *test, token *inc, token *stmt ) {
	return NULL;
}

token *gDo( token *stmt, token *test) {
	return NULL;
}

token *gSwitch( token *test, token *compoundStmt ) {
	return NULL;
}

token *gGoto( token *identifier ) {
	return NULL;
}

token *gReturn( token *expr ) {
	return NULL;
}

token *gLabeled( token *identifier, token *stmt ) {
	return NULL;
}

token *gCase( token *constant, token *stmt ) {
	return NULL;
}

token *gDefault( token *stmt ) {
	return NULL;
}

token *gExpression( token *expr ) {
	tokenSetNextSibling(expr, tSemi());
	return tokenNewWithAttributes(STMT_EXPRESSION, NULL, NULL, expr);
}


/* objc */
token *gTry( token *tryBlock, token *catchInitDecl, token *catchBlock, token *finBlock ) {
	return NULL;
}

token *gSynch( token *identifier, token *stmt ) {
	return NULL;
}

token *gThrow( token *identifier ) {
	return NULL;
}



#pragma mark Expressions
/** Expressions **/
token *gPostfix( token *expr, token *op, token *member ) {
	if(NULL != member)
		tokenSetNextSibling(op, member);
	tokenSetNextSibling(expr, op);
	return tokenNewWithAttributes(EXPR_POSTFIX, NULL, NULL, expr);
}

token *gPrefix( token *op, token *expr) {
	tokenSetNextSibling(op, expr);
	return tokenNewWithAttributes(EXPR_PREFIX, NULL, NULL, op);
}


token *gArray( token *expr ) {
	return tokenSetNextSibling(tParenL(), tokenSetNextSibling(expr, tParenR()));
}

token *gParen( token *expr ) {
	return tokenSetNextSibling(tSquareL(), tokenSetNextSibling(expr, tSquareR()));
}

token *gDot( token *expr, token *ident ) {
	return tokenSetNextSibling(expr, tokenSetNextSibling(tDotOp(), ident));
}

token *gBinary( token *left, token *op, token *right) {
	tokenSetNextSibling(left, tokenSetNextSibling(op, right));
	return tokenNewWithAttributes(EXPR_BINARY, NULL, NULL, left);
}

token *gCast( token *typeSpec, token *expr ) {
	typeSpec = tokenSetNextSibling(tParenL(), tokenSetNextSibling(typeSpec, tParenR()));
	return tokenNewWithAttributes(EXPR_CAST, NULL, NULL, typeSpec);
}

token *gAssign( token *left, token *op, token *right ) {
	token *children = tokenSetNextSibling(left, tokenSetNextSibling(op, right));
	return tokenNewWithAttributes(EXPR_ASSIGN, NULL, NULL, children);
}

token *gConditional( token *logical, token *trueExpr, token *falseExpr ) {
	
	token *children = tColon();
	
	if(NULL != falseExpr)
		tokenSetNextSibling(children, falseExpr);
	if(NULL != trueExpr)
		children = tokenSetNextSibling(trueExpr, children);
	
	children = tokenSetNextSibling(tQuest(), children);
	
	tokenSetNextSibling(logical, children);
	
	return tokenNewWithAttributes(EXRP_CONDITIONAL, NULL, NULL, children);
}

token *gSizeofUnary( token *unary ) {
	return tokenSetNextSibling(tSizeof(), unary);
}

token *gSizeofType( token *typeSpec ) {
	return tokenSetNextSibling(tSizeof(), gParen(typeSpec));
}


/* objc */
token *gMessage( token *receiver, token *message ) {
	token *children = tokenSetNextSibling(tSquareL(), 
										  tokenSetNextSibling(receiver,
															  tokenSetNextSibling(message,
																				  tSquareR())));
	return tokenNewWithAttributes(EXPR_MESSAGE, NULL, NULL, children);
}

token *gAtSelector( token *name ) {
	return tokenNewWithAttributes(EXPR_AT_SELECTOR, NULL, NULL, gList(name));
}

token *gSelector( token *keysWordsAndArgs ) {
	return tokenNewWithAttributes(EXPR_SELECTOR, NULL, NULL, keysWordsAndArgs);
}

token *gSelectorKeyword( token *identifier ) {
	if(NULL != identifier)
		return tokenSetNextSibling(identifier, tColon());
	else
		return tColon();
}

token *gAtProtocol( token *identifier ) {
	token *children = tokenSetNextSibling(tObjCAtProtocol(),
										  tokenSetNextSibling(tParenL(),
															  tokenSetNextSibling(identifier,
																				  tParenR())));
	return tokenNewWithAttributes(EXPR_AT_PROTOCOL, NULL, NULL, children);
}

token *gAtEncode( token *typeName ) {
	
	// FIXME: check typeName
	token *children = tokenSetNextSibling(tObjCAtEncode(),
										  tokenSetNextSibling(tParenL(),
															  tokenSetNextSibling(typeName,
																				  tParenR())));
	return tokenNewWithAttributes(EXPR_AT_ENCODE, NULL, NULL, children);
}



