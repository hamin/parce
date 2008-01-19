/*
 *  parce_custom_token.h
 *  Parce
 *
 *  Created by Brent Gulanowski on 02/12/07.
 *
 */

#include "PaToken.h"

#define YYSTYPE PaToken *

#define token PaToken // override the C-lib definition of token -- requires additional GCC argument -DCUSTOM_TOKEN_TYPE

