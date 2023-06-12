#pragma once
#include "Plataforma.h"
#include <stdlib.h>
#include <time.h>
class ConjuntoPlataformas
{
private:
    list<Plataforma*> listapPlataformas;
    vector<Vector2f> posicoesPossiveis;
    int nPlataformas;
    int fase;
public:
    ConjuntoPlataformas(Fase* pF = NULL, GerenciadorGrafico* pgg = NULL, int f = 1);
    ~ConjuntoPlataformas();
    void adPlataforma(Fase* pF);
};

