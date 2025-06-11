#ifndef VELHA_H
#define VELHA_H

// "Copyright 2025 Marcelo Rodrigues"

/**
 * @brief Verifica o estado de um jogo da velha.
 *
 * @param tabuleiro A matriz 3x3 representando o jogo.
 * 0 para vazio, 1 para X, 2 para O.
 * @return int Retorna 1 se X venceu, 2 se O venceu, 0 para empate,
 * -1 para jogo indefinido, -2 para jogo impossível.
 */

int verificaVelha(int tabuleiro[3][3]);

#endif  // VELHA_H