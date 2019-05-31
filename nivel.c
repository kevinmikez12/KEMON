#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>

typedef struct nodo{
	struct nodo *arriba;
	struct nodo *abajo;
	struct nodo *izquierda;
	struct nodo *derecha;
	int band;
}NMalla;

void abrirNivel(void *kemon,void*coin,void *dmonkey,void *pared,NMalla **cab)
{
    FILE *arch;
    NMalla *auxd=*cab;
    NMalla *auxb=*cab;
    char num[2];
    int ancho=40,alto=44,i=20,j=20;
    //Abriendo el achivo
    arch=fopen("Nivel.bin", "rb");
    if(arch!=NULL){

        while(!feof(arch)){
            fread(num,sizeof(char),1,arch);

            if(!strcmp(num, "\n")){
                j+=alto;
                i=20;
                auxb=auxb->abajo;
                auxd=auxb;
            }
            if(!strcmp(num, "0")){
                auxd->band=0;
            }
            if(!strcmp(num,"1")){
                putimage(i,j,coin,COPY_PUT);
                auxd->band=1;
            }
            if(!strcmp(num,"2")){
                putimage(i,j,dmonkey,COPY_PUT);
                auxd->band=2;

            }
            if(!strcmp(num,"3")){
                putimage(i,j,pared,COPY_PUT);
                auxd->band=3;
            }
            auxd=auxd->derecha;
            i+=ancho;
        }

    }

}
