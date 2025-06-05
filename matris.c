#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define C 4
#define F 6
/*
11. Desarrollar un algoritmo que cargue una matriz que representa las notas de un alumnno
determinado teniendo en cuenta que las filas representan las materias y las columnas los
trimenstre
se pide cargar la matriz y el nombre y apellido del alumno y luego informar. Nombre
completo del alumn y el siguiente reporte

Promedio en cada una de las materias
Porcentaje de las materias aprobadas por trimestres nota 6
Promedio general
*/

void cargavec(int [F][C],int,int);
void mostrarvec(int [F][C],int,int);
void mostrarxy(int [F][C],int ,int);
void mostrardiagp(int [F][C]);

int main()
{

   int materias=6,trimestres=4,x,y;
   int matris[F][C];
   char eleccion='n';



  srand(time(NULL));//Semilla para numeros aleatorios

//CARGA EL VECTOR CON ELEMENTOS ALEATORIOS
//-------------------------------------------------------------------------------------



cargavec(matris,materias,trimestres);     //carga el vector con num aleatorios
mostrarvec( matris, materias, trimestres);
//-------------------------------------------------------------------------------------
do{
eleccion='n';
/*
printf("\n Ingrese la posicion X : \n");
scanf("%d",&x);
if(x>columnas)  //la eleccion maxima es la cantidad de columnas de la matriz
x=columnas;

printf("\n Ingrese la posici�n Y : \n");
scanf("%d",&y);
if(y>filas)  // la eleccion maxima es la cantidad de filas de la matriz
y=filas;

mostrarvec(matris,filas,columnas);   //Muestra el vector cargado
mostrarxy(matris,y,x); //Muestra los ceros del vector cargado

printf("\n\nDesea ver la matriz? \n");
fflush(stdin);
scanf("%c",&eleccion);
 if(eleccion=='S' || eleccion=='s')
    {mostrarvec(matris,filas,columnas);
     eleccion='n';}   //Muestra el vector cargado

fflush(stdin);
printf("\n\nDesea ver otro dato? \n");
scanf("%c",&eleccion);
*/
}while(eleccion=='S' || eleccion=='s');


}
//-------------------------------------------------------------------------------------
void cargavec(int matris[][C],int materias,int trimestres)
 {
  int i,u;
  //printf("Ingrese la cantidad de elementos a ingresar");


    for(i=0;i<materias;i++)
    {
     for(u=0;u<trimestres;u++)
    {
      matris[i][u]=rand()%(10+u);
    }
    }
 }
//-------------------------------------------------------------------------------------
 void mostrarvec( int matris[][C],int materias,int trimestres)
 {
  int fil=0,col=0;
    printf("\t[Materias]\n");
    printf("\n\n[Trimestres]");
  for(fil=0;fil<trimestres;fil++)
    {

     if(col%trimestres==0)
     {printf("\n");
     }

     for(col=0;col<materias;col++)
    {

      if(col==0 ||(fil>0 &&  fil<4) )
        {if(fil==0 )
        { printf("\tMatematica\tLengua\tIngles\tGeografia\tBiologia\n");
         fil++;
        }
         if(fil>0 &&  fil<4 && col==0 )
           {
              printf("Trim %d\t",col);
           }
         col++;
        }else if(fil>0)
        {
         printf("\t %d",matris[fil][col]);
         if(col%5==0)
         printf("\n");
        }



    }
    }
 }
//-------------------------------------------------------------------------------------
void mostrarxy( int matris[][C],int y,int x)
 {

  printf("\n\n El dato en la posicion es matriz[%d][%d]---> %d\n\n",x,y,matris[x][y]);

   return;
 }
