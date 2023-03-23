#include "Fase1.h"

Fase1::Fase1(GerenciadorGrafico* pgg, Menu* m):
Fase(pgg, m),
gravidade(2),
plataforma1(Vector2f(0.f,1450.f), "./imagens/plataforma1.png", static_cast <Fase*> (this), pgg),
plataforma2(Vector2f(1600.f,1300.f), "./imagens/plataforma2.png", static_cast <Fase*> (this), pgg),
plataforma3(Vector2f(1700.f,1450.f), "./imagens/plataforma3.png", static_cast <Fase*> (this), pgg),
fundoFase1("./imagens/fundoFase1.png"),
jogador1(Vector2f(0.f,0.f), "./imagens/jogador1.png", static_cast <Fase*> (this), pgg, 10, 0.1, &jogador2),
jogador2(Vector2f(300.f,0.f), "./imagens/jogador2.png", static_cast <Fase*> (this), pgg, 10, 0.1, &jogador1)
{
    adEnte(&fundoFase1);
}

void Fase1::adicionaJogador(int n)
{
    jogador1.setPosicao(Vector2f(0.f,0.f));
    jogador2.setPosicao(Vector2f(300.f,0.f));
    if (n == 1)
    {
        list<Entidade*>::iterator i = find(listaEntidade.begin(), listaEntidade.end(), static_cast<Entidade*> (&jogador1));
        jogador1.setVivo(true);
        jogador1.setHp(10);
        if (i == listaEntidade.end())
        {
            cout << "adiciona jogador1" << endl;
            adEntidade(static_cast <Entidade*> (&jogador1));
        }
    }
    if (n == 2)
    {
        list<Entidade*>::iterator i = find(listaEntidade.begin(), listaEntidade.end(), static_cast<Entidade*> (&jogador1));
        list<Entidade*>::iterator j = find(listaEntidade.begin(), listaEntidade.end(), static_cast<Entidade*> (&jogador2));
        jogador1.setVivo(true);
        jogador1.setHp(10);
        jogador2.setVivo(true);
        jogador2.setHp(10);
        if (i == listaEntidade.end() && j == i)
        {
            cout << "adiciona jogador1 e jogador2" << endl;
            adEntidade(static_cast <Entidade*> (&jogador1));
            adEntidade(static_cast <Entidade*> (&jogador2));
        }
    }
}
void Fase1::adicionaPlataformas()
{
    adEntidade(static_cast <Entidade*> (&plataforma1));
    adEntidade(static_cast <Entidade*> (&plataforma2));
    adEntidade(static_cast <Entidade*> (&plataforma3));
}

float Fase1::getG() {return gravidade;}