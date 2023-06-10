#pragma once
#include "Mina.h"
#include <stdlib.h>
#include <time.h>
class ConjuntoMinas
{
private:
    list<Mina*> listapMinas;
    vector<Vector2f> posicoesPossiveis;
    int nMinas;
public:
    ConjuntoMinas(Fase* pF = NULL, GerenciadorGrafico* pgg = NULL);
    ~ConjuntoMinas();
    void adMina(Fase* pF);
};

