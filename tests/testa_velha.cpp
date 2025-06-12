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

TEST_CASE("3.2: Vitoria do O - Linha Horizontal", "[vitoria-o]") {
    int tabuleiro[3][3] = {
        {0, 1, 1},  // X Ganha
        {1, 1, 2},
        {2, 2, 2}
    };
    // A função deve retornar 2 se o 0 for o vencedor
    REQUIRE(verificaVelha(tabuleiro) == 2);}

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

TEST_CASE("4.2: Vitoria do 1 - Coluna Vertical", "[vitoria-x]") {
    int tabuleiro[3][3] = {
        {1, 2, 1},
        {0, 0, 1},
        {2, 2, 1}
    };

    // A função deve retornar 1 se o X for o vencedor
    REQUIRE(verificaVelha(tabuleiro) == 1);
}

TEST_CASE("5: Vitoria do X - Diagonal Principal", "[vitoria-x]") {
    // Teste de Vitória pela diagonal PRINCIPAL
    int tabuleiro[3][3] = {
        {1, 0, 2},
        {0, 1, 2},
        {0, 0, 1}
    };

    // A função deve retornar 1 se o X for o vencedor
    REQUIRE(verificaVelha(tabuleiro) == 1);
}

TEST_CASE("5.2: Vitoria do X - Diagonal Principal", "[vitoria-x]") {
    // Teste de Vitória pela diagonal PRINCIPAL O
    int tabuleiro[3][3] = {
        {2, 0, 1},
        {0, 2, 1},
        {0, 1, 2}
    };

    // A função deve retornar 2 se o O for o vencedor
    REQUIRE(verificaVelha(tabuleiro) == 2);
}

TEST_CASE("6: Vitoria do O - Diagonal Secundaria", "[vitoria-o]") {
    int tabuleiro[3][3] = {
        {1, 0, 2},
        {1, 2, 0},
        {2, 0, 1}
    };

    // A função deve retornar 2 se o O for o vencedor
    REQUIRE(verificaVelha(tabuleiro) == 2);
}

TEST_CASE("6.2: Vitoria do X - Diagonal Secundaria", "[vitoria-x]") {
    int tabuleiro[3][3] = {
        {2, 0, 1},
        {0, 1, 0},
        {1, 2, 0}
    };

    // A função deve retornar 1 se o X for o vencedor
    REQUIRE(verificaVelha(tabuleiro) == 1);
}

TEST_CASE("Final: Jogo Impossivel - Excesso de pecas", "[impossivel]") {
    // Estado impossível de jogo da velha (0 O's)
    int tabuleiro[3][3] = {
        {1, 1, 1},
        {0, 0, 0},
        {0, 0, 0}
    };
    // Um jogo impossível deve retornar -2
    REQUIRE(verificaVelha(tabuleiro) == -2);
}
