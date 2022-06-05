#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <assert.h>

int imprime(int array[], int n);
int imprime2(int array[], int n); 
int imparray(int array[], int n); 

void merge(int array[], int izquierda,int medio,int derecha, int n);
void merge_sort(int array[], int izquierda,int derecha, int n);  
int imparray2(int array[], int n); 


int main(){
    int val[50], aux[50], n, i, clave, l, j;

    printf("Escribe el numero de elementos: "); scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("\t elem[%d]: ", i+1); scanf("%d", &val[i]);
    }
    igualarray(val, aux, n);

    	printf("Tu arrelgo es:\n"); imprime(aux, n);
        igualarray(aux, val, n);
    	
                printf("\n\n--> Ordenamiento mergesort <--\n");
                imprime2(val, n);
                merge_sort(val, 0,n-1, n);

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


void merge_sort(int array[], int izquierda,int derecha, int n){
    int medio;
    if(izquierda<derecha){
        medio=(izquierda+derecha)/2;
        merge_sort(array, izquierda,medio, n);
        merge_sort(array, medio+1,derecha, n);
        merge(array, izquierda,medio,derecha, n);
    }
}

void merge(int array[], int izquierda,int medio,int derecha, int n){
    int h,i,j,b[50],k;
    h=izquierda;
    i=izquierda;
    j=medio+1;
    
    while((h<=medio)&&(j<=derecha)){
        if(array[h]<=array[j]){
            b[i]=array[h];
            h++;
        }
        else
            {
                b[i]=array[j];
                j++;
            }
        i++;
    }
    if(h>medio){
        for(k=j;k<=derecha;k++){
            b[i]=array[k];
            i++;
        }
    }
    else
        {
            for(k=h;k<=medio;k++){
                b[i]=array[k];
                i++;
            }
        }
    for(k=izquierda;k<=derecha;k++){
        array[k]=b[k];
        }
    imparray2(array, n);
}


