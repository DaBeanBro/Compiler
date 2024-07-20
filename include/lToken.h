//
// Created by Peter Kilian on 2024/07/20.
// Last Edited: 2024/07/20  -   3:33pm
//

#ifndef COMPILER_LTOKENS_H        /* Contains definitions for Token related types and structures. */
#define COMPILER_LTOKENS_H

//#include <stdint.h>
#include <stddef.h>

typedef enum {
    I32,
    IDENTIFIER,
    UNKNOWN
} TypeID;

union TypeValue {
    struct {
        int variable;
        int keyword;
    } type;
    int unknown;
} type_declarations;

typedef struct {
    TypeID typeid;
    union TypeValue value;
} TokenType;

typedef enum TokenSeverity {
    HIGH,
    MEDIUM,
    LOW,
    NONE
} TokenSeverity;

typedef char TokenValue[256];

typedef struct {
    TokenType type;
    TokenValue value;
} Token;

Token tokenize(char* code);
void token_print(Token token);

#endif //COMPILER_LEXER_TOKENS_H