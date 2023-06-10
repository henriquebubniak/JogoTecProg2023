#include "ConjuntoLamas.h"
#include <stdlib.h>
#include "Fase.h"

ConjuntoLamas::ConjuntoLamas(Fase* pF, GerenciadorGrafico* pgg):
    nLamas(0),
    listapLamas()
{
    srand(time(NULL));
    rand();
    nLamas = (rand()%4) + 3;//de 4 a 10 Lamas
    vector<Vector2f> posPossiveis;
    vector<int> indicesPos;
    posPossiveis.push_back(Vector2f(2200.f, 1445.f));
    posPossiveis.push_back(Vector2f(3500.f, 995.f));
    posPossiveis.push_back(Vector2f(4700.f, 545.f));
    posPossiveis.push_back(Vector2f(7600.f, 995.f));
    posPossiveis.push_back(Vector2f(8800.f, 1445.f));
    posPossiveis.push_back(Vector2f(10000.f, 1445.f));
    cout << nLamas << " Lamas" << endl;
    while (indicesPos.size() < nLamas)
    {
        int auxrand = rand()%6;
        auto it = find(indicesPos.begin(), indicesPos.end(), auxrand);
        if (it == indicesPos.end())
        {
            cout << "POS LAMA " << auxrand << endl;
            indicesPos.push_back(auxrand);
        }
        
    }
    for (int i = 0; i < nLamas; i++)
    {
        listapLamas.push_back(new Lama(posPossiveis[indicesPos[i]], pF, pgg));
    }    
}

ConjuntoLamas::~ConjuntoLamas()
{
    for (list<Lama*>::iterator i = listapLamas.begin(); i != listapLamas.end(); i++)
    {
        delete(*i);
    }
}

void ConjuntoLamas::adLama(Fase* pF)
{
    for (list<Lama*>::iterator i = listapLamas.begin(); i != listapLamas.end(); i++)
    {
        pF->adEntidade(static_cast<Entidade*>(*i));
    }
}