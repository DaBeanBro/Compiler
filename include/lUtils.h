//
// Created by Peter Kilian on 2024/07/20.
//

#ifndef COMPILER_LUTILS_H
#define COMPILER_LUTILS_H
#include "lLexer.h"

void slice_array(int* src, int start, int end, int** dest, int* length);
size_t get_token_type_size(TokenType type);
const char* typeid_to_string(TypeID typeid);

#endif //COMPILER_LUTILS_H
