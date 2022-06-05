#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <assert.h>


int imprime(int array[], int n);
int imprime2(int array[], int n); 
int imparray(int array[], int n); 
int igualarray(int array[], int aux[], int n); 
void intercambiar(int *a, int *b);
int particion(int arreglo[], int izquierda, int derecha, int n) ;
void quicksort(int arreglo[], int izquierda, int derecha, int n); 


int main(){
    int val[50], aux[50], n, i, clave, l, j;

    printf("Escribe el numero de elementos: "); scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("\t elem[%d]: ", i+1); scanf("%d", &val[i]);
    }
    igualarray(val, aux, n);

    	printf("El arreglo  ingresado es: ");
    	imprime(aux, n);
        igualarray(aux, val, n);
        printf("\nVemos graficamente\n");
        imprime2(val, n);
        quicksort(val, 0, n-1, n);
                
    printf("fin del programa. ");
    system("pause");
    return 0;
}

int imprime(int array[], int n){
    int i;
    for(i=0; i<n; i++)
            printf("%d, ", array[i]);
       
    printf("\n");
    system("pause\n Presiona enter para empezar ordenamiento");

    return 0;
}

int igualarray(int array[], int aux[], int n){
    int i;
    for(i=0; i<n; i++){
        aux[i]=array[i];
    }
    return 0;
}

int imprime2(int array[], int n){
	
    int i, j, cont=0;
    for(i=0; i<n; i++){
    	if((i)%n==0 || i==0) {
    		cont=cont+1;
    		printf("\t Paso %d: \n",cont);
		}
        for(j=0; j<array[i]; j++){
        	printf("*");
		}
		printf("\n");
    }
 
    return 0;
}

void intercambiar(int *a, int *b){
  int temporal = *a;
  *a = *b;
  *b = temporal;
}

int particion(int arreglo[], int izquierda, int derecha, int n) {
  int pivote = arreglo[izquierda];
  while (1) {
    while (arreglo[izquierda] < pivote) {
      izquierda++;
    }
    while (arreglo[derecha] > pivote) {
      derecha--;
    }
    if (izquierda >= derecha) {
      return derecha;
    } else {
      intercambiar(&arreglo[izquierda], &arreglo[derecha]);
      izquierda++;
      derecha--;
      imprime2(arreglo, n);
    }
  }
}


void quicksort(int arreglo[], int izquierda, int derecha, int n){
  if (izquierda < derecha) {
    int indiceParticion = particion(arreglo, izquierda, derecha, n);
    quicksort(arreglo, izquierda, indiceParticion, n);
    quicksort(arreglo, indiceParticion + 1, derecha, n);
  }
}




