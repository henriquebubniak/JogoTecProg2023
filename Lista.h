#pragma once
#include <iostream>

template <typename TL>
class Lista
{
private:
    template <typename TE>
    class Elemento
    {
    private:
        TE* pInfo;
        Elemento<TE>* pProximo;
        Elemento<TE>* pAnterior;
    public:
    //Construtora e destrutora
        Elemento(TE* pT = NULL):
            pInfo(pT),
            pProximo(NULL),
            pAnterior(NULL)
        {}
        ~Elemento()
        {
            pInfo = NULL;
            pProximo = NULL;
            pAnterior = NULL;
        }
    //Gets e sets
        void setProximo(Elemento<TE>* pP)
        {
            pProximo = pP;
        }
        void setAnterior(Elemento<TE>* pP)
        {
            if(pP)
                pAnterior = pP;
            else
                std::cout << "pP nulo em Elemento::setProximo" << std::endl;
        }
        Elemento<TE>* getProximo()
        {
            return pProximo;
        }
        Elemento<TE>* getAnterior()
        {
            return pAnterior;
        }
        TE* getInfo()
        {
            return pInfo;
        }
    };

    Elemento<TL>* pPrimeiro;
    Elemento<TL>* pAtual;
public:
    class Iterador
    {
    private:
        Elemento<TL>* pAtual;
        Elemento<TL>* pProximo;
    public:
    //Construtora e destrutora
        Iterador():
            pAtual(NULL),
            pProximo(NULL)
        {}
        ~Iterador()
        {
            pAtual = NULL;
            pProximo = NULL;
        }
    //Gets
        Elemento<TL>* getProximo()
        {
            return pProximo;
        }
        TL* getAtual()
        {
            if(pAtual)
                return pAtual->getInfo();
            return NULL;
        }
        Elemento<TL>* getElementoAtual()
        {
            return pAtual;
        }
    //Operadores sobrecarregados
        void operator++()
        {
            if (pProximo)
            {
                pAtual = pProximo;
                pProximo = pAtual->getProximo();
            }
        }
        void operator=(Elemento<TL>* pE)
        {
            if(pE)
            {
                pAtual = pE;
                pProximo = pE->getProximo();
            }
        }
    };
//Construtor e destrutor
    Lista():
        pPrimeiro(NULL),
        pAtual(NULL)
    {}
    ~Lista()
    {
        limpar();  
    }
//Funcionalidades
    void incluir(TL* pT)
    {
        if (pT)
        {
            if (pPrimeiro == NULL && pAtual == NULL)
            {
                pPrimeiro = new Elemento<TL>(pT);
                pAtual = pPrimeiro;
            }
            else
            {
                Elemento<TL>* pAux = new Elemento<TL>(pT);
                pAux->setAnterior(pAtual);
                pAtual->setProximo(pAux);
                pAtual = pAux;
                pAux = NULL;
            }        
        }
        else
            std::cout << "Ponteiro nulo em Lista::incluir()" << std::endl;
    }
    void limpar()
    {
        Iterador it;
        it = getpPrimeiro();
        if(it.getElementoAtual())
        {
            while (it.getProximo() != NULL)
            {
                delete(it.getElementoAtual());
                it.operator++();
            }
            delete(it.getElementoAtual()); 
        }
        pPrimeiro = NULL;
        pAtual = NULL;
    }
    void remover(TL* no)
    {
        Iterador it;
        it = getpPrimeiro();
        if(it.getElementoAtual())
        {
            if (it.getAtual() == no)
            {
                it.getProximo()->setAnterior(NULL);
                pPrimeiro = it.getProximo();
                delete(it.getElementoAtual());
            }
            
            while(it.getProximo() != NULL)
            {
                if(it.getProximo()->getInfo() == no)
                {
                    it.getElementoAtual()->setProximo(it.getProximo()->getProximo());
                    if (it.getProximo()->getProximo())
                    {
                        it.getProximo()->getProximo()->setAnterior(it.getElementoAtual());
                        delete(it.getProximo());
                    }
                    else
                    {
                        pAtual = it.getElementoAtual();
                        delete(it.getProximo());
                    }
                }
                it.operator++();
            }
        }
    }
//Gets
    Elemento<TL>* getpPrimeiro()
    {
        return pPrimeiro;
    }
    Elemento<TL>* getpAtual()
    {
        return pAtual;
    }
};
