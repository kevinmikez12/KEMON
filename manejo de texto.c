#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>
#define tam 20
void intextxy(int x,int y,char texto[tam])
{
    char tecla[2];
    int xi=x,yi=y,i=0;
    do
        {
        do
            {
                setcolor(15); //color de letra
                outtextxy(xi,yi,"_");
                delay(100);
                setcolor(0);//color de fondo
                outtextxy(xi,yi,"_");
                delay(100);
            }while(!kbhit());

            tecla[0]=getch(); //se crean solamente 2 campos en el arreglo de tecla,uno para el caracter y otro para el caracter nulo donde termina la cadena
            tecla[1]='\0';
            if(tecla[0]!=8 && tecla[0]!=13)// si es diferente de espacio y enter.
            {
                setcolor(15);
                outtextxy(xi,yi,tecla);
                xi+=textwidth(tecla);
                texto[i++]=tecla[0];
                texto[i]='\0';
            }else
                {
                    if(tecla[0]==8 && i>0)//condicion si se oprime el boton de backspace(borrar)
                    {
                        tecla[0]=texto[--i];
                        tecla[1]=texto[i]='\0';
                        xi-=textwidth(tecla);
                        setcolor(0);
                        outtextxy(xi,yi,tecla);
                    }
                }

        }while(tecla[0]!=13 && i<tam-1);//condicion que se hace cuando aun no es oprimido el enter ni llega el texto a su limite.
}
