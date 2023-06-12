#include "ConjuntoMinas.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoMinas::ConjuntoMinas(Fase* pF, GerenciadorGrafico* pgg):
    nMinas(0),
    listapMinas()
{
    srand(time(NULL));
    rand();
    nMinas = (rand()%7) + 4;//de 4 a 10 Minas
    cout << nMinas << " Minas" << endl;
    //7000 - 9300
    int delta = (9300-7000)/nMinas;
    for (float i = 7000.0; i < 9300.0; i+=(float)delta)
    {
        listapMinas.push_back(new Mina(Vector2f(i, 0.f), pF, pgg));
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