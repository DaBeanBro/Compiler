//
// Created by Peter Kilian on 2024/07/20.
//
#include <stdlib.h>
#include <string.h>
#include "lUtils.h"

void slice_array(int* src, int start, int end, int** dest, int* length) {
    *length = end - start;
    *dest = malloc(*length * sizeof(int));
    if (*dest != NULL) {
        memcpy(*dest, src + start, *length * sizeof(int));
    }
}

size_t get_token_type_size(TokenType type) {
    switch (type.typeid) {
        case I32:
            return sizeof(int);
        case IDENTIFIER:
            return sizeof(char*);
        case UNKNOWN:
        default:
            return sizeof(type.value.unknown);
    }
}

const char* typeid_to_string(TypeID typeid) {
    switch (typeid) {
        case I32: return "I32";
        case IDENTIFIER: return "IDENTIFIER";
        case UNKNOWN: return "UNKNOWN";
        default: return "UNKNOWN";
    }
}