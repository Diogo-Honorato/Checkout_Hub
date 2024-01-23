CC = g++

CFLAGS = -Wall -std=c++11 -g -lm

# Nome do executável
EXECUTABLE = check-out.exe

# Diretórios
HEADER_DIR = API/Headers
SRC_DIR = API/Sources
OBJ_DIR = API/Objetos

# Obter automaticamente todos os arquivos .cpp no diretório source
SRCS = $(wildcard $(SRC_DIR)/**/*.cpp)

# Gerar nomes de arquivos .o a partir dos arquivos .cpp
OBJS = $(patsubst $(SRC_DIR)/%.cpp,$(OBJ_DIR)/%.o,$(SRCS))

# Regra para compilar todos os arquivos .o a partir dos arquivos .cpp
all: $(EXECUTABLE)


$(EXECUTABLE): $(OBJS)
	@$(CC) $(CFLAGS) $^ -o $@

# Regra para criar diretórios e compilar cada arquivo .cpp em um arquivo .o correspondente
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | obj_dirs
	@$(CC) $(CFLAGS) -I $(HEADER_DIR) -c $< -o $@

# Criação dos diretórios necessários para armazenar os arquivos .o
obj_dirs:
	@mkdir -p $(dir $(OBJS))

run:$(EXECUTABLE)
	@./$(EXECUTABLE)

leak:$(EXECUTABLE)
	@valgrind --leak-check=full ./$(EXECUTABLE)

debug:$(EXECUTABLE)
	gdb ./$(EXECUTABLE)


# Limpar arquivos objeto e o executável
clean:
	@rm -rf $(OBJ_DIR) $(EXECUTABLE)