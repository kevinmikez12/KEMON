/*  Nombre: Kevin Miguel Hernandez Lopez
    Materia: Lenguajes de Programas
    Proyecto: Editor de Sprites */

#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>


void portada()
{

    int centery, centerx;
    int margen[10]={10,10,10,690,1190,690,1190,10,10,10};

    centerx = getmaxx();
    centery = getmaxy();

    setcolor(WHITE);
    setfillstyle(DASHED_LINE,DARKGRAY);
    setlinestyle(SOLID_LINE,1,12);
    fillpoly(5,margen);
    //rectangle(10, 10, 1190, 690);

    /** PORTADA **/
    /* Titulo PACMAN */
    setcolor(YELLOW);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 10);
    outtextxy((centerx/2)-textwidth("KEMON")/2, centery/2-300, "KEMON");

    /* Logo U.A.S.L.P. */
    readimagefile("UASLP.jpg", 60, 60, 360, 360);
    /* Logo Fac. Ingenieria */
    readimagefile("ING.jpg", 850,60,1150,360);

    /* Subtitulo */
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 4);
    outtextxy((centerx/2)-360, (centery/2+200), " !Presiona cualquier boton para continuar ...! ");

    /* Nombre alumnos */
    setcolor(WHITE);
    settextstyle(EUROPEAN_FONT, HORIZ_DIR, 1);
    setlinestyle(SOLID_LINE,1,3);
    rectangle((centerx/2)-180,centery/2-10,centerx/2+230, centery/2+180);
    outtextxy((centerx/2)-145, centery/2, "Kevin Miguel Hernandez Lopez");
    outtextxy((centerx/2)-170, centery/2+30, "Karla Monserrat Gonzalez Palomares");
    outtextxy((centerx/2)-90, centery/2+60, "Estructura de Datos 2");
    outtextxy((centerx/2)-170, centery/2+90, "Prof. Miguel Angel De La Cruz Lopez");
    outtextxy((centerx/2)-145, centery/2+120, "Prof. Edgar Francisco Castillo Barrera");
    outtextxy((centerx/2)-90, centery/2+150, "Semestre 2018 - 2019");
}
