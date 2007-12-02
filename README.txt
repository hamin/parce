2007 December 1


ABOUT PARCE

The software accompanying this README file is meant to provide a foundation for examining the structure of C and Objective-C programs. There are two main parts: files which specify the parser and scanner components (meant to be processed by Bison and Flex), and files which define and implement functions to create an abstract syntax tree (on which the geenerated parser and scanner depend).

Additionally, there is a basic main file to enable testing, and a makefile to build the software.

The design of the parser and scanner components have been kept as simple as possible. The idea is that the semantic action functions allow creation of a token tree to capture all of the syntactical and value information in the source code (including white space, comments and pre-processor commands (TODO)), and then a program can work on the tree any way that it sees fit. (The driving force for the creation of the parser is to create the tree for the benefit of a Mac OS X program written in Cocoa for editing Objective-C programs in an object-oriented manner).

The primary goals of the design are two, but are met by a single strategy: by separating the implementation of the semantic action functions (and the associated data type "token") from the generated parser and scanner, the same generated parser and scanner specifications can be used with any substituted implementation of the semantic processing component, and they can be distributed under different licenses.

Additionally, the included impelementation files can be used as-is if they are sufficient, and together with the generated components can form a simple library.

Hopefully this will be useful to someone.


NOTES ABOUT BUILDING THE SOURCES

I have included a basic makefile and an XCode project. The makefile should be self explanatory.

Where are "parce_parser.h and parce_parser.c"? Read on.

The XCode project may be confusing to those unfamiliar with working with non-source code input files (such as Yacc grammar specification files). There are at least two ways to support these files, but both have their drawbacks.

XCode can process lex (.l) and yacc (.y) input files itself, although it requires tweaking. In Mac OS X v10.4 (Tiger) and earlier, the default install of bison does not support the %pure-parser directive. Solving that requires a custom build rule for yacc files. On Mac OS X v10.5 (Leopard), yacc resolves to bison 2.3, so this is not an issue.

When processing lex and yacc files, the intermediate *.c files are compiled immediately. Unfortunately, the default rules do not take into account the fact that the generated flex scanner depends on a header file output by bison. On multiprocessor machines, this causes the compilation of the scanner to fail.

There are two solutions to this problem that I've found, although both amount to roughly the same thing (custom scripts). Either make a custom lex rule, and add "sleep(1)" before the lex command, to ensure that bison finishes first; or use a custom Run Script build phase to generate the parser.

I tried the first technique and didn't like it. It's too hackish. The second technique, requires adding the intermediate output from bison to the project, but this is akin to building a framework and an application that depends upon it in the same project.


BACKGROUND

The parser and scanner generator input files (objc.y and objc.l, respectively), are built on work done by others, predominantly the C85 grammar distributed by Jeff Lee, and a c89 specification distributed by Adrian Johnstone and Elizabeth Scott. (The work of the latter team was not in the YACC format, so I had to convert it.) Additionally, the statement rules were redefined--to remove the ambiguity of nested if-else statements--following a technique outlined in a document published by Parsifal Software ("Resolving the General Dangling Else/If Else Ambiguity, www.parsifalsoft.com/ifelse.html). Objective-C additions were created based on the Grammar appendix in The Objective-C Programming Language from Apple. Unfortunately, there seem to be some problems with Apple's addenda; I am hoping that someone authoritative will independently verify them, and publish corrections to any errors they find (especially in the declaration of class instance variables).

I have done all of this work without access to any ISO specifications, primarily because I'm interested in Objective-C, which to my knowledge has no legitimate standard, and also because I'm not writing a compiler and am not currently doing any work in the correctness of C programs. I am mostly interested in the structure of Objective-C programs at the level of classes, protocols, methods and message patterns. A long term goal is to investigate a technique for separating pure C statements from Objective-C message statements, perhaps to aid in compilation, but mostly to aid in program design.

Brent Gulanowski

