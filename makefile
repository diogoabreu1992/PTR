# Nome do programa final
PROG = programa

# Compilador
CC = gcc

# Flags de compilação
CFLAGS = -std=c17 -Wall -Wextra -Iinclude -pthread

# Flags de link (somente ao criar o executável)
LDFLAGS = -pthread -lm -lrt

# Diretórios
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

# Lista de arquivos .c
SRCS = $(wildcard $(SRC_DIR)/*.c)

# Gera lista de objetos correspondentes em build/
OBJS = $(SRCS:$(SRC_DIR)/%.c=$(BUILD_DIR)/%.o)

# Regra padrão
all: $(PROG)

# Como gerar o executável
$(PROG): $(OBJS)
	$(CC) $(OBJS) -o $(PROG) $(LDFLAGS)

# Como compilar cada .c em .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c | $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Garantir que build/ existe
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Limpeza
clean:
	rm -rf $(BUILD_DIR)/* $(PROG)