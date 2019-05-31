#include <stdlib.h>
#include <stdio.h>
#include <graphics.h>
#include <time.h>

int imprime_tiempo(int ini,int col_i,int col_f)
{

    int act,seg;
    int band=0;


    char reloj[20];
    act=clock();
    seg=(act-ini)/CLK_TCK;
    sprintf(reloj,"TIME:   %d : %d  ",1-seg/60,59-seg%60);
    setfillstyle(1,col_f);
    setcolor(col_i);
    outtextxy(940,40,reloj);

    if(59-seg%60<0)
        return band=1;
}
