#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <graphics.h>
void abrirnivel(void *kemon,void*coin,void *dmonkey,void *pared,int mallamov[13][22])
{
    char num[2];
    int ancho=40,alto=44,i=20,j=20,k=0,l=0;
    //Abriendo el achivo.
    FILE *arch;
    arch=fopen("NivelB.txt", "rt");
    printf("\n");

    if(arch!=NULL){
        char n;
        for(k=0;k<13;k++)
        {
            for(l=0;l<22;l++)
            {
                fscanf(arch,"%c",&n);
                mallamov[k][l]=n;
                printf("%c",mallamov[k][l]);
            }
        }
    }
    fclose(arch);
    printf("\n");
    arch=fopen("NivelB.txt", "rt");
    if(arch!=NULL){

        while(!feof(arch)){
            fscanf(arch,"%c",num);

            //if(!strcmp(num, "0")){
            //mallamov[k][l]=0;
            //printf("%d ",mallamov[k][l]);
            //l++;
            //}
            if(!strcmp(num, "\n")){
                j+=alto;
                i=20;
                //k++;
                //printf("\n");
            }
            if(!strcmp(num,"1")){
                putimage(i,j,coin,COPY_PUT);
                /*mallamov[k][l]=1;
                printf("%d ",mallamov[k][l]);
                l++;*/

            }
            if(!strcmp(num,"2")){
                putimage(i,j,dmonkey,COPY_PUT);
                /*mallamov[k][l]=2;
                printf("%d ",mallamov[k][l]);
                l++;*/
            }
            if(!strcmp(num,"3")){
                putimage(i,j,pared,COPY_PUT);
                /*mallamov[k][l]=3;
                printf("%d ",mallamov[k][l]);
                l++;*/
            }

            i+=ancho;

        }

fclose(arch);

}
}
