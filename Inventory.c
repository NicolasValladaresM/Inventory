//Nicolas Valladares M

#include <stdio.h>
#include <string.h>


typedef struct Usuario{
	
	int id;
	char usuario[25];
	char clave[20];
	char nombre[20];
	char apellido[20];
	
}US;
typedef struct Producto{

int idp;
int idb;
char nombre[20];
char marca[20];
float precio;
char tipo[20];



	
}PR; 
typedef struct Tipo{
	
	
char nombre[20];
char descripcion[100];
	
}TP;

typedef struct Bodega{
	
	int id;
	char nombre[30];
	char direccion[30];
	PR productos;
	TP tipo_productos;
}BO;





BO crear_bodega (BO a[], int tamanio);
PR crear_producto (PR a[], int tamanio);
void ver_todo (BO a[], int tamanio);
BO marca_productos (BO a[],int tamanio);
TP tipo_producto (TP a);




int main(){
int flag=0,a,flag2=0,h;
int m=1;

int sw;


BO bodegas[m];
fflush( stdin );
 bodegas[0].id=1,
 fflush( stdin );
 strcpy(bodegas[0].nombre,"Bodega 1");
 strcpy(bodegas[0].direccion,"Direccion Bodega numero1");
 bodegas[0].productos.idb=1;
 bodegas[0].productos.idp=10;
 fflush( stdin );
 strcpy(bodegas[0].productos.nombre,"Productos 1");
 strcpy(bodegas[0].productos.marca,"Marcaaa1 ");
 bodegas[0].productos.precio=756.3;
 strcpy(bodegas[0].tipo_productos.nombre,"Productos del tipo 1");
 fflush( stdin );
 strcpy(bodegas[0].tipo_productos.descripcion,"Descripcion de productos del tipo 1");
 fflush( stdin );
  bodegas[1].id=2,
 strcpy(bodegas[1].nombre,"Bodega 2");
 strcpy(bodegas[1].direccion,"Direccion Bodega numero2");
 bodegas[1].productos.idb=1;
 bodegas[1].productos.idp=20;
 fflush( stdin );
 strcpy(bodegas[1].productos.nombre,"Productos numero2");
 strcpy(bodegas[1].productos.marca,"Marcaaaaa2");
 fflush( stdin );
 bodegas[1].productos.precio=6545.3;
 strcpy(bodegas[1].tipo_productos.nombre,"Productos del tipo 2");
 strcpy(bodegas[1].tipo_productos.descripcion,"Descripcion de productos del tipo 2");
 
 
 
 
 


char nombre[20],clave[20];
US verificar;	
printf ("Usuario ");
gets(nombre);
printf ("\nClave ");
gets(clave);

FILE *archivo;

archivo=fopen("personal.txt", "r");
	
	
while (!feof(archivo)){
	
	
	fscanf(archivo, "%d %s %s %s %s", &verificar.id, &verificar.usuario, &verificar.clave, &verificar.nombre, &verificar.apellido);
	fflush( stdin );
	if (strcmp(nombre,verificar.usuario)==0 && strcmp(clave,verificar.clave)==0){
		
		
		flag=1;
		printf (" \n----------------- \n%s %s \n\n", verificar.nombre, verificar.apellido);
		printf ("\nQue hacer?\n");
		int opcion;
		char temp[10];
		
	    do{
		printf (" 1 para agregar una nueva bodega \n 2 para ver productos de una bodega existente \n 3 para ver informacion de todas las bodegas \n 4 para ver las marcas de los productos \n ");
		
	    fgets(temp,10,stdin);
	    opcion=atoi(temp);
		switch (opcion)
		{
		fflush( stdin );
		   int p;
		   int h;
		   int y;	
		   
		   
		   case 1:
			
			
			m=m+1;
			
			crear_bodega(bodegas,m);
		    fflush( stdin );
			
		    break;
		   case 2:
		    
			printf ("A cual bodega quiere ingresar? ");
			int x;
			for(x=1;x<m+2;x++){
				
				printf (" [%d] ", x);
				
			}
			scanf("%d", &y);
			y=y-1;
			if (y<=m && y>=0){
			
			 	printf (" \n Producto N %d  %s  %s  %.2f  ", bodegas[y].productos.idp, bodegas[y].productos.nombre, bodegas[y].productos.marca, bodegas[y].productos.precio);
			 }	
			 else{
			 	
			 	printf ("\nBodega no existe \n");
			 	break;
			 }
			 	
			 
						
			break;
			case 3:
				
			printf ("Informacion de todas las bodegas ");
			ver_todo(bodegas,m);
			fflush( stdin );	
		    break;
			case 4:
			
			marca_productos(bodegas,m);
		    }
		    break;
		    defaul:printf(" Opcion incorrecta ") ;
		    break;
		}while (opcion!=0);
		    
	
}




fclose(archivo);
if(flag==0){
	
	printf(" \nDatos incorrectos\n ");
	return 0;
}
	
	

}

}
BO crear_bodega (BO a[], int tamanio){
	
	
	
	printf ("\nIngrese nombre \n");
	scanf("%s", &a[tamanio].nombre);
	
    printf ("\nIngrese direccion de la bodega\n");
    scanf("%s", &a[tamanio].direccion);
    printf ("Ingrese Id de la bodega ");
	scanf("%d", &a[tamanio].id);
	
    printf ("\nQuiere agregar un producto a la nueva bodega? \n");
	
    int h;
    printf ("1 = Si - 2 = No ");
    scanf("%d", &h);
    
    if (h==1){
    	
    	TP u;
    	tipo_producto(u);
    	
    	printf (" \n Se asignara a la bodega N.%d ", a[tamanio].id);
    	PR f[tamanio];
    	
    	crear_producto(f,tamanio);
		fflush( stdin );
     	strcpy(a[tamanio].productos.nombre,f[tamanio].nombre);   
		 fflush( stdin ); 
    	a[tamanio].productos.idp=f[tamanio].idp;
    	fflush( stdin );
    	strcpy(a[tamanio].productos.marca,f[tamanio].marca); 
    	fflush( stdin );
    	a[tamanio].productos.precio=f[tamanio].precio;
    	
    	
	}
    
	

	
}

PR crear_producto (PR a[], int tamanio){
	
	printf (" \n Ingrese ID del producto ");
    scanf("%d", &a[tamanio].idp);
    printf (" \n Ingrese nombre del producto ");
    scanf("%s", &a[tamanio].nombre);
    printf (" \n Ingrese marca del producto ");
    scanf("%s", &a[tamanio].marca);
    printf (" \n Ingrese precio del producto ");
    scanf("%f", &a[tamanio].precio);
    
    

	
	
}

void ver_todo (BO a[], int tamanio){
	
	int i;
	for (i=0;i<=tamanio;i++){
	
	printf ("\n Bodega numero %d \n %s Tiene \n Producto numero %d LLamados %s De un valor de %.2f \n", a[i].id, a[i].nombre,a[i].productos.idp,a[i].productos.nombre,a[i].productos.precio);
		
	}
	

	
}

BO marca_productos (BO a[],int tamanio){
printf ("\n");
int i=0;

for (i=0;i<=tamanio;i++){
	printf ("%s \n", a[i].productos.marca);
}
 
printf ("\n");




}

TP tipo_producto (TP a){
	
	printf ("\n - Tipo de producto - \n");
    	printf ("\n Ingrese Nombre ");
    	scanf("%s", &a.nombre);
    	printf("\n Ingrese descripcion ");
        scanf("%s", &a.descripcion);
	
}





