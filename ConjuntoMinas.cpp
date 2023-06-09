#include "ConjuntoMinas.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoMinas::ConjuntoMinas(Fase* pF, GerenciadorGrafico* pgg):
    nMinas(0),
    listapMinas(),
    posicoesPossiveis()
{
    srand(time(NULL));
    rand();
    nMinas = (rand()%7) + 4;//de 4 a 10 Minas
    cout << nMinas << " CowboyPerseguidor" << endl;
    posicoesPossiveis.push_back(Vector2f(2000.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(2300.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(2600.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(3400.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(3700.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(4000.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(4300.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(4600.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(4900.f, 0.f));
    posicoesPossiveis.push_back(Vector2f(5200.f, 0.f));
    for (int i = 0; i < nMinas; i++)
    {
        listapMinas.push_back(new Mina(posicoesPossiveis[i], pF, pgg, 10));
    }
    
}

ConjuntoMinas::~ConjuntoMinas()
{
}

void ConjuntoMinas::adMina(Fase* pF)
{
    for (list<Mina*>::iterator i = listapMinas.begin(); i != listapMinas.end(); i++)
    {
        pF->adEntidade(static_cast<Entidade*>(*i));
    }
}