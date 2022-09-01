#include "lexer.h"

char** LexContents(char *script_contents) {
    return str_split(script_contents, " ");
}