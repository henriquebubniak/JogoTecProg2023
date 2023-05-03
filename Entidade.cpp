#include "Entidade.h"
#include "Fase.h"

//Constutora e destrutora
Entidade::Entidade(Vector2f p, const char* caminhoTextura, Fase* f, GerenciadorGrafico* pgg, Vector2f v):
Ente(caminhoTextura, pgg, p), pfase(f), velocidade(v)
{}
Entidade::~Entidade() {pfase = nullptr;}

//Sets e gets
void Entidade:: setFase(Fase* f) 
{
    if (f)
        pfase = f;
    else
        cout << "FASE NULA EM setFase() DE ENTIDADE" << endl;
}
Vector2f Entidade::getVelocidade() {return Vector2f(0.f,0.f);}