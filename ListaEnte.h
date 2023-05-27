#pragma once
#include "Lista.h"
#include "Ente.h"

class ListaEnte
{
private:
    Lista<Ente> lista;
public:
    ListaEnte():
        lista()
    {}
    ~ListaEnte()
    {}
    void imprimirEntes()
    {
        Lista<Ente>::Iterador iEnte;
        iEnte = lista.getpPrimeiro();
        while (iEnte.getProximo() != NULL)
        {
            iEnte.getAtual()->seImprimir();
            iEnte.operator++();
        }      
        iEnte.getAtual()->seImprimir();
    }
    void incluir(Ente* pE)
    {
        lista.incluir(pE);
    }
    void limpar()
    {
        lista.limpar();
    }
    void remover(Ente* pE)
    {
        lista.remover(pE);
    }
};


