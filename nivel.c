#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
int abrirnivel(void *kemon,void*coin,void *dmonkey,void *pared)
{
    char num[2];
    char cp;
    int ancho=40,alto=44,i=20,j=20;
    //Abriendo el achivo.
    FILE *arch;
    arch=fopen("Nivel.bin", "rb");
    if(arch!=NULL){

        while(!feof(arch)){
            fread(num,sizeof(char),1,arch);
            if(!strcmp(num, "\n")){
                j+=alto;
                i=20;
            }
            if(!strcmp(num,"1")){
                putimage(i,j,coin,COPY_PUT);
            }
            if(!strcmp(num,"2")){
                putimage(i,j,dmonkey,COPY_PUT);

            }
            if(!strcmp(num,"3")){
                putimage(i,j,pared,COPY_PUT);
            }
            i+=ancho;
        }

    }

}
