// Last Edited: 2024/07/20  -   3:33pm

/* Standard Includes */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
/* My Includes */
#include "lLexer.h"
#include "lUtils.h"

/* main */
int main(void) {
    char* code = "inte";
    Token token = tokenize(code);
    printf("Token Type: %s\n", typeid_to_string(token.type.typeid));
    printf("Token Value: %s\n", token.value);
    return 0;
}