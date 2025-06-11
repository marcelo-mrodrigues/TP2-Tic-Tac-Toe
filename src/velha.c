#include "velha.h"
#include <stdbool.h>  //  Usaremos para a flag

// "Copyright 2025 Marcelo Rodrigues"

int verificaVelha(int tabuleiro[3][3]) {
    bool temPeca = false;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] != 0) {
                temPeca = true;
                break;  // Achar peça
            }
        }
        if (temPeca) {
            break;
            // Se já achamos uma peça, não precisa procurar mais no tabuleiro
        }
    }
    if (!temPeca) {
        return -1;  //  Sem peça retorna indefinido
    }
    return 99;}