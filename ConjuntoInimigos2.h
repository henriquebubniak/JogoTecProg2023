#include "Inimigo2.h"
#include <stdlib.h>
#include <time.h>
class ConjuntoInimigos2
{
private:
    list<Inimigo2*> listapInis;
    vector<Vector2f> posicoesPossiveis;
    int nInimigos;
public:
    ConjuntoInimigos2(Fase* pF = NULL, GerenciadorGrafico* pgg = NULL, Jogador1* pJ1 = NULL, Jogador2* pJ2 = NULL);
    ~ConjuntoInimigos2();
    void adInimigos2(Fase* pF);
};

