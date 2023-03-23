#include "Projetil.h"
#include "Jogo.h"

//Construtora e destrutora
Projetil::Projetil(int f, Vector2f pos,  const char* cT, Fase* pf, GerenciadorGrafico* pgg, float vel_x, float vel_y):
forca(f),
Entidade(pos, cT, pf, pgg)
{velocidade = Vector2f(vel_x, vel_y);}
Projetil::~Projetil() {pfase->rmEntidade(this);}

//Funcionalidades
void Projetil::move()
{
    caixa.move(velocidade);
    velocidade.y += pfase->getG() * (0.016);
    velocidade.x *= 0.999;
}
bool Projetil::colide(Entidade* ent)
{
    if (caixa.getGlobalBounds().intersects(ent->getGlobalBounds()))
        return true;
    else
        return false;
}
void Projetil::morrer()
{
    pfase->rmEntidade(static_cast<Entidade*>(this));
    cout << "morreu projetil" << endl;
    pGerenciadorGrafico->removeEnte(static_cast<Ente*>(this));
    cout << "morreu projetil" << endl;
    cout << "morreu projetil" << endl;
    delete(this);
    cout << "morreu projetil" << endl;
}

//Gets
int Projetil:: get_forca() {return forca;}
