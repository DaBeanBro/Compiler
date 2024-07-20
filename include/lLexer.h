//
// Created by Peter Kilian on 2024/07/20.
// Last Edited: 2024/07/20  -   3:33pm
//

#ifndef COMPILER_LLEXER_H
#define COMPILER_LLEXER_H

#include "lToken.h"
typedef struct LexerState {
    TokenSeverity severity;
    int isScanning;
};

#endif //COMPILER_LLEXER_H