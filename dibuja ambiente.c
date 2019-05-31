#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>

#include "malla.h"
#include "lecturasprites.h"

typedef struct{
    int cx, cy;     ///Coordenada del icono.
    NMalla *psnodo; ///Posicion de nodo.
}Ticono;


int imprime_tiempo(int ini,int col_i,int col_f);
void selectmenumalla();
int menu(int estado);
void abrirnivel(void *kemon,void *dmonkey, void *coin, void *pare,NMalla**cab);
void imprime_puntos(int *punt);

void dibujamalla(char texto[])
{
/*----------------------------------------------------------------------------------------------------------------------*/
/**Variables**/
        void *kemon,*Dmonkey,*coin,*pared;
        int tamimg;
        tamimg=imagesize(100,50,140,85);
        kemon=malloc(tamimg);
        coin=malloc(tamimg);
        Dmonkey=malloc(tamimg);
        pared=malloc(tamimg);
        NMalla *cab=creanodo();
        NMalla *priMa=cab;
        NMalla *mmalla=cab;
        creamalla(&cab);
        int ini,xm,ym,v;
        //int cmallaX=20,cmallaY=20;
        v=1;

/*----------------------------------------------------------------------------------------------------------------------*/
/** Pantalla De Carga **/
        setcolor(WHITE);
        SPRITE *abrir;
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
        outtextxy(200, 50,"CARGANDO...");
        abrirSprite(abrir,"Kemon");
        delay(500);
        getimage(100,50,140,85,kemon);
        abrirSprite(abrir,"D'monkey");
        delay(500);
        getimage(100,50,140,85,Dmonkey);
        abrirSprite(abrir,"Coin");
        delay(500);
        getimage(100,50,140,85,coin);
        abrirSprite(abrir,"Pared");
        delay(500);
        getimage(100,50,140,85,pared);
        cleardevice();
/*-----------------------------------------------------------------------------------------------------------------------*/
/** Dibuja Espacio del juego y Boton de Salida como Datos del jugador**/
        setcolor(WHITE);
        rectangle(15,15,905,600);
        rectangle(15,620,209,680);
        setfillstyle(SOLID_FILL,0);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
        outtextxy(940,200,"Vidas:");
        outtextxy(980,250,"3");
        outtextxy(20+35,620+15, "SALIR");
        outtextxy(940,120,"Name:");
        setcolor(YELLOW);
        outtextxy(1065,120,texto);
        abrirnivel(kemon,coin,Dmonkey,pared,&mmalla);
        ini=clock();

        Ticono jugador;
        jugador.psnodo=priMa;
        jugador.cx=20;
        jugador.cy=20;


/*--------------------------------------------------------------------------------------------------*/
/** Ciclo Principal del Juego **/
    int timelose, puntos=50;

    do{
        if(jugador.psnodo->band==1){
            puntos+=50;
            jugador.psnodo->band=0;
        }

        if(jugador.psnodo->band==2){
            puntos-=25;
            jugador.psnodo->band=0;
        }


        timelose=imprime_tiempo(ini,15,0);//da el tiempo y manda una bandera cuando el tiempo acabe
        imprime_puntos(&puntos);

        testmalla(&jugador.psnodo,&jugador.cx,&jugador.cy,kemon);
        getmouseclick(WM_LBUTTONDOWN, xm, ym); //En estas lineas se optiene la coordenada del click y se se cumple se sale del ciclo while.
        if(xm>15 && xm<209 && ym>620 && ym < 680)
        {
            v=0;
        }

      }while(v!=0 && timelose!=1 && puntos!=0);

    ///Libera memoria de la imagen.
    free(kemon);free(coin);free(Dmonkey);
    free(pared);


    cab=NULL;  /// Libera memoria de
    free(cab); /// la mallla.


      ini=clock();
      cleardevice();
      menu(1);
}

