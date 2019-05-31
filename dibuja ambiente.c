#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#include <time.h>

#include "malla.h"
#include "lecturasprites.h"

void imprime_tiempo(int ini,int col_i,int col_f);
void selectmenumalla();
int menu(int estado);
int abrirnivel(void *kemon,void *dmonkey, void *coin, void *pared);

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
        creamalla(&cab);
        int ini,xm,ym,v;
        int cmallaX=20,cmallaY=20;
        v=1;

/*----------------------------------------------------------------------------------------------------------------------*/
/** Pantalla De Carga **/
        SPRITE *abrir;
        setcolor(WHITE);
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
        ini=clock();
/*-----------------------------------------------------------------------------------------------------------------------*/
/** Dibuja Espacio del juego y Boton de Salida como Datos del jugador**/
        setcolor(WHITE);
        rectangle(15,15,905,600);
        rectangle(15,620,209,680);
        setfillstyle(SOLID_FILL,0);
        settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 4);
        outtextxy(940,200,"Vidas:");
        outtextxy(980,250,"3");
        outtextxy(940,350,"Monedas:");
        outtextxy(980,400,"4");
        outtextxy(20+35,620+15, "SALIR");
        outtextxy(940,120,"Name:");
        setcolor(YELLOW);
        outtextxy(1065,120,texto);
        abrirnivel(kemon,coin,Dmonkey,pared);
/*--------------------------------------------------------------------------------------------------*/
/** Ciclo Principal del Juego **/

    do{
        imprime_tiempo(ini,15,0);
        testmalla(&priMa,&cmallaX,&cmallaY,kemon);
        getmouseclick(WM_LBUTTONDOWN, xm, ym); //En estas lineas se optiene la coordenada del click y se se cumple se sale del ciclo while.
        if(xm>15 && xm<209 && ym>620 && ym < 680)
        {
            v=0;
        }

      }while(v!=0);
      cleardevice();
      menu(1);
}

