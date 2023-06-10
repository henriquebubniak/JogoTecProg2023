#include "Projetil.h"
#include "Jogo.h"

//Construtora e destrutora
Projetil::Projetil(int f, Vector2f pos, Fase* pf, GerenciadorGrafico* pgg, float vel_x, float vel_y, Jogador* at):
forca(f),
atirador(at),
Entidade(pos, "imagens/projetil.png", pf, pgg, Vector2f(vel_x, vel_y))
{
    setID(2);
}
Projetil::~Projetil() {pfase->rmEntidade(this);}

//Funcionalidades
void Projetil::mover()
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
    delete(this);
}

//Gets
int Projetil:: getForca() const {return forca;}
