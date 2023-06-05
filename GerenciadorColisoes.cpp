#include "GerenciadorColisoes.h"
#include "GerenciadorGrafico.h"

//Construtora e destrutora
GerenciadorDeColisoes:: GerenciadorDeColisoes(list<Entidade*>* ple, GerenciadorGrafico* pgg)
{
    entidades = ple;
    pGerenciadorGrafico = pgg;
}
GerenciadorDeColisoes:: ~GerenciadorDeColisoes()
{}

//Funcionalidades
void GerenciadorDeColisoes:: testaColisoes() {testaColisoesEntidades();}
void GerenciadorDeColisoes:: testaColisoesEntidades ()
{
    list <Entidade*> listaMorte;
    list<Entidade*>::iterator i;
    list<Entidade*>::iterator j;
    for (i = entidades->begin(); i != entidades->end(); i++)
    {
        for (j = next(i, 1); j != entidades->end(); j++)
        {
            FloatRect proxPosEntidade1, posEntidade1, posEntidade2;
            float componente;
            posEntidade1 = (*i)->getGlobalBounds();
            proxPosEntidade1 = (*i)->getGlobalBounds();
            proxPosEntidade1.left += ((*i)->getVelocidade()).x;
            proxPosEntidade1.top += ((*i)->getVelocidade()).y;
            posEntidade2 = (*j)->getGlobalBounds();
            if (proxPosEntidade1.intersects(posEntidade2))
            {
                testaColisaoPersonagemProjetil(i, j, &listaMorte);
                if (proxPosEntidade1.left < posEntidade2.left)
                {
                    if (proxPosEntidade1.top < posEntidade2.top && proxPosEntidade1.top + proxPosEntidade1.height < posEntidade2.top + posEntidade2.height)
                    {
                        if (proxPosEntidade1.left + proxPosEntidade1.width - posEntidade2.left <= proxPosEntidade1.top + proxPosEntidade1.height - posEntidade2.top) //Colisao a esquerda
                        {
                            (*i)->setVelocidadeX (0.f);
                            (*i)->setPosicao (Vector2f(posEntidade2.left - posEntidade1.width, posEntidade1.top));
                            (*j)->setVelocidadeX (0.f);
                            (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                        }
                        else //Colisao acima
                        {
                            (*i)->setVelocidadeY (0.f);
                            (*i)->setPosicao(Vector2f(posEntidade1.left, posEntidade2.top - posEntidade1.height));
                            (*j)->setVelocidadeY (0.f);
                            (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                            (*i)->setPodePular (true);
                            (*j)->setPodePular (true);
                        }
                    }
                    else if (proxPosEntidade1.top + proxPosEntidade1.height > posEntidade2.top + posEntidade2.height && proxPosEntidade1.top > posEntidade2.top)
                    {
                        if (proxPosEntidade1.left + proxPosEntidade1.width - posEntidade2.left <= posEntidade2.top + posEntidade2.height - proxPosEntidade1.top) //Colisao a esquerda
                        {
                            (*i)->setVelocidadeX (0.f);
                            (*i)->setPosicao (Vector2f(posEntidade2.left - posEntidade1.width, posEntidade1.top));
                            (*j)->setVelocidadeX (0.f);
                            (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                        }
                        else //Colisao abaixo
                        {
                            (*i)->setVelocidadeY (0.f);
                            (*i)->setPosicao(Vector2f(posEntidade1.left, posEntidade2.top + posEntidade2.height));
                            (*j)->setVelocidadeY (0.f);
                            (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                        }
                    }
                    else //Colisao a esquerda
                    {
                        (*i)->setVelocidadeX (0.f);
                        (*i)->setPosicao (Vector2f(posEntidade2.left - posEntidade1.width, posEntidade1.top));
                        (*j)->setVelocidadeX (0.f);
                        (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                    }
                }
                else if (proxPosEntidade1.left + proxPosEntidade1.width > posEntidade2.left + posEntidade2.width)
                {
                    if ((proxPosEntidade1.top < posEntidade2.top) && (proxPosEntidade1.top + proxPosEntidade1.height < posEntidade2.top + posEntidade2.height))
                    {
                        if (posEntidade2.left + posEntidade2.width - proxPosEntidade1.left <= proxPosEntidade1.top + proxPosEntidade1.height - posEntidade2.top) //Colisao a direita
                        {
                            (*i)->setVelocidadeX (0.f);
                            (*i)->setPosicao(Vector2f(posEntidade2.left + posEntidade2.width, posEntidade1.top));
                            (*j)->setVelocidadeX (0.f);
                            (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                        }
                        else //Colisao acima
                        {
                            (*i)->setVelocidadeY (0.f);
                            (*i)->setPosicao(Vector2f(posEntidade1.left, posEntidade2.top - posEntidade1.height));
                            (*j)->setVelocidadeY (0.f);
                            (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                            (*i)->setPodePular (true);
                            (*j)->setPodePular (true);
                        }
                    }
                    else if ((proxPosEntidade1.top > posEntidade2.top) && (proxPosEntidade1.top + proxPosEntidade1.height > posEntidade2.top + posEntidade2.height))
                    {
                        if (posEntidade2.left + posEntidade2.width - proxPosEntidade1.left <= posEntidade2.top + posEntidade2.height - proxPosEntidade1.top) //Colisao a direita
                        {
                            (*i)->setVelocidadeX (0.f);
                            (*i)->setPosicao(Vector2f(posEntidade2.left + posEntidade2.width, posEntidade1.top));
                            (*j)->setVelocidadeX (0.f);
                            (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                        }
                        else //Colisao abaixo
                        {
                            (*i)->setVelocidadeY (0.f);
                            (*i)->setPosicao(Vector2f(posEntidade1.left, posEntidade2.top + posEntidade2.height));
                            (*j)->setVelocidadeY (0.f);
                            (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                        }
                    }
                    else //Colisao a direita
                    {
                        (*i)->setVelocidadeX (0.f);
                        (*i)->setPosicao(Vector2f(posEntidade2.left + posEntidade2.width, posEntidade1.top));
                        (*j)->setVelocidadeX (0.f);
                        (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                    }
                }
                else if(proxPosEntidade1.top < posEntidade2.top) //Colisao acima
                {
                    (*i)->setVelocidadeY (0.f);
                    (*i)->setPosicao(Vector2f(posEntidade1.left, posEntidade2.top - posEntidade1.height));
                    (*j)->setVelocidadeY (0.f);
                    (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                    (*i)->setPodePular (true);
                }
                else //Colisao abaixo
                {
                    (*i)->setVelocidadeY (0.f);
                    (*i)->setPosicao(Vector2f(posEntidade1.left, posEntidade2.top + posEntidade2.height));
                    (*j)->setVelocidadeY (0.f);
                    (*j)->setPosicao (Vector2f(posEntidade2.left, posEntidade2.top));
                }
            }
        }
        if ((*i)->getGlobalBounds().top + (*i)->getGlobalBounds().height >= 2560)
        {
            cout << "MORREU POR QUEDA" << endl;
            listaMorte.push_back(*i);
        }
    }
    for (i = listaMorte.begin(); i != listaMorte.end(); i++)
        (*i)->morrer();
    listaMorte.clear();
}

//Sets e gets
void GerenciadorDeColisoes:: setListaEntidades(list<Entidade*>* ent) {entidades = ent;}

void GerenciadorDeColisoes::testaColisaoPersonagemProjetil(list<Entidade*>::iterator i, list<Entidade*>::iterator j, list<Entidade*>* pListaMorte)
{
    if ((((*i)->getID() == 1 || (*i)->getID() == 4) && (*j)->getID() == 2) ||
        ((*i)->getID() == 2 && (*j)->getID() == 1 || (*j)->getID() == 4))//Colisao entre Projetil e Personagem
    {
        if ((*i)->getID() == 1 || (*i)->getID() == 4)
        {
            (*i)->receberDano((*j)->getForca());
            pListaMorte->push_back(*j);
            if ((*i)->getHp() <= 0)
                pListaMorte->push_back(*i);
        }
        else
        {
            (*j)->receberDano((*i)->getForca());
            pListaMorte->push_back(*i);
            if ((*j)->getHp() <= 0)
                pListaMorte->push_back(*j);
        }                    
    }
}