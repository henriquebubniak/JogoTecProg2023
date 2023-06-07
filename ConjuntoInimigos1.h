#include "Inimigo1.h"
#include <stdlib.h>
#include <time.h>
class ConjuntoInimigos1
{
private:
    list<Inimigo1*> listapInis;
    vector<Vector2f> posicoesPossiveis;
    int nInimigos;
public:
    ConjuntoInimigos1(Fase* pF = NULL, GerenciadorGrafico* pgg = NULL, Jogador1* pJ1 = NULL, Jogador2* pJ2 = NULL);
    ~ConjuntoInimigos1();
    void adInimigos1(Fase* pF);
};

