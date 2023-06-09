#include "CowboyPerseguidor.h"
#include <stdlib.h>
#include <time.h>
class ConjuntoCowboyPerseguidor
{
private:
    list<CowboyPerseguidor*> listapInis;
    vector<Vector2f> posicoesPossiveis;
    int nInimigos;
public:
    ConjuntoCowboyPerseguidor(Fase* pF = NULL, GerenciadorGrafico* pgg = NULL, HeroiPreto* pJ1 = NULL, HeroiVerde* pJ2 = NULL);
    ~ConjuntoCowboyPerseguidor();
    void adCowboyPerseguidor(Fase* pF);
};

