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
        Elemento(TE pT = NULL):
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
            if(pP)
                pProximo = pP;
            else
                cout << "pP nulo em Elemento::setProximo" << endl;
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
                return pAtual->pInfo;
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
            cout << "Ponteiro nulo em Lista::incluir()" << endl;
    }
    void limpar()
    {
        Iterador it;
        it = getPrimeiro();
        if(it.getElementoAtual())
        {
            while (it.getProximo() != NULL)
            {
                delete(it.getElementoAtual());
                it++;
            }
            delete(it.getElementoAtual()); 
        }
        pPrimeiro = NULL;
        pAtual = NULL;
    }
    void remover(TL no)
    {
        Iterador it;
        it = getPrimeiro();
        if(it.getElementoAtual())
        {
            if (*(it.getElementoAtual()) == no)
            {
                it.getProximo()->setAnterior(NULL);
                pPrimeiro = it.getProximo();
                delete(it.getElementoAtual());
            }
            
            while(it.getProximo() != NULL)
            {
                if(*(it.getProximo()) == no)
                {
                    it.getElementoAtual()->setProximo(it.getProximo()->getProximo());
                    delete (it.getProximo());
                    it = it.getElementoAtual();
                }

            }

        }
    }
    Elemento<TL>* getpPrimeiro()
    {
        return pPrimeiro;
    }
    Elemento<TL>* getpAtual()
    {
        return pAtual;
    }
};