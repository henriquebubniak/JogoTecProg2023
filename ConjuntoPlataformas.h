#include "Plataforma.h"
#include <stdlib.h>
#include <time.h>
class ConjuntoPlataformas
{
private:
    list<Plataforma*> listapPlataformas;
    vector<Vector2f> posicoesPossiveis;
    int nPlataformas;
public:
    ConjuntoPlataformas(Fase* pF = NULL, GerenciadorGrafico* pgg = NULL);
    ~ConjuntoPlataformas();
    void adPlataforma(Fase* pF);
};

