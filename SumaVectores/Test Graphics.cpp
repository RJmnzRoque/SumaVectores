#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string>

#define PI 3.1416	//Constante pi

#define limiteX 600
#define limiteY 600


void dibujaVector(int, int, int);
void dibujaComponentes(int, int, int);
void plano();
void menu();

main(){
   int gd = DETECT, gm, color;
   initgraph(&gd, &gm, "C:\\TC\\BGI");  

	//------------------------------------------------------------------------
	//V A R I A B L E S
                                                                 
   int **A;				//Matriz donde se guardaran los vectores
   int i, j, numberVector, factorEscala = 1;
   float magnitud = 0, direccion = 0, tmp = 0;
   int B[2] = {0,0};	//vector resultante

	//------------------------------------------------------------------------

  printf("Ingresa el numero de vectores que quieres sumar:\n");
  fflush(stdin);
  scanf("%d", &numberVector);

	//------------------------------------------------------------------------
	//RESERVAR MEMORIA PARA EL NUMERO DE VECTORES SOLICITADOS
	//------------------------------------------------------------------------

  A = (int **)malloc( sizeof(int*) * numberVector );

  for( i = 0; i < numberVector; i++ ){
    A[i] = (int*)malloc( sizeof(int)* 2 );
  }
	
	//------------------------------------------------------------------------
	//Llenar con zero, toda la matriz para evitar errores
	//------------------------------------------------------------------------
	

  for( i = 0; i < numberVector; i++ ){
    for( j = 0; j < 2; j++ ){
      A[i][j] = 0;  //Acción: de asignar datos al arreglo
    }
  }
  
  	//------------------------------------------------------------------------
  	//Verificacion de memoria
  	//------------------------------------------------------------------------

  if( A == NULL ){
    printf("No se reservo el bloque de memoria...\n");
    exit(1);
  }else{
    for(i = 0; i < numberVector; i++){
    	
    	//------------------------------------------------------------------------
    	//Se solicitan las componentes
    	//------------------------------------------------------------------------
      printf("Ingresa la componente en x del vector %d\n", i + 1);
      fflush(stdin);
      scanf("%d", &A[i][0]);
      printf("Ingresa la componente en y del vector %d\n", i + 1);
      fflush(stdin);
      scanf("%d", &A[i][1]);
    }
  }
  
  	//------------------------------------------------------------------------
	//Suma de todas las componentes, en el vector resultante
	//------------------------------------------------------------------------
	
	
  for( i = 0; i < numberVector; i++ ){
    B[0] += A[i][0];
    B[1] += A[i][1];
  }
  	//------------------------------------------------------------------------
  	//Calculos
  	//------------------------------------------------------------------------
	  magnitud = sqrt( pow(B[0], 2) + pow(B[1], 2));
	  
	  tmp = atan2( B[1], B[0] );  //Angulo en radianes
	  
	  direccion = tmp * (180 / PI); //Angulo en grados
  
  //------------------------------------------------------------------------
  
  if(direccion < 0){
    direccion = direccion + 360;
  }
  
  if(magnitud <= 10){
  	factorEscala = 20;
  }
	
  printf("\nVector resultante => (%d) i + (%d) j\tMagnitud: %.2f\tDireccion: %.2f Grados", B[0], B[1], magnitud, direccion);
   
  plano();	//Dibujar el plano cartesiano
  dibujaComponentes(B[0], B[1], factorEscala);
  dibujaVector(B[0], B[1], factorEscala);
  getch();
  closegraph();
  return 0;
}


void plano(){
	setcolor(RED);
	rectangle(0, 0, limiteX, limiteY);
	
	setcolor(RED);
	line((limiteX / 2), 25, (limiteX / 2), (limiteY - 25));	//Linea y
	setcolor(RED);
	line(25, (limiteY / 2), (limiteX - 25), (limiteY / 2));	//Linea x	
}

void dibujaComponentes(int Xfin, int Yfin, int fE){
	Xfin = limiteX/2 + ( Xfin * fE );
	Yfin = limiteY/2 - ( Yfin * fE);	//Se mueve en sentido contrario
	
	setcolor(BLUE);
	line(limiteX/2, limiteY/2, Xfin, limiteY/2);	//0,0, fin, 0
	setcolor(BLUE);
	line(Xfin, limiteY/2, Xfin, Yfin);				//fin, 0, fin, fin
}

void dibujaVector(int xr, int yr, int fE){
	xr = xr * fE;
	yr = yr * fE;
	
	setcolor(GREEN);
	line(limiteX/2, limiteY/2, limiteX/2 + xr, limiteY/2 - yr);
	outtextxy(limiteX/2 + xr, limiteY/2 - yr, "Vector Resultante");
}

