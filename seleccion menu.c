#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#define tam 20

void intextxy(int x,int y,char texto[tam]);
void Ayuda();
void Records();
void menu(int estado);
void dibujamalla(char texto[]);
int main(void);

int selection(int mX, int mY){

    char texto[tam];
    int verf,sx,sy;
    sx=getmaxx()/2;
    sy=getmaxy()/2;
/*esta seccion se compone de los rangos de los botones del menu principal y su funcion*/
    if(mX>236 && mX<730 && mY>56 && mY<661){

        if(mY>56 && mY<166){//boton jugar
            cleardevice();
            int xm,ym;
            setcolor(15);
            settextstyle(EUROPEAN_FONT, HORIZ_DIR, 4);
            outtextxy(sx-400,sy,"Ingrese su nombre:");
            intextxy((sx-400)+textwidth("Ingrese su nombre:"),sy,texto); //captura del tamano en X
            cleardevice();
            dibujamalla(texto);
            return 1;
        }

        if(mY>220 && mY<330){// boton Records
           cleardevice();
            int xm,ym;
            Records();
            outtextxy(450,50, "---RECORDS---");
            do{
            getmouseclick(WM_LBUTTONDOWN, xm, ym);
            if(xm >20 && xm<200 && ym>20 && ym<100)
            {
            cleardevice();
            menu(1);
            }
            }
            while(!ismouseclick(WM_LBUTTONDOWN));
            cleardevice();
            menu(1);
            return 0;
        }

        if(mY>385 && mY<495){//Ayuda
            cleardevice();
            int xm,ym;
            Ayuda();
            outtextxy(450,50, "---AYUDA---");
            do{
            getmouseclick(WM_LBUTTONDOWN, xm, ym);
            if(xm >20 && xm<200 && ym>20 && ym<100)
            {
            cleardevice();
            menu(1);
            }
            }
            while(!ismouseclick(WM_LBUTTONDOWN));
            cleardevice();
            menu(1);
            return 0;
        }

        if(mY>550 && mY<660)//Boton Salir
            exit(1);

        return 0;
    }

    else{
        return 0;
    }

}
