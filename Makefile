# Makefile para compilar em Linux e macOS

# Diretório para os arquivos .o
OBJ_DIR = obj

# Arquivos do projeto
SRCS = main.cpp Jogo.cpp GerenciadorGrafico.cpp Ente.cpp Entidade.cpp Botao.cpp CursorBot.cpp Menu.cpp Fase.cpp Plataforma.cpp Fase1.cpp GerenciadorColisoes.cpp Personagem.cpp Jogador1.cpp Projetil.cpp Jogador2.cpp

# Opções de compilação para Linux
LINUX_CXX = g++
LINUX_CXXFLAGS = -fdiagnostics-color=always -g -I/usr/include/SFML
LINUX_LDFLAGS = -L/usr/lib/x86_64-linux-gnu -lsfml-graphics -lsfml-window -lsfml-system

# Opções de compilação para macOS
MACOS_CXX = g++
MACOS_CXXFLAGS = -fdiagnostics-color=always -g -I/opt/homebrew/Cellar/sfml/2.5.1_1/include
MACOS_LDFLAGS = -L/opt/homebrew/Cellar/sfml/2.5.1_1/lib -lsfml-graphics -lsfml-window -lsfml-system

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
linux: $(OBJ_DIR) $(SRCS)
	$(LINUX_CXX) $(LINUX_CXXFLAGS) -c $(SRCS)
	$(LINUX_CXX) $(OBJS) -o jogo $(LINUX_LDFLAGS)

# Regra para compilar para macOS
macos: $(OBJ_DIR) $(SRCS)
	$(MACOS_CXX) $(MACOS_CXXFLAGS) -c $(SRCS)
	$(MACOS_CXX) $(OBJS) -o jogo $(MACOS_LDFLAGS)

# Regra para limpar
clean:
	rm -rf $(OBJ_DIR) jogo

# Regra para gerar os arquivos .o
$(OBJ_DIR)/%.o: %.cpp
	$(MACOS_CXX) $(MACOS_CXXFLAGS) -c $< -o $@












