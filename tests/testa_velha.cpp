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