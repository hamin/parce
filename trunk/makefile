
#
# parce: makefile
#
# Copyright 2007 Bored Astronaut Software. All rights reserved.
# 
# Redistribution and use in source and binary forms, with or without modification, are permitted provided that the following conditions are met:
# 
# - Redistributions of source code must retain the above copyright notice, this list of conditions and the following disclaimer.
# 
# - Redistributions in binary form must reproduce the above copyright notice, this list of conditions and the following disclaimer in the documentation and/or other materials provided with the distribution.
# 
# THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
# "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
# LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
# A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
# CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
# EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
# PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
# PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
# LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
# NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
# SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.


YACC= bison

LEX	= flex

CC	= gcc -c
LD	= gcc -o

CFLAGS =


SOURCES = objc_parser.c			\
		objc_scanner.c			\
		objc_scanner_actions.c	\
		objc_parser_actions.c	\
		objc_parser_token.c		\
		main.c
		
LIB_SOURCES = objc_parser.c		\
		objc_scanner.c			\
		objc_scanner_actions.c	\
		objc_parser_actions.c	\
		objc_parser_token.c

OBJECTS = $(SOURCES:.c=.o)

LIB_OBJECTS = $(LIB_SOURCES:.c=.o)

.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) $*.c


all: objc_parser


objc_parser: $(OBJECTS)
	$(LD) $@ $(OBJECTS)
	
clean:
	rm -f objc_parser *.o objc_parser.h objc_parser.c objc_parser.output objc_scanner.c

#objc_parser_lib: $(LIB_SOURCES)

objc_parser.c: objc.y
	$(YACC) -dv -oobjc_parser.c objc.y

objc_scanner.c: objc.l
	$(LEX) -oobjc_scanner.c objc.l
