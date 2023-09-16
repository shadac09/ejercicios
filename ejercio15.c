#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#define TRIM 3   //el numero de filas para registro de cada alumno debe ser multiplo de 3
#define MAT 6
/*
Desarrollar un algoritmo que cargue una matriz que representa las notas de un alumno
determinado teniendo en cuenta que las filas representa nlas materias y las columnas
los trimestres

Se pide:
Promedio de cada una de las materias.
Porcentaje de materias aprobadas.
Promedio general.
 */

void cargarnotas(int [TRIM][MAT],int , int,int );
void mostrarnotas(int [TRIM][MAT],int ,int ,float [MAT],char ,float [],int );
void sacarpromedios(int [TRIM][MAT],float [MAT],float [], int ,int);

int main()
{

int matriznotas[TRIM][MAT],indicenombres=0,seleccion=0;
float promedios[MAT]={0},porcaprob[TRIM]={0};
char vectornombres[10]=" ",nombre,opcion='S';


 srand(time(NULL));//Semilla para numeros aleatorios

while(opcion=='S'|| opcion=='s')
{

printf("\t---------------------------------------[ELIJA UNA OPCION]----------------------------------------\n") ;
printf("\t----[0 Ingresar nombre de alumno]-------[1 Ver Notas-Promedios]---------[2 Salir]------------\n\n") ;
scanf("%d",&seleccion);

    switch(seleccion)
    {
    case 0 :
        system("cls");
        printf("Ingrese los Nombres del Alumno\n");
        scanf("%s",&nombre);
        carganotas(matriznotas,TRIM,MAT,indicenombres);
        indicenombres++;
        break;
    case 1:
        sacarpromedios(matriznotas,promedios,porcaprob,TRIM,MAT);
      //  printf("\naqui");
        mostrarnotas( matriznotas,TRIM ,MAT,promedios,nombre,porcaprob, indicenombres );
        break;
    case 2:
        printf("Saliendo...........\n");
        opcion='N';
        break;
    }
}

}

void carganotas(int matris[][MAT],int filas,int columnas,int indicenombres )
 {
  int i,u;

  for(i=0+indicenombres*3;i<filas;i++)                      //Filas
  {
     for(u=0;u<columnas;u++)                //Columnas
    {
      if(u==0)
      {
        matris[i][0]=indicenombres;
      }else if(u>0)
           {
            matris[i][u]=rand()%(6+u)+1;
            // vector[i][u]=rand()%(100+u);
            //prom[i] = prom[i]+ matris[i][k];
            //printf("prom[i]:%f i:%d k:%d\n",prom[i],i,k);
          //prom[i] = prom[i]/5;
            }
    }
  }
 }


 void sacarpromedios(int matris[][MAT],float promedios[MAT],float porcaprob[TRIM],int filas,int columnas)
 {
  int j,k,z,contaux=0;

  for(j=0;j<filas;j++)                      //Filas de la matriz promedios
  {  contaux=0;
     for(k=1;k<columnas;k++)                //Columnas de la matriz promendios
    {  // z= matris[j*3][0] ;                                                              // en la primera columna de matriz llevo el indice del alumno 0,1,2 que lo relaciona con el nombre
      promedios[k]=promedios[k]+matris[j][k];   //matris[j*3][0]; en los primeros tres elementos de las notas de cada alumno se repite el indice
     if(j==filas-1)
     {
      promedios[k] = promedios[k]/3 ;//El promedio final guardado
     }
     if(matris[j][k]>=6)
        { contaux++;
        }
    }
   porcaprob[j]=(contaux*100)/5;

  }
  return;

  }


  void mostrarnotas( int matris[][MAT],int filas,int columnas, float promedios[MAT],char nombres,float porcaprob[TRIM], int indicenombres)
 {
  int i,t,x,indicetemp=0;
  float promgral=0;
//printf("\naqui");
  while( indicetemp<indicenombres)
  {
        printf("ALUMNO : %c \n",nombres);//*(vectornombres+10*indicenombres)
        printf("\n\t\t   [Matematica]  |   [Lengua]    |    [Ingles]    |  [Geografia]  |  [Biologia]  |\n\n");


    for(i=0;i<filas;i++)                      //Filas de la matriz
    {
        printf("\n[Trimestre%d]\t",i+1);
    // if(t%columnas==0)
    // {printf("\n");
    // printf("\n");}

        for(t=1;t<columnas;t++)                 //Columnas de la matriz arranco de 1,la posicion 0 de las columnas de la matris tienen el indice
        {
         printf("\t %d    \t",matris[i][t]);
        }
        if(t==columnas)
        {printf("\n") ; }
    }

    printf("\nPromedios  \t");

    for(x=0;x<indicenombres;x++)                       //FILAS
    { for(i=1;i<MAT;i++)                   //COLUMNAS
      {
          printf("   |   %0.2f    |",promedios[i]);
          promgral= promgral + promedios[i];
      }
    }
    printf("\nPromedio General: %f \n",promgral/5);

    for(t=0;t<filas;t++)
     {
      printf("Porcentaje aprobadas Trim%d:%.01f\n",t+1, porcaprob[t]);
     }
    indicetemp++;
  }
  return;
}

