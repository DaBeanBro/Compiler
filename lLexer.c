//
// Created by Peter Kilian on 2024/07/20.
// Last Edited: 2024/07/20  -   3:33pm
//

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <ctype.h>
#include <string.h>
#include "lLexer.h"
#include "lUtils.h"

void token_print(Token token);
Token tokenize(char *code) {
    Token token;
    token.type.typeid = UNKNOWN;
    token.type.value.unknown = 0;
    memset(token.value, 0, sizeof(token.value));

    static struct LexerState state = { NONE, 0 };
    state.severity = NONE;
    state.isScanning = 0;

    int code_length = strlen(code);
    for (int i = 0; i < code_length; i++) {
        // Skip blank spaces
        if (isblank(code[i])) {
            continue;
        }

        // Check for alphanumerical value
        if (isalnum(code[i])) {
            token.type.value.unknown = 1; // Indicates "unknown" is true
        } else {
            token.type.value.unknown = 0;
        }

        // Check if the type size matches
        if (token.type.value.unknown == 1 && get_token_type_size(token.type) == sizeof(token.type.value.type.variable)) {
            if (strncmp(&code[i], "int", 3) == 0) {
                token.type.typeid = I32;
                strncpy(token.value, "int", 3);
                token.value[3] = '\0'; // Null-terminate the string
                i += 2; // Move the index past "int"
                continue; // Continue with the next character
            } else {
                token.type.typeid = IDENTIFIER;
                int j = 0;
                while (isalnum(code[i]) && i < code_length && j < sizeof(token.value) - 1) {
                    token.value[j++] = code[i++];
                }
                token.value[j] = '\0'; // Null-terminate the string
                return token; // Return the identifier token
            }
        } else {
            // Handle other cases if necessary
            fprintf(stderr, "Unexpected token or error!\n");
            return token;
        }
    }

    return token;
}
