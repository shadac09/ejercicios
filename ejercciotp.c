/*
1. Escribir un código que a través de un menú me llene dos vectores de 10 posiciones
cada uno con números al azar entre 20 y 35 la primer opción del menú debe mostrarme
estos vectores y cuantos datos se repiten en cada uno.

2. La segunda opción debe mostrarme estos números al azar pero sin que los datos se repitan.

3. Me debe mostrar la unión entre ambos vectores.

4. La siguiente opción me debe mostrar la intersección entre ambos vectores.

5. La siguiente opción me debe mostrar la resta de los elementos del primer ve0ctor menos el segundo.

6. La ultima opción resta del segundo vector menos el primer vector


*/
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#define C 2
#define F 10
#define U 15
/*
11. Desarrollar un algoritmo que cargue un array de dos dimensiones con números
enteros, luego pida una posición X,Y y muestre por pantalla el dato
correspondiente.

*/

void cargavec(int [F][C],int,int);
void mostrarvec(int [F][C],int,int);
void mostrarrepetidos(int [F][C],int [F],int [F],int ,int);
void mostrarnorep(int [F][C],int [F],int [F],int );
void mostrardiagp(int [F][C]);
void mostrarunion(int [F][C], int [],int );
void mostrarinterseccion(int [F][C], int [],int );
void mostraresta( int [F][C], int [], int , int);
int mostrarmenu(void );

int main()
{

   int filas=10,columnas=2,x,y,opcion;
   int matris[F][C]={0};
   int vectorrep1[F]={0},vectorrep2[F]={0},vectornorep1[F]={0},vectornorep2[F]={0};
   int vectorv1v2[F]={0} ,vectorv2v1[F]={0},vectorunion[U]={0},vectorinter[F]={0};
   char eleccion='s';




  srand(time(NULL));//Semilla para numeros aleatorios

//CARGA EL VECTOR CON ELEMENTOS ALEATORIOS
//-------------------------------------------------------------------------------------

/*printf("\n Ingrese el numero de FILAS de la matriz : \n");
scanf("%d",&filas);
if(filas>10)  //Defino el maximo de filas de la matriz
filas=10;

printf("\n Ingrese el numero de COLUMNAS de la matriz : \n");
scanf("%d",&columnas);
if(columnas>10)  //Defino el maximo de columnas de la matriz
columnas=10;
*/
cargavec(matris,F,C);     //carga el vector con num aleatorios
//-------------------------------------------------------------------------------------
do{

opcion = mostrarmenu();

switch(opcion)
{
case 1:
    mostrarvec(matris,F,C);   //Muestra el vector cargado
    break;
case 2:
    mostrarrepetidos( matris,vectorrep1,vectorrep2,F,C);
    break;
case 3:
    mostrarnorep( matris,vectornorep1,vectornorep2,F);
    break;
case 4:
    mostrarunion(matris,vectorunion,F);
    break;
case 5:
   mostrarinterseccion(matris,  vectorinter, F);
    break;
case 6:
    mostraresta( matris, vectorv1v2,F,0 );
    break;
case 7:
    mostraresta( matris, vectorv2v1,F,1 );
    break;
case 8:
  eleccion='n';
  break;
}

}while(eleccion=='S' || eleccion=='s');


}
//-------------------------------------------------------------------------------------
void cargavec(int matris[][C],int filas,int columnas)
 {
  int i,u;
  //printf("Ingrese la cantidad de elementos a ingresar");


    for(i=0;i<filas;i++)
    {
     for(u=0;u<columnas;u++)
    {

      {matris[i][u]=(rand()%(15+u))+19;}
       // vector[i][u]=rand()%(100+u);
       }
    }
 }
//-------------------------------------------------------------------------------------
 void mostrarvec( int matris[][C],int filas,int columnas)
 {
  int i,t;
     printf("\t--------VECTORES---------\n");
 //   printf("\t-----------------------------------------------------\n");
    printf("\t      VECTOR 1\t   VECTOR 2\n");
  for(i=0;i<filas;i++)
    {

     if(t%columnas==0)
     {printf("\n");
    }

     for(t=0;t<columnas;t++)
    {
     printf("\t\t%d",matris[i][t]);
    // if(i%10==0)
    // printf("\n");
    }
    }
 }
//-------------------------------------------------------------------------------------
void mostrarrepetidos( int matris[][C],int vector1[],int vector2[], int filas,int columnas)
 {
     int i,x,j,t=0,aux;
   //  printf("\n estoy aqui\n");


   for( x=0;x<filas;x++)
   {for( i=x+1;i<filas;i++)
    {

    //  if(t%columnas==0)
    //   {printf("\n");
    //   printf("\n");}
    //printf("x:%d  i:%d ",x,i);
      if(matris[x][t] == matris[i][t])      //Busco los repetidos y los guardo en un vector nuevo para la colunma 1
         { vector1[x] = matris[x][t];
           vector1[i] = matris[i][t];
         }

         if(matris[x][t+1] == matris[i][t+1])     //Busco los repetidos y los guardo en un vector nuevo para la colunma 2
         { vector2[x] = matris[x][t+1];
           vector2[i] = matris[i][t+1];
         }
     }

    }
    printf("\t-----ELEMENTOS--REPETIDOS--EN--LOS--VECTORES-----\n");
 //   printf("   -----------------------------------------------------\n");
    printf("      VECTOR 1\t   VECTOR 2\n");

    for(j=0;j<filas ; j++)           //Imprimo el vector en dos columnas
    {
    if( vector1[j]!=0 ){
       printf("\t%d\t",vector1[j]);
    }else  if (vector1[j]==0 )
          {
           printf("\t \t");
          }

     if( vector2[j]!=0)
          {
            printf("\t%d\t\n",vector2[j]);
          } else if ( vector2[j]==0)
          {
           printf("\t \t\n");
          }
    }

    return;
}
//-----------------------------------------------------------------------------------------------------------------------------------
void mostrarnorep(int matris[][C],int vectornorep1[],int vectornorep2[],int filas)
{
   int i,x,j,t=0,z,aux;
   //  printf("\n estoy aqui\n");
   for(z=0;z<filas;z++)     //Copio matrices a vectores
   {
      vectornorep1[z]= matris[z][t];
      vectornorep2[z]= matris[z][t+1];
   }
   //--------------------------------------------------------------------------------------------------------------------------------
   for( x=0;x<filas;x++)
   {for( i=x+1;i<filas;i++)
    {
      if(matris[x][t] == matris[i][t] )      //Si un elemento y el siguiente esta repetido les pongo un cero para la colunma/vector 1
        { vectornorep1[x] = 0;
          vectornorep1[i] = 0;
         }

          if(i==filas && vectornorep1[x]!=0 )  // Si llegue al final de los elementos a comparar y el elemento comparado no tiene el valor cero
          {vectornorep1[x]=matris[x][t]; }     //copio el elemnto de la matris en el vector de los no repetidos

         if(matris[x][t+1] == matris[i][t+1] )    //Si un elemento y el siguiente esta repetido les pongo un cero para la colunma/vector 2
        { vectornorep2[x] = 0;
           vectornorep2[i] = 0;

         if(i==filas && vectornorep2[x]!=0 )   // Si llegue al final de los elementos a comparar y el elemento comparado no tiene el valor cero
          {vectornorep2[x]=matris[x][t+1]; }  //copio el elemnto de la matris en el vector de los no repetidos
        }
    }
    }
    //-----------------------------GRAFICO--------------------------------------------------------------------------------------------
    printf("\t---NO-REPETIDOS-EN-LOS-VECTORES---\n");
  //  printf("  -----------------------------------------------------\n");
    printf("      VECTOR 1\t   VECTOR 2\n");

    for(j=0;j<filas ; j++)           //Imprimo el vector en dos columnas
    {
    if( vectornorep1[j]!=0 ){
       printf("\t%d\t",vectornorep1[j]);  //Si tengo ceros en las posiciones del vector no los imprimo
    }else  if (vectornorep1[j]==0 )
          {
           printf("\t \t");
          }

     if( vectornorep2[j]!=0)
          {
            printf("\t%d\t\n",vectornorep2[j]);
          } else if ( vectornorep2[j]==0)
          {
           printf("\t \t\n");
          }
    }

    return;
}
//-----------------------------------------------------------------------------------------------------------------------------------
 void mostrarunion(int matris[][C] ,int vectorunion[] ,int filas)
 {
   int p=15,t,i,n=0,x,j=0,m=0;  //x:indice del elemento de la posicion de la matris i:indice de la posicion del vectorunion m:0 vector1 1 vector2 n:una copia de x

    for(x=0;x<filas;x++)
     { for(i=0;i<p;i++)
       {//printf("\n EStoy aqui\n");
         //  printf("\n matris[x][t+m]:%d vectorunion[i]:%d i:%d p:%d\n",matris[x][t+m],vectorunion[i],i,p);
        if( matris[x][m] != vectorunion[i])  //Tomo los elementos del vector union , son diferentes a el de la matris?
          {
             //   printf("\n n:%d\n",n);
            for(j=0;j<(x+n);j++)
            {   if(vectorunion[j]!= matris[x][m] && j==(x+n)-1 )
               { vectorunion[x+n] = matris[x][m] ;
                 i=p;
               }else if(vectorunion[j]== matris[x][m])
               { i=p;
                 j=x+n;
                }
            }

        //  printf("\n x:%d m:%d\n",x,m);

          }
       }
      if(x==(filas-1) && m==0 )
       {n=x;
        x=0;
        m++;
        //printf("\n EStoy aqui\n");
       }
    }
//-------------------GRAFICO----------------------------------------------------------------------------------------
printf("\t----UNION-DE-VECTORES----\n");

    for(t=0;t<15 ;t++)           //Imprimo el vector en dos columnas
    {
     if( vectorunion[t]!=0 )
    { printf("\t%d\n",vectorunion[t]);  //Si tengo ceros en las posiciones del vector no los imprimo
    }else  if (vectorunion[t]==0 )
          {
           printf("\t \n");
          }
    }
   return;

 }
//------------------------------------------------------------------------------------------------------------------------------
void mostrarinterseccion(int matris[][C], int vector[],int filas  )
{
    int x,i,j,k,m=0;

    for(k=0;k<filas;k++)   //Recorre el primer vector de los aleatorios
    {
     for( x=0;x<filas;x++)     //Recorre el segundo vector de los aleatorios
     { if(matris[k][m] == matris[x][m+1])
        { for( i=0;i<20;i++) //Recorre el vector donde guardo la interseccion
          {
          if(matris[k][m]  == vector[i] )//Busco los repetidos y los guardo en un vector nuevo para la colunma 1
          { i=20;
            x=filas;
          }else if(matris[k][m]  != vector[i] )
                   {
                    vector[k] = matris[k][m];
                    i=20;
                    x=filas;
                   }
          }
        }
       }
     }

     printf("\t--INTERSECCION--DE-VECTORES----\n");
    for(j=0; j<filas ; j++)
    {//printf("\nvector[x]:%d x:%d\n",vector[x],x);
        if(vector[j]!=0)
        {
            printf("\t%d\n",vector[j]);
        }/* else if(vector[j]==0)
        {
            printf("\t");
        }*/
    }
    return;
}
//------------------------------------------------------------------------------------------------------------------------------
void mostraresta( int matris[][C],int vector[],int filas, int opcion  )//opcion 0 v1-v2 ; 1 v2-v1
{
    int i,m=0;

    if(!opcion)
    { for(i=0;i<filas;i++)
      { vector[i]= matris[i][m] - matris[i][m+1];
      }
    }else if(opcion)
          { for(i=0;i<filas;i++)
            { vector[i]= matris[i][m+1] - matris[i][m];
            }
          }
  printf("\t----RESTA-DE-VECTORES----\n");
    for(i=0; i<filas ; i++)
    {
        if(vector[i]!=0)
        {
            printf("\t%d\n",vector[i]);
        }
    }

  return;
}
//------------------------------------------------------------------------------------------------------------------------------
int mostrarmenu(void )
{
    int opcion=0;
    printf("\n|---------------------------------------------[MENU]-------------------------------------------------|\n");
    printf("|OPCION---> 1[MOSTRAR VECTOR]  2[MOSTRAR REPETIDOS]  3[AL AZAR SIN REPETIDOS] 4[UNION ENTRE VECTORES]| \n");
    printf("|           5[INTERSECION ENTRE VECTORES]  6[RESTA VEC1-VEC2]  7[RESTA VEC2-VEC1] 8[SALIR]           | \n");
    printf("|ELIJA UNA OPCION------------------------------------------------------------------------------------|\n");
    fflush(stdin);
    scanf("%d",&opcion);

    switch (opcion)
    {case 1:return 1;break;
     case 2:return 2;break;
     case 3:return 3;break;
     case 4:return 4;break;
     case 5:return 5;break;
     case 6:return 6;break;
     case 7:return 7;break;
     case 8:return 8;break;
     default:return 0;break;
    }
  return opcion;
}
