# Makefile para compilar em Linux e macOS

# Diretório para os arquivos .o
OBJ_DIR = obj

# Arquivos do projeto
SRCS = *.cpp

# Opções de compilação para Linux
LINUX_CXX = g++
LINUX_CXXFLAGS = -fdiagnostics-color=always -g -I/usr/include/SFML
LINUX_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lsfml-graphics -lsfml-window -lsfml-system

# Opções de compilação para macOS
MACOS_CXX = g++
MACOS_CXXFLAGS = -fdiagnostics-color=always -g
MACOS_INCLUDES = -I/opt/homebrew/Cellar/sfml/2.5.1_2/include
MACOS_LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.5.1_2/lib -lsfml-graphics -lsfml-window -lsfml-system

# Objetos gerados
OBJS = $(addprefix $(OBJ_DIR)/,$(SRCS:.cpp=.o))

# Regra padrão
all: $(OBJ_DIR) jogo

# Regra para criar o diretório dos objetos
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

# Regra para compilar o jogo
jogo: $(OBJS)
	$(MACOS_CXX) $(MACOS_CXXFLAGS) $(OBJS) -o jogo $(MACOS_LDFLAGS)

# Regra para compilar para Linux
linux:  $(SRCS)
	$(LINUX_CXX) $(LINUX_CXXFLAGS) $(SRCS) -o jogo $(LINUX_LDFLAGS)

# Regra para compilar para macOS
macos: $(SRCS)
	$(MACOS_CXX) $(MACOS_CXXFLAGS) $(SRCS) $(MACOS_INCLUDES) -o jogo $(MACOS_LDFLAGS)

# Regra para limpar
clean:
	rm -rf $(OBJ_DIR) jogo
	rm *.o

# Regra para gerar os arquivos .o
$(OBJ_DIR)/%.o: %.cpp
	$(MACOS_CXX) $(MACOS_CXXFLAGS) -c $< -o $@












