//
//  PaParser.m
//  Parce
//
//  Created by Brent Gulanowski on 02/12/07.

/*
 
 Copyright 2007 Brent Gulanowski.
 
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


#import "PaParser.h"

#import "PaToken.h"

#import "parce_parser_actions.h"



/** Public Symbol Definitions **/


/** Private Symbol Definitions **/
//#pragma mark -
//#pragma mark File Statics

/* Private Category Declaration */
//@interface PaParser (PaParser_private)
//@end


@implementation PaParser


//#pragma mark property directives
 

/** inheritance tree overrides **/

//#pragma mark NSObject

//+(void)initialize {
//}



//-(id)init {
//	
//	self = [super init];
//	
//	if(self) {
//		// initiliase me
//	}
//	
//	return self;
//}

//- (void)dealloc {
//}


/** formal protocol implementations **/
//#pragma mark -
//#pragma mark NSCoding
//#pragma mark NSCopying


/** informal protocol implementations **/
//#pragma mark -
//#pragma mark NSNibAwakening


/** Accessor Methods **/
//#pragma mark -
//#pragma mark Standard Accessors
//#pragma mark Synthetic Accessors


/** Private Operations **/
//#pragma mark -
//#pragma mark PaParser_private


/** Public Operations (Group by Type) **/
//#pragma mark -
//#pragma mark Actions

@end


/* All the functions from parce_parser_actions.h */
#pragma mark PaToken management
PaToken *tokenNextSibling( PaToken *aToken ) { return NULL; }
PaToken *tokenFirstChild( PaToken *aToken ) { return NULL; }

PaToken *tokenSetNextSibling( PaToken *aToken, PaToken *next ) { return NULL; }
PaToken *tokenSetFirstChild( PaToken *aToken, PaToken *first ) { return NULL; }

PaToken *tokenCopy( PaToken *original ) { return NULL; }
PaToken *tokenListAppend( PaToken *list, PaToken *last ) { return NULL; }


#pragma mark -
#pragma mark operators
PaToken *tPtrOp( void ) { return NULL; }

PaToken *tIncOp( void ) { return NULL; }
PaToken *tDecOp( void ) { return NULL; }

PaToken *tBooleanAndOp( void ) { return NULL; }
PaToken *tBooleanOrOp( void ) { return NULL; }
PaToken *tEqualToOp( void ) { return NULL; }
PaToken *tLessOrEqualOp( void ) { return NULL; }
PaToken *tGreaterOrEqualOp( void ) { return NULL; }
PaToken *tNotEqualToOp( void ) { return NULL; }

PaToken *tShiftLOp( void ) { return NULL; }
PaToken *tShiftROp( void ) { return NULL; }

PaToken *tMulAssignOp( void ) { return NULL; }
PaToken *tDivAssignOp( void ) { return NULL; }
PaToken *tModAssignOp( void ) { return NULL; }
PaToken *tAddAssignOp( void ) { return NULL; }
PaToken *tSubAssignOp( void ) { return NULL; }

PaToken *tLeftAssignOp( void ) { return NULL; }
PaToken *tRightAssignOp( void ) { return NULL; }
PaToken *tAndAssignOp( void ) { return NULL; }
PaToken *tXorAssignOp( void ) { return NULL; }
PaToken *tOrAssignOp( void ) { return NULL; }

/* multi-purpose operators */
PaToken *tStarOp( void ) { return NULL; }
PaToken *tAmpOp( void ) { return NULL; }
PaToken *tExclaimOp( void ) { return NULL; }
PaToken *tBarOp( void ) { return NULL; }
PaToken *tSubOp( void ) { return NULL; }

/* arithmetic operators */
PaToken *tAddOp( void ) { return NULL; }
PaToken *tDivOp( void ) { return NULL; }
PaToken *tModOp( void ) { return NULL; }

/* boolean operators */
PaToken *tLessOp( void ) { return NULL; }
PaToken *tGreaterOp( void ) { return NULL; }

/* bitwise operators */
PaToken *tXorOp( void ) { return NULL; }
PaToken *tCompOp( void ) { return NULL; }

/* other single character operators */
PaToken *tAssignOp( void ) { return NULL; }
PaToken *tDotOp( void ) { return NULL; }


#pragma mark -
#pragma mark punctuation
/* braces/parentheses */
PaToken *tCurlyL( void ) { return NULL; }
PaToken *tCurlyR( void ) { return NULL; }
PaToken *tSquareL( void ) { return NULL; }
PaToken *tSquareR( void ) { return NULL; }
PaToken *tParenL( void ) { return NULL; }
PaToken *tParenR( void ) { return NULL; }

/* punctuation marks */
PaToken *tComma( void ) { return NULL; }
PaToken *tColon( void ) { return NULL; }
PaToken *tSemi( void ) { return NULL; }
PaToken *tQuest( void ) { return NULL; }

PaToken *tEllipsis( void ) { return NULL; }


#pragma mark -
#pragma mark type names
/* built in types */
PaToken *tChar( void ) { return NULL; }
PaToken *tShort( void ) { return NULL; }
PaToken *tInt( void ) { return NULL; }
PaToken *tLong( void ) { return NULL; }
PaToken *tSigned( void ) { return NULL; }
PaToken *tUnsigned( void ) { return NULL; }
PaToken *tFloat( void ) { return NULL; }
PaToken *tDouble( void ) { return NULL; }
PaToken *tConst( void ) { return NULL; }


#pragma mark type specifiers
PaToken *tVolatile( void ) { return NULL; }
PaToken *tVoid( void ) { return NULL; }
PaToken *tExtern( void ) { return NULL; }
PaToken *tStatic( void ) { return NULL; }
PaToken *tAuto( void ) { return NULL; }
PaToken *tRegister( void ) { return NULL; }

PaToken *tSizeof( void ) { return NULL; }


#pragma mark type definition
PaToken *tTypedef( void ) { return NULL; }
PaToken *tStruct( void ) { return NULL; }
PaToken *tUnion( void ) { return NULL; }
PaToken *tEnum( void ) { return NULL; }


#pragma mark control flow terminals
PaToken *tIf( void ) { return NULL; }
PaToken *tElse( void ) { return NULL; }
PaToken *tSwitch( void ) { return NULL; }
PaToken *tCase( void ) { return NULL; }
PaToken *tDefault( void ) { return NULL; }
PaToken *tWhile( void ) { return NULL; }
PaToken *tDo( void ) { return NULL; }
PaToken *tFor( void ) { return NULL; }
PaToken *tGoto( void ) { return NULL; }
PaToken *tContinue( void ) { return NULL; }
PaToken *tBreak( void ) { return NULL; }
PaToken *tReturn( void ) { return NULL; }


#pragma mark comments
PaToken *tBlockComment( void ) { return NULL; }
PaToken *tInLineComment( void ) { return NULL; }


#pragma mark -
#pragma mark Objective-C
PaToken *tObjCId( void ) { return NULL; }
PaToken *tObjCSelf( void ) { return NULL; }
PaToken *tObjCSuper( void ) { return NULL; }
PaToken *tObjCIn( void ) { return NULL; }
PaToken *tObjCOut( void ) { return NULL; }
PaToken *tObjCInout( void ) { return NULL; }
PaToken *tObjCBycopy( void ) { return NULL; }
PaToken *tObjCByref( void ) { return NULL; }
PaToken *tObjCOneway( void ) { return NULL; }

PaToken *tObjCAtClass( void ) { return NULL; }
PaToken *tObjCAtProtocol( void ) { return NULL; }
PaToken *tObjCAtInterface( void ) { return NULL; }
PaToken *tObjCAtImplementation( void ) { return NULL; }
PaToken *tObjCAtEnd( void ) { return NULL; }

PaToken *tObjCAtPrivate( void ) { return NULL; }
PaToken *tObjCAtPublic( void ) { return NULL; }
PaToken *tObjCAtProtected( void ) { return NULL; }

PaToken *tObjCAtTry( void ) { return NULL; }
PaToken *tObjCAtCatch( void ) { return NULL; }
PaToken *tObjCAtFinally( void ) { return NULL; }
PaToken *tObjCThrow( void ) { return NULL; }

PaToken *tObjCAtDefs( void ) { return NULL; }
PaToken *tObjCAtSynchronized( void ) { return NULL; }
PaToken *tObjCAtSelector( void ) { return NULL; }
PaToken *tObjCAtEncode( void ) { return NULL; }

PaToken *tObjCString( char *tokenText ) { return NULL; }


#pragma mark -
// NON-TERMINAL TOKENS
PaToken *gTranslationUnit( PaToken *externalDef ) { return NULL; }
PaToken *gDec( PaToken *decSpecs, PaToken *initDeclarators ) { return NULL; }

PaToken *gInitDeclarator( PaToken *typeDeclarator, PaToken *initializer ) { return NULL; }


/* functions */
PaToken *gFunctionDef (PaToken *decSpecs, PaToken *typeDec, PaToken *body ) { return NULL; } 
PaToken *gFunctionBody ( PaToken *decs, PaToken *compoundStatement ) { return NULL; } 

/* type specifiers */
PaToken *gStructOrUnionSpec( PaToken *structOrUnion, PaToken *name, PaToken *structDecs ) { return NULL; } 

/* structure/union elements */
PaToken *gStructDec( PaToken *specQuals, PaToken *declarators ) { return NULL; }
PaToken *gStructDeclarator( PaToken *typeDeclarator, PaToken *initValue ) { return NULL; } 

/* enumeration elements */
PaToken *gEnumSpec( PaToken *name, PaToken *enumerators ) { return NULL; } 
PaToken *gEnumerator( PaToken *name, PaToken *initValue ) { return NULL; } 

/* type declarations */
PaToken *gTypeDeclarator( PaToken *pointer, PaToken *declarators ) { return NULL; } 
PaToken *gArrayDeclarator( PaToken *length ) { return NULL; } 
PaToken *gListDeclarator( PaToken *parameters ) { return NULL; } 
PaToken *gParameterDec( PaToken *specs, PaToken *declarator ) { return NULL; } 

PaToken *gStructInitializer( PaToken *assignmentExpr ) { return NULL; }


#pragma mark Expressions and Statements
/** Statements **/
PaToken *gCompound( PaToken *stmtsAndDecs ) { return NULL; }

PaToken *gIf( PaToken *test, PaToken *trueStmt ) { return NULL; }
PaToken *gIfElse( PaToken *test, PaToken *trueStmt, PaToken *falseStmt ) { return NULL; }
PaToken *gWhile( PaToken *test, PaToken *stmt ) { return NULL; }
PaToken *gFor( PaToken *init, PaToken *test, PaToken *inc, PaToken *stmt ) { return NULL; }
PaToken *gDo( PaToken *stmt, PaToken *test) { return NULL; }
PaToken *gSwitch( PaToken *test, PaToken *compoundStmt ) { return NULL; }
PaToken *gGoto( PaToken *identifier ) { return NULL; }
PaToken *gReturn( PaToken *expr ) { return NULL; }
PaToken *gLabeled( PaToken *identifier, PaToken *stmt ) { return NULL; }
PaToken *gCase( PaToken *constant, PaToken *stmt ) { return NULL; }
PaToken *gDefault( PaToken *stmt ) { return NULL; }
PaToken *gExpression( PaToken *expr ) { return NULL; }

/* objc */
PaToken *gTry( PaToken *tryBlock, PaToken *catchInitDecl, PaToken *catchBlock, PaToken *finBlock ) { return NULL; }
PaToken *gSynch( PaToken *identifier, PaToken *stmt ) { return NULL; }
PaToken *gThrow() { return NULL; }

/** Expressions **/
PaToken *gPostfix( PaToken *expr, PaToken *op, PaToken *member ) { return NULL; } // member may be NULL
PaToken *gPrefix( PaToken *op, PaToken *expr) { return NULL; }
PaToken *gArray( PaToken *expr ) { return NULL; }
PaToken *gParen( PaToken *expr ) { return NULL; }
PaToken *gDot( PaToken *expr, PaToken *ident ) { return NULL; }
PaToken *gBinary( PaToken *left, PaToken *op, PaToken *right) { return NULL; }
PaToken *gCast( PaToken *typeSpec, PaToken *expr ) { return NULL; }
PaToken *gAssign( PaToken *left, PaToken *op, PaToken *right ) { return NULL; }
PaToken *gConditional( PaToken *logical, PaToken *trueExpr, PaToken *falseExpr ) { return NULL; }

PaToken *gSizeofUnary( PaToken *unary ) { return NULL; }
PaToken *gSizeofType( PaToken *typeSpec ) { return NULL; }

#pragma mark -
#pragma mark Objective-C groups

/* expressions */
PaToken *gMessage( token *receiver, token *message ) { return NULL; }
PaToken *gAtSelector( token *name ) { return NULL; }
PaToken *gSelector( token *keysWordsAndArgs ) { return NULL; }
PaToken *gSelectorKeyword( PaToken *identifier ) { return NULL; }
PaToken *gAtProtocol( PaToken *identifier ) { return NULL; }
PaToken *gAtEncode( PaToken *typeName ) { return NULL; }


/* external definitions */
PaToken *gClassNameDecs( PaToken *identifiers ) { return NULL; }
PaToken *gProtocolNameDecs( PaToken *identifiers ) { return NULL; }

PaToken *gProtocolRefs( PaToken *identifiers ) { return NULL; }
PaToken *gInstanceVariables( PaToken *members ) { return NULL; }

PaToken *gClassInterface( PaToken *className, PaToken *superClassName, PaToken *protocolRefs, PaToken *ivars, PaToken *interfaceDecs ) { return NULL; }
PaToken *gCategoryInterface( PaToken *className, PaToken *categoryName, PaToken *protocolRefs, PaToken *interfaceDecs ) { return NULL; }
PaToken *gProtocolDec( PaToken *protocolName, PaToken *protocolRefs, PaToken *interfaceDecs ) { return NULL; }

PaToken *gClassImplementation(PaToken *className, PaToken *methodDefs ) { return NULL; }
PaToken *gCategoryImplementation( PaToken *className, PaToken *categoryName, PaToken *methodDefs ) { return NULL; }

PaToken *gClassMethodDec( PaToken *returnType, PaToken *selector ) { return NULL; }
PaToken *gInstanceMethodDec( PaToken *returnType, PaToken *selector ) { return NULL; }

PaToken *gClassMethodDef( PaToken *returnType, PaToken *selector, PaToken *decs, PaToken *compoundStmt ) { return NULL; }
PaToken *gInstanceMethodDef( PaToken *returnType, PaToken *selector, PaToken *decs, PaToken *compoundStmt ) { return NULL; }

/* type specifiers */
PaToken *gTypeSpec( PaToken *typeSpec, PaToken *protocolRefs ) { return NULL; } 

PaToken *gStructObjCDefs( PaToken *className ) { return NULL; }


