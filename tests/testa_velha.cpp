#define CATCH_CONFIG_MAIN  //  Catch2 cria uma main()
#include "catch.hpp"

//  "Copyright 2025 Marcelo Rodrigues"

extern "C" {
    #include "velha.h"
}
TEST_CASE("1: Jogo Indefinido - Tabuleiro Vazio", "[indefinido]") {
    //  O valor 0 significa que a posição está vazia
    int tabuleiro[3][3] = {
        {0, 0, 0},
        {0, 0, 0},
        {0, 0, 0}
    };
    //  Jogo indefinido deve retornar -1
    REQUIRE(verificaVelha(tabuleiro) == -1);}

TEST_CASE("2: Jogo Empatado", "[empate]") {
    // Tabuleiro cheio, sem vencedor.
    int tabuleiro[3][3] = {
        {1, 2, 1},
        {1, 1, 2},
        {2, 1, 2}
    };
    // Um jogo empatado deve retornar 0
    REQUIRE(verificaVelha(tabuleiro) == 0);
}

TEST_CASE("3: Vitoria do X - Linha Horizontal", "[vitoria-x]") {
    int tabuleiro[3][3] = {
        {1, 1, 1},  // X Ganha
        {2, 0, 2},
        {0, 0, 0}
    };
    // A função deve retornar 1 se o X for o vencedor
    REQUIRE(verificaVelha(tabuleiro) == 1);}

TEST_CASE("4: Vitoria do O - Coluna Vertical", "[vitoria-o]") {
    // O (2) vence na segunda coluna
    int tabuleiro[3][3] = {
        {1, 2, 1},
        {0, 2, 0},
        {1, 2, 0}
    };

    // A função deve retornar 2 se o O for o vencedor
    REQUIRE(verificaVelha(tabuleiro) == 2);
}
