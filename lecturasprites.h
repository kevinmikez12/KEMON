
typedef struct{
    int renglones;
    int columnas;
    int **mtrx;
}SPRITE;

///----------------------------------Abre el sprite de un archivo binario-----------------------------///
int abrirSprite(SPRITE *spr, char nombre[20]){
    char res[20];

    int i, j;
    int ren, col;
    int r[50][50];

    // copia el nombre y le agrega la extension .sprite
    strcpy(res, nombre);
    strcat(res, ".sprite");

    FILE *arch;
    arch = fopen(res, "r");
    if(arch != NULL){
        // Lee el numero de columnas
        fread(&ren, sizeof(int), 1, arch);
        // Lee el numero de renglones
        fread(&col, sizeof(int), 1, arch);

        // va leyendo elemento por elemento del arreglo
        for(i = 0; i < ren; i++){

            for(j = 0; j < col; j++){
                fread(&r[i][j], sizeof(int), 1, arch);
                 setfillstyle(SOLID_FILL,  r[i][j]);
                 bar(100+(1.5*j), 50+(1.5*i), 100+5+(1.5*j), 50+5+(1.5*i)); /*    Carga sprites para captura [getimage] */
            }
        }
        fclose(arch);
        return 1;
    }
    fclose(arch);
    return 0;
}
