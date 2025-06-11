#include "velha.h"
#include <stdbool.h>  //  Usaremos para a flag

// "Copyright 2025 Marcelo Rodrigues"

int verificaVelha(int tabuleiro[3][3]) {
    // Checa as 3 linhas horizontais por vitória
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != 0
            && tabuleiro[i][0] == tabuleiro[i][1]
             && tabuleiro[i][1] == tabuleiro[i][2]) {
            return tabuleiro[i][0];  // Retorna o jogador (1 para X, 2 para O)
        }
    }
    
    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] != 0 && tabuleiro[0][j] == tabuleiro[1][j] && tabuleiro[1][j] == tabuleiro[2][j]) {
            return tabuleiro[0][j]; 
        }
    }   

    // --- VERIFICA EMPATE OU JOGO INDEFINIDO ---
    int pecasJogadas = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] != 0) {  // 0 significa que a posição está vazia
                pecasJogadas++;
            }
        }
    }

    if (pecasJogadas == 9) {
        return 0;  // 0 se o jogo está empatado
    } else {
        return -1;  // -1 se o jogo está indefinido
}}
