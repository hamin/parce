
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


SOURCES = parce_parser.c			\
		parce_scanner.c			\
		parce_scanner_actions.c	\
		parce_parser_actions.c	\
		parce_parser_token.c		\
		main.c
		
LIB_SOURCES = parce_parser.c		\
		parce_scanner.c			\
		parce_scanner_actions.c	\
		parce_parser_actions.c	\
		parce_parser_token.c

OBJECTS = $(SOURCES:.c=.o)

LIB_OBJECTS = $(LIB_SOURCES:.c=.o)

.SUFFIXES:
.SUFFIXES: .c .o
.c.o:
	$(CC) $(CFLAGS) $*.c


all: parce_parser


parce_parser: $(OBJECTS)
	$(LD) $@ $(OBJECTS)
	
clean:
	rm -f objc_parser *.o parce_parser.h parce_parser.c parce_parser.output parce_scanner.c

#objc_parser_lib: $(LIB_SOURCES)

objc_parser.c: objc.y
	$(YACC) -dv -oparce_parser.c objc.y

objc_scanner.c: objc.l
	$(LEX) -oparce_scanner.c objc.l
