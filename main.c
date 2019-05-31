#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>

void portada();
void menu(int estado);
int selection(int mX, int mY);

int main(){

    int xm, ym , verf;

    initwindow(1200,700);
    setbkcolor(0);

        portada();
        getch();

        cleardevice();
        menu(0);

        do{

            //Captura coordenadas x, y hasta que se de click izquierdo.
            getmouseclick(WM_LBUTTONDOWN, xm, ym);

            //Verifica que se halla dado en un boton.
            verf=selection(xm, ym);

        }while(!ismouseclick(WM_LBUTTONDOWN) || verf==0);


    closegraph();



}
