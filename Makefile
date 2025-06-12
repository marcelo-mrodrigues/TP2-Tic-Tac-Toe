# Compiladores
CXX = g++
CC = gcc

# Flags de compilação
# -g: para incluir informações de debug (para o GDB)
# -Wall -Wextra: para mostrar todos os avisos importantes
# -ftest-coverage -fprofile-arcs: para gerar dados de cobertura (para o gcov) 
CXXFLAGS = -std=c++11 -g -Wall -Wextra -ftest-coverage -fprofile-arcs
CFLAGS = -std=c11 -g -Wall -Wextra -ftest-coverage -fprofile-arcs

# Nome do executável de teste
TARGET = testa_velha_runner

# Diretórios
SRC_DIR = src
TEST_DIR = tests
LIBS_DIR = libs

# Arquivos fonte e objeto
SOURCES_C = $(SRC_DIR)/velha.c
OBJECTS = $(SOURCES_C:.c=.o)
TEST_SOURCES = $(TEST_DIR)/testa_velha.cpp

# Regra principal: compila e cria o executável de teste
all: $(TARGET)

$(TARGET): $(OBJECTS) $(TEST_SOURCES)
	$(CXX) $(CXXFLAGS) -I$(SRC_DIR) -I$(LIBS_DIR) $(TEST_SOURCES) $(OBJECTS) -o $@

# Regra para compilar os arquivos .c em arquivos objeto .o
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@


# Regra para rodar os testes
test: all
	./$(TARGET)

# Regra para rodar o analisador estático
check:
	cppcheck --enable=warning --error-exitcode=1 src/ tests/

# Regra para rodar com valgrind
memcheck: all
	valgrind --leak-check=full --error-exitcode=1 ./$(TARGET)

# Regra para rodar o linter (cpplint)
lint:
	python3 libs/cpplint.py src/velha.h src/velha.c tests/testa_velha.cpp

# Regra para gerar relatório de cobertura
coverage: test
	gcovr --gcov-ignore-parse-errors --filter src/ --root . --print-summary --fail-under-line 80

# Regra para limpar os arquivos gerados
clean:
	rm -f $(TARGET) $(SRC_DIR)/*.o *.gcda *.gcno *.gcov

.PHONY: all test clean

docs:
	doxygen
