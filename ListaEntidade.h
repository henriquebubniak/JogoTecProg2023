#pragma once
#include "Lista.h"
// #include "Ente.h"
#include "Entidade.h"

class ListaEntidade
{
private:
    // Lista<Ente> lista;
    Lista<Entidade*> lista;
public:
    // ListaEnte():
    ListaEntidade():
        lista()
    {}
    ~ListaEntidade()
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
        Lista<Entidade*>::Iterador iEntidade;
	iEntidade = lista.getPrimeiro();
	while (iEntidade.getProximo() != NULL)
	{
	    // if (doisJogadores) // esta na classe Fase -> construtora
            iEntidade.getAtual()->executar();
	    iEntidade.operator++(); // TODO alterar operator++ para ++ (corrigir sobrecarga de operador)
	}
	iEntidade.getAtual()->executar(); 
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


