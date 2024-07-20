//
// Created by Peter Kilian on 2024/07/20.
//
#include <stdio.h>
#include <stdint.h>
#include <stddef.h>

typedef union {
    int32_t i32;
    size_t VarType[256];
    void* unknown;
} TokenType;

void printToken(TokenType token, char type) {
    switch (type) {
        case 'i':
            printf("Integer: %d\n", token.i32);
            break;
        case 'v':
            for (size_t i = 0; i < 256; i++) {
                printf("%zu ", token.VarType[i]);
                if ((i + 1) % 10 == 0) {
                    printf("\n");
                }
            }
            break;
        case 'u':
            if (token.unknown == NULL) {
                printf("Unknown: NULL\n");
            } else {
                printf("Unknown: %p\n", token.unknown);
            }
            break;
        default:
            printf("Invalid token type\n");
            break;
    }
}

int main() {
    TokenType token1 = {.i32 = 12345};

    TokenType token2;
    for (size_t i = 0; i < 256; i++) {
        token2.VarType[i] = i;
    }

    TokenType token3 = {.unknown = NULL};

    printToken(token1, 'u');
    printf("\n");

    return 0;
}