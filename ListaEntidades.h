#pragma once
#include "Lista.h"
// #include "Ente.h"
#include "Entidade.h"

class ListaEntidades
{
private:
    Lista<Entidade*> lista;
public:   
    ListaEntidades():
        lista()
    {}
    ~ListaEntidades()
    {}
    // chama executar de cada entidade na lista
    void executarEntidades()
    {
        Lista<Entidade*>::Iterador iEntidade;
	iEntidade = lista.getpPrimeiro();
	while (iEntidade.getProximo() != NULL)
	{
	    // if (doisJogadores) // esta na classe Fase -> construtora
            iEntidade.getAtual()->executar();
	    iEntidade.operator++(); // TODO alterar operator++ para ++ (corrigir sobrecarga de operador)
	}
	iEntidade.getAtual()->executar(); 
    }
    void desenhar()
    {
	Lista<Entidade*>::Iterador iEntidade;
	iEntidade = lista.getpPrimeiro();
	while (iEntidade.getProximo() != NULL)
	{
		iEntidade.getAtual()->desenhar();
		iEntidade.operator++();
	}
	iEntidade.getAtual()->desenhar();
    }
    void incluir(Entidade** pE)
    {
        lista.incluir(pE);
    }
    void limpar()
    {
        lista.limpar();
    }
    void remover(Entidade** pE)
    {
        lista.remover(pE);
    }
};


