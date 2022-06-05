#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <malloc.h>
#include <assert.h>

int imprime(int array[], int n);
int imprime2(int array[], int n);
int igualarray(int array[], int aux[], int n); 
typedef int DataType; 
typedef int(*Compare)(const void *a, const void *b); 
int ascenso(const void *a, const void *b); 
int descenso(const void *a, const void *b); 
void HeapSort(DataType *array, int size, Compare cmp); 





int main(){
    int val[50], aux[50], n, i, r=0, clave, l, j;

    printf("Escribe el numero de elementos: "); scanf("%d", &n);
    for(i=0; i<n; i++){
        printf("\t elem[%d]: ", i+1); scanf("%d", &val[i]);
    }
    igualarray(val, aux, n);

    	printf("Tu arrelgo es: "); 	imprime(aux, n);
        igualarray(aux, val, n);

           
            printf("\n\n--> Ordenamiento heapsort <--\n");
            sleep(2);
            imparray2(val, n);
            HeapSort(val, n, descenso);
            
    printf("fin del programa. ");
    system("pause");        
    return 0;
}

int igualarray(int array[], int aux[], int n){
    int i;
    for(i=0; i<n; i++){
        aux[i]=array[i];
    }
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



void HS_swap(DataType *a, DataType *b)
{
    DataType temp = *a;
    *a = *b;
    *b = temp;
}


int ascenso(const void *a, const void *b)
{
    return *(DataType*)a - *(DataType*)b;
}

 
int descenso(const void *a, const void *b)
{
    return *(DataType*)b - *(DataType*)a;
}

void HS_Adjust(DataType *array, int size, int parent, Compare cmp)
{
    int child = parent * 2 + 1;
    assert(array);

    while (child < size)
    {
        if ((child + 1) < size && cmp(&array[child], &array[child + 1]) > 0)
        {
            child += 1;
        }
        if (array[parent] < array[child])
        {
            HS_swap(&array[parent], &array[child]);
            parent = child;
            child = parent * 2 + 1;
        }
        else
        {
            return;
        }
    }
}


void HeapSort(DataType *array, int size, Compare cmp){
    int end = size - 1;
    // 1. construir montaña
    int root = ((size - 1) - 1) >> 1;
    for (; root >= 0; --root)
    {
        HS_Adjust(array, size, root, cmp);
    }
    // 2. Ordenar
    while (end)
    {
        HS_swap(&array[0], &array[end]);
        HS_Adjust(array, end, 0, cmp);
        --end;
        imparray2(array, size);
    }
}


