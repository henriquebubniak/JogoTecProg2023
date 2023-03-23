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
            listaMorte.push_back(*i);
        }
    }
    for (i = listaMorte.begin(); i != listaMorte.end(); i++)
        (*i)->morrer();
    listaMorte.clear();
}

//Sets e gets
void GerenciadorDeColisoes:: setListaEntidades(list<Entidade*>* ent) {entidades = ent;}


/*
void GerenciadorDeColisoes:: setListaProjeteis(list<Projetil*>* proj)
{

    projeteis = proj;
}

void GerenciadorDeColisoes:: testaColisoesProjeteis()
{

     * 1- Criar dois iteradores, um para a lista de entidades e outro para a lista de projeteis
     *
     *  2- Testar se houve colis�o
     *
     *  3- Em caso positivo, testar se a entidade eh viva ou nao (pode sofrer dano)
     *
     *  4- Caso o seja, aplicar o dano.
     

    list<Projetil*> plista_rm;
    list<Entidade*>::iterator ent;
    list<Projetil*>::iterator proj;
    list<Projetil*>::iterator proj_rm;
    if (projeteis != NULL)
    {
        for (proj = projeteis->begin(); proj != projeteis->end(); proj++)
        {
            for (ent = entidades->begin(); ent != entidades->end(); ent++)
            {
                if((*proj)->get_GlobalBounds().intersects((*ent)->get_GlobalBounds()))
                {
                    (*ent)->dano((*proj)->get_forca());
                    plista_rm.push_back(*proj);
                    pGerenciadorGrafico->removeEnte(static_cast<Ente*>(*proj));
                    break;
                }
            }
        }
        proj_rm = plista_rm.begin();

        while(proj_rm != plista_rm.end())
        {
            projeteis->remove(*proj_rm);
            proj_rm++;
            //delete(*prev(proj_rm, 1));
        }
    }

}

void GerenciadorDeColisoes:: testaColisoesObstaculos ()
{
    list<Entidade*>::iterator ent;
    list<Obstaculo*>::iterator obst;

    list<Obstaculo*> lista_rm;
    list<Obstaculo*>::iterator obst_rm;

    if (obstaculos != NULL)
    {
        for (obst = obstaculos->begin(); obst != obstaculos->end(); obst++)
        {
            for (ent = entidades->begin(); ent != entidades->end(); ent++)
            {
                if((*obst)->get_GlobalBounds().intersects((*ent)->get_GlobalBounds()))
                {
                    (*obst)->aplica_efeito(*ent);

                    if(!((*obst)->get_tipo())){

                            lista_rm.push_back((*obst));
                            pGerenciadorGrafico->removeEnte(static_cast<Ente*>(*obst));
                    }

                    break;
                }
                else
                {
                    (*ent)->set_velmaxpersonagem();
                }
            }
        }

        obst_rm = lista_rm.begin();

        while(obst_rm != lista_rm.end()){

            obstaculos->remove(*obst_rm);
            obst_rm++;
            //delete(*prev(obst_rm, 1));
        }

    }
}
*/