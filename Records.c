#include <stdio.h>
#include <stdlib.h>
#include <graphics.h>


void Records()
{
    setfillstyle(SOLID_FILL,DARKGRAY);
    settextstyle(SANS_SERIF_FONT, HORIZ_DIR, 3);
    bar(20,20,200,100);
    outtextxy(50,50, "REGRESAR");

    int MX, MY;
    MX=getmaxx()/2;
    MY=getmaxy()/2;
    char c[2];
    char cp;

    FILE *Records;
    Records=fopen("Records.txt", "rt");
    if(Records==NULL){
        outtextxy(500,500, "No existe archivo");
    }
    else{
        settextstyle(COMPLEX_FONT, HORIZ_DIR, 4);
        int i=0, j=0, tx=150;
        while(!feof(Records)){
            fscanf(Records, "%c", c);
            outtextxy(15+i,150+j,c);
            if(!strcmp(c, "\n")){
                setcolor(WHITE);
                j+=25;
                i=0;
            }
            tx=textwidth(c);
            i+=tx;
        }

    }

}

