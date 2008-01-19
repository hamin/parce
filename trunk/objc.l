/*

parce: objc.l

Copyright 2007 Bored Astronaut Software. All rights reserved.

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

D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%top{
#include "parce_scanner_actions.h"
#include "parce_parser_token.h"

#define YY_DECL int yylex( token *yylval )

#define YY_USER_INIT scanInitialize()
}

%%
"^#.*"          { scanMacro( yylval, yytext ); }
"\/\*.*\*\/"	{ scanCommentBlock(  yylval, yytext ); }
"\/\/.*"		{ scanCommentLine(  yylval, yytext ); }

"auto"			{ return AUTO; }
"break"			{ return BREAK; }
"case"			{ return CASE; }
"char"			{ return CHAR; }
"const"			{ return CONST; }
"continue"		{ return CONTINUE; }
"default"		{ return DEFAULT; }
"do"			{ return DO; }
"double"		{ return DOUBLE; }
"else"			{ return ELSE; }
"enum"			{ return ENUM; }
"extern"		{ return EXTERN; }
"float"			{ return FLOAT; }
"for"			{ return FOR; }
"goto"			{ return GOTO; }
"if"			{ return IF; }
"int"			{ return INT; }
"long"			{ return LONG; }
"register"		{ return REGISTER; }
"return"		{ return RETURN; }
"short"			{ return SHORT; }
"signed"		{ return SIGNED; }
"sizeof"		{ return SIZEOF; }
"static"		{ return STATIC; }
"struct"		{ return STRUCT; }
"switch"		{ return SWITCH; }
"typedef"		{ return TYPEDEF; }
"union"			{ return UNION; }
"unsigned"		{ return UNSIGNED; }
"void"			{ return VOID; }
"volatile"		{ return VOLATILE; }
"while"			{ return WHILE; }
"..."			{ return ELLIPSIS; }

"id"			{ return OBJC_ID; }
"self"			{ return SELF; }
"super"			{ return SUPER; }
"@end"			{ return AT_END; }
"@interface"	{ return AT_INTERFACE; }
"@implementation"	{ return AT_IMPLEMENTATION; }
"@protocol"		{ return AT_PROTOCOL; }
"@class"		{ return AT_CLASS; }
"@selector"		{ return AT_SELECTOR; }
"@encode"		{ return AT_ENCODE; }
"@defs"			{ return AT_DEFS; }
 
"@private"		{ return AT_PRIVATE; }
"@protected"	{ return AT_PROTECTED; }
"@public"		{ return AT_PUBLIC; }
 
"@throw"		{ return AT_THROW; }
"@try"			{ return AT_TRY; }
"@catch"		{ return AT_CATCH; }
"@finally"		{ return AT_FINALLY; }
"@synchronized"	{ return AT_SYNCHRONIZED; }
 
"in"			{ return IN; }
"out"			{ return OUT; }
"inout"			{ return INOUT; }
"bycopy"		{ return BYCOPY; }
"byref"			{ return BYREF; }
"oneway"		{ return ONEWAY; }
 
{L}({L}|{D})*	{ return scanType(  yylval, yytext ); }

0[xX]{H}+{IS}?	{ return scanHexConstant(  yylval, yytext ); }
0{D}+{IS}?		{ return scanOctalConstant(  yylval, yytext ); }
{D}+{IS}?		{ return scanDecimalConstant(  yylval, yytext ); }
'(\\.|[^\\'])+'		{ return scanEscapeConstant(  yylval, yytext ); }

{D}+{E}{FS}?		{ return scanFloatEConstant(  yylval, yytext ); }
{D}*"."{D}+({E})?{FS}?	{ return scanFloatDotConstant(  yylval, yytext ); }
{D}+"."{D}*({E})?{FS}?	{ return scanFloatDotConstant(  yylval, yytext ); }

\"(\\.|[^\\"])*\"	{ return scanCString(  yylval, yytext ); }

@\"(\\.|[^\\"])*\"	{ return scanObjCString(  yylval, yytext ); }

">>="		{ return RIGHT_ASSIGN; }
"<<="		{ return LEFT_ASSIGN; }
"+="		{ return ADD_ASSIGN; }
"-="		{ return SUB_ASSIGN; }
"*="		{ return MUL_ASSIGN; }
"/="		{ return DIV_ASSIGN; }
"%="		{ return MOD_ASSIGN; }
"&="		{ return AND_ASSIGN; }
"^="		{ return XOR_ASSIGN; }
"|="		{ return OR_ASSIGN; }
">>"		{ return RIGHT_OP; }
"<<"		{ return LEFT_OP; }
"++"		{ return INC_OP; }
"--"		{ return DEC_OP; }
"->"		{ return PTR_OP; }
"&&"		{ return AND_OP; }
"||"		{ return OR_OP; }
"<="		{ return LE_OP; }
">="		{ return GE_OP; }
"=="		{ return EQ_OP; }
"!="		{ return NE_OP; }
";"			{ return ';'; }
"{"			{ return '{'; }
"}"			{ return '}'; }
","			{ return ','; }
":"			{ return ':'; }
"="			{ return '='; }
"("			{ return '('; }
")"			{ return ')'; }
"["			{ return '['; }
"]"			{ return ']'; }
"."			{ return '.'; }
"&"			{ return '&'; }
"!"			{ return '!'; }
"~"			{ return '~'; }
"-"			{ return '-'; }
"+"			{ return '+'; }
"*"			{ return '*'; }
"/"			{ return '/'; }
"%"			{ return '%'; }
"<"			{ return '<'; }
">"			{ return '>'; }
"^"			{ return '^'; }
"|"			{ return '|'; }
"?"			{ return '?'; }

[ \t\v\n\f]+		{ scanWhiteSpace(  yylval, yytext ); }
.			{ /* ignore bad characters */ }

%%
