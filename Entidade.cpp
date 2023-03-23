#include "Entidade.h"
#include "Fase.h"

//Constutora e destrutora
Entidade::Entidade(Vector2f p, const char* caminhoTextura, Fase* f, GerenciadorGrafico* pgg):
Ente(caminhoTextura, pgg, p), pfase(f)
{}
Entidade::~Entidade() {pfase = nullptr;}

//Sets e gets
void Entidade:: setFase(Fase* f) {pfase = f;}
Vector2f Entidade::getVelocidade() {return Vector2f(0.f,0.f);}