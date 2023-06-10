#include "ConjuntoMinas.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoMinas::ConjuntoMinas(Fase* pF, GerenciadorGrafico* pgg):
    nMinas(0),
    listapMinas()
{
    srand(time(NULL));
    rand();
    nMinas = (rand()%7) + 4;//de 4 a 10 CowboyPerseguidor
    cout << nMinas << " Minas" << endl;
    //8200 - 11000
    int delta = (10600-8200)/nMinas;
    for (float i = 8200.0; i < 10600.0; i+=(float)delta)
    {
        listapMinas.push_back(new Mina(Vector2f(i, 1400.f), pF, pgg));
    }    
}

ConjuntoMinas::~ConjuntoMinas()
{
    for (list<Mina*>::iterator i = listapMinas.begin(); i != listapMinas.end(); i++)
    {
        delete(*i);
    }
}

void ConjuntoMinas::adMina(Fase* pF)
{
    for (list<Mina*>::iterator i = listapMinas.begin(); i != listapMinas.end(); i++)
    {
        pF->adEntidade(static_cast<Entidade*>(*i));
    }
}