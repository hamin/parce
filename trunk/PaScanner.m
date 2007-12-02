//
//  PaScanner.m
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


#import "PaScanner.h"

#import "parce_scanner_actions.h"


/** Public Symbol Definitions **/


/** Private Symbol Definitions **/
//#pragma mark -
//#pragma mark File Statics

/* Private Category Declaration */
//@interface PaScanner (PaScanner_private)
//@end


@implementation PaScanner


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
//#pragma mark PaScanner_private


/** Public Operations (Group by Type) **/
//#pragma mark -
//#pragma mark Actions

@end

extern void scanMacro( char *tokenString ) { return; }

extern void scanCommentBlock( char *tokenString ) { return; }
extern void scanCommentLine( char *tokenString ) { return; }
extern void scanWhiteSpace( char *tokenString ) { return; }

extern int scanHexConstant( char *tokenString ) { return 0; }    
extern int scanOctalConstant( char *tokenString ) { return 0; }    
extern int scanDecimalConstant( char *tokenString ) { return 0; }    
extern int scanEscapeConstant( char *tokenString ) { return 0; }    
extern int scanFloatEConstant( char *tokenString ) { return 0; }    
extern int scanFloatDotConstant( char *tokenString ) { return 0; }    
extern int scanCString( char *tokenString ) { return 0; }     
extern int scanObjCString( char *tokenString ) { return 0; }  

extern int scanType( char *tokenString ) { return 0; }
