#define anchonodo 40
#define altonodo 44

typedef struct nodo{
	struct nodo *arriba;
	struct nodo *abajo;
	struct nodo *izquierda;
	struct nodo *derecha;
	int band;
}NMalla;

NMalla *creanodo();
int insNodo(NMalla **p);
int insNodoSec(NMalla **p, NMalla **q);

/*-------------------- Crea Malla --------------------------------------------------------*/
int creamalla(NMalla **cab){

    NMalla *cabant=NULL; //creamos para poder desplazarnos en el renglon anterior
	//variables de verificacion y ciclos.
	int i, j, v;
	int ren=13, col=22;
		//ren = renglon			Nos sirven para definir los renglones y columnas
		//col = columna			de la mallla.

	//creamalla
	for(i=0; i<ren; i++){
		NMalla *nnodo;			//nnodo nos ayudara a crear un nuevo nodo que se va a ir desplazando hacia abajo.
		nnodo=creanodo();
		for(j=0; j<col-1; j++){
			//separamos la primera lista
			if(i==0){
				v=insNodo( &(*cab) );			//insertamos todos los nodos de una columna

			}
			else{
				v=insNodoSec( &(*cab), &cabant);
			}
		}
		printf("%d",i);
		//despues de que se halla creado los nodos de una columna |cabezad| nos ayuda a crear un nodo
		//que avance hacia abajo para poder crear asi todos los nodos de la siguiente columna.
		if((*cab)->abajo==NULL && i!=ren-1){
			//la condicion nos sirve para saber si se estan creando nodos (cab->abajo==NULL)
			//y no crear un nodo de mas (i!=renglon-1) ya que al ultimo crea un ultimo nodo en la fila pero no sus nodos de la columna.
			(*cab)->abajo=nnodo;	 // se crea el nodo de abajo
			nnodo->arriba=(*cab);		// y se enlaza con el nodo de arriba


			cabant=(*cab);		//dejamos a cabant en el renglon anterior.
			(*cab)=(*cab)->abajo;
			//AVANZAMOS LA CABEZA EN LOS RENGLONES PARA PODER CREAR LOS NODOS DE LAS COLUMNAS.
		}

	}

        return v;
}

NMalla *creanodo(){

	NMalla *nodo;

	nodo = (NMalla *)malloc(sizeof(NMalla));

	if(nodo){
		nodo->abajo=NULL;
		nodo->izquierda=NULL;
		nodo->derecha=NULL;
		nodo->arriba=NULL;
	}

	return nodo;
}


int insNodo(NMalla **k){

	NMalla *nuevo;
	int cont=0;

	nuevo=creanodo();

	if(nuevo){

		if(*k==NULL){
			*k=nuevo;
			cont++;
		}
		else{
			NMalla *a, *b;

			for(a=b=*k; a; b=a, a=a->derecha);

			if(a==NULL){
				b->derecha=nuevo;
				nuevo->izquierda=b;
				cont++;
			}
		}

	}

	return cont;

}

int insNodoSec(NMalla **cr, NMalla **ra){		//NMalla **cr nos apunta a la cabeza del renglon
												//NMalla **ra nos ayudara como el apuntador que recorre el renglon anterior para poder asi
	NMalla *nuevo;								//			 a enlazar la parte de arriba con la de abajo.
	nuevo=creanodo();

	int cont=0;
	if(nuevo){

		//En esta parte no verificamos si la cabeza del reglon esta vacia puesto que ya la creamos
		//en el ciclo for de la funcion main.
		NMalla *a, *b, *M;
		//	a y b nos ayudaran a desplazarnos para encontrar el ultimo nodo en el renglon que queremos poner el nuevo nodo
		//	M nos ayudara para moverse en el renglon anterior para asi poder enlazar los nodos de arriba a abajo
		for(a=b=*cr, M=*ra; a; b=a, a=a->derecha, M=M->derecha);
		//Con el ciclo nos movemos primero los del renglon actual (a - b) y despues el renglon anterior (M)

		if(a==NULL){
			//Enlazamos horizontalmente.
			b->derecha=nuevo;
			nuevo->izquierda=b;
			//Enlazamos verticalmente.
			nuevo->arriba=M;
			M->abajo=nuevo;

			cont++;
		}
	}

	return cont;
}

/*------------------------ Prueba Malla ---------------------------------------------------*/

void testmalla(NMalla **cab, int *inix, int *iniy,void *kemon){
    // tam  sprite ancho 20 y alto 20
    int t,cx=0,cy=0;
    cx=*inix;
    cy=*iniy;
    if( kbhit() ){

        t=getch();
        if(t==77 && (*cab)->derecha && (*cab)->derecha->band<=1){ /*Movimiento hacia derecha*/
            *inix+=anchonodo;
            (*cab)=(*cab)->derecha;
            setfillstyle(1,BLACK);
            bar(cx,cy,cx+40,cy+44);
        }
        if(t==75 && (*cab)->izquierda && (*cab)->izquierda->band<=1){  /*Movimiento hacia Izquierda*/

            *inix-=anchonodo;
            (*cab)=(*cab)->izquierda;
            setfillstyle(1,BLACK);
            bar(cx,cy,cx+40,cy+44);
        }
        if(t==80 && (*cab)->abajo && (*cab)->abajo->band<=1){ /*Movimiento hacia Abajo*/

            *iniy+=altonodo;
            (*cab)=(*cab)->abajo;
            setfillstyle(1,BLACK);
            bar(cx,cy,cx+40,cy+44);
        }
        if(t==72 && (*cab)->arriba && (*cab)->arriba->band<=1){ /*Movimiento hacia Arriba*/

            *iniy-=altonodo;
            (*cab)=(*cab)->arriba;
            setfillstyle(1,BLACK);
            bar(cx,cy,cx+40,cy+44);
        }

    }
putimage(*inix,*iniy,kemon,COPY_PUT);

}

void abrirnivel(void *kemon,void*coin,void *dmonkey,void *pared,NMalla **cab)
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
