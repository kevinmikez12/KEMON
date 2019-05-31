#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

typedef char string[50];
typedef struct{

    int x, y;
    int x2, y2;


}Boton;

int menu(int estado)
{

    // El tamaño sera constante asi que no es necesario declararlo en la estructura.
    int i=0, xMax, tam=165;
    Boton B[4];
    xMax=getmaxx();
    string texts[4]={"Jugar","Records","Ayuda","Salir"};
    /* Acomodacion y dibujo de los botones */
    for( ; i<4; i++){

        B[i].x = (xMax/3)-((tam/2));
        B[i].y = (tam*i)+(tam/3);

        B[i].x2 = (xMax/3)+(tam*2);
        B[i].y2 = (tam*i)+tam;

        printf("\n [%d] x: %d - y: %d - x2: %d - y2: %d", i, B[i].x, B[i].y, B[i].x2, B[i].y2);
    }

    /* Dibujo de las barras */
    for(i=0; i<4; i++)
    {
        setfillstyle(SOLID_FILL,BLACK);
        bar(B[i].x, B[i].y, B[i].x2, B[i].y2);
        settextstyle(EUROPEAN_FONT, HORIZ_DIR, 5);
        if(i==0){
        outtextxy((xMax/3)+(tam/2)-20,(tam*i)+95 , texts[i]);}
        if(i==1){
        outtextxy((xMax/3)+(tam/2)-60,(tam*i)+95 , texts[i]);}
        if(i==2){
        outtextxy((xMax/3)+(tam/2)-50,(tam*i)+95 , texts[i]);}
        if(i==3){
        outtextxy((xMax/3)+(tam/2)-30,(tam*i)+95 , texts[i]);}
    }


if(estado==0){

    for(i=0; i<4; i++){

        line(B[i].x, B[i].y, B[i].x+(3*tam)-85, B[i].y);             //Lineas cabecera. [up]

        line(B[i].x, B[i].y, B[i].x, B[i].y+(tam)-(tam/3)-5);       //Lineas laterales. [left]

    }

}
else{

    for(i=0; i<4; i++){

        line(B[i].x, B[i].y+tam, B[i].x+(3*tam)-6, B[i].y+tam);             //Lineas cabecera. [up]

        line(B[i].x, B[i].y, B[i].x, B[i].y+(tam)-(tam/3)-5);       //Lineas laterales. [left]

    }

}





}
