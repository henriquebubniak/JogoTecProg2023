#include "Personagem.h"
class Jogador: public Personagem
{
private:
    
public:
    Jogador(Vector2f p = Vector2f(0.f, 0.f), Fase* f = NULL, GerenciadorGrafico* pgg = NULL, int h = 0, float v = 1,  const char* cT = "./imagens/padrao.png");
    ~Jogador();
};
