#pragma once
#include "Lama.h"
#include <stdlib.h>
#include <time.h>
class ConjuntoLamas
{
private:
    list<Lama*> listapLamas;
    vector<Vector2f> posicoesPossiveis;
    int nLamas;
public:
    ConjuntoLamas(Fase* pF = NULL, GerenciadorGrafico* pgg = NULL);
    ~ConjuntoLamas();
    void adLama(Fase* pF);
};

