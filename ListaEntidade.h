#pragma once
#include "Lista.h"
// #include "Ente.h"
#include "Entidade.h"

class ListaEntidade
{
private:
    // Lista<Ente> lista;
    Lista<Entidade> lista;
public:
    // ListaEnte():
    ListaEntidade():
        lista()
    {}
    ~ListaEnte()
    {}
    /* void imprimirEntes()
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
    */
    void executarEntidades() //chama executar de cada entidade na lista
    {
        
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


