#include "Jogo.h"

//Construtora e destrutora
Jogo::Jogo():
gg(),
menu(&gg, &fase1, &fase2),
fase1(&gg, &telaMorte, &fase2),
telaMorte(&gg, &fase1),
fase2(&gg, &telaMorte)
{
    menu.setAtivo(true);
    executar();
}
Jogo::~Jogo()
{}


void Jogo::executar()
{
    while (gg.get_JanelaAberta())
    {
        Event event;
        while (gg.pega_evento(&event))
            if (event.type == Event::Closed)
                gg.fecha_janela();
        gg.limpaJanela();

        if(menu.getAtivo())
            menu.executar();
        else if(fase1.getAtivo())
            fase1.executar();
        else if(fase2.getAtivo())
            fase2.executar();
        else if(telaMorte.getAtivo())
            telaMorte.executar();
            
        gg.atualizaJanela();
    }
}