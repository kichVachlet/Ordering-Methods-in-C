

#include <stdio.h>
#include <stdlib.h>

#define N 100

void ordSeleccion(int a[], int n);
void imprimirLista(int a[], int n);
void entradaLista(int a[], int n);
void intercambiar(int *a, int *b);

int main(int argc, char *argv[]) {
	
	int n;
	int v[N];
	
	do{
		printf("\nIntroduzca el numero de elementos: ");
		scanf("%d", &n);
	}while((n<1) && (n>N));
	int aux[n];
	
	entradaLista(v,n);
	
	printf("\nLista original de %d elementos es: ",n);
	imprimirLista(v,n);

	printf("\ngraficamente tenemos: \n"); 
	imprime2(v, n);
	
	
    ordSeleccion(v, n);
    printf("\nLa lista ordenada es\n");
    imprimirLista(v,n);
	 
	system("pause");
	return 0;
}


int imprime2(int array[], int n){
	
    int i, j, cont=0;
    for(i=0; i<n; i++){
    	if((i)%n==0 || i==0) printf("\t Paso: \n");
		
        for(j=0; j<array[i]; j++){
        	printf("*");
		}
		printf("\n");
    }
 
    return 0;
}
void imprimirLista(int a[], int n){
	int i;
	
	for(i=0; i<n; i++){
		
		char c;
		c=(i%10==0)?'\n':' ';
		printf("%c%d, ",c,a[i]); 
	//	c=(i%10==0)?'\n':' ';
	//	printf(" %d,",a[i]);
	}
}

void entradaLista(int a[], int n){
	
	int i;
	
	
	for(i=0; i<n; i++){
		printf("entrada[%d]:\n", i+1);
		scanf("%d", a+i);	//esto om
	}
}

void ordSeleccion(int a[], int n){//double
	
	int indiceMenor, i, j, k;
	
	for(i=0; i<n-1; i++){
		
		indiceMenor = i;
		for(j=i+1; j<n; j++){
			if(a[j] < a[indiceMenor])
			indiceMenor = j;	
		}
		
		if(i!=indiceMenor){
			int aux = a[i];
			a[i]=a[indiceMenor];
			a[indiceMenor] = aux;
		}
		
		imprime2(a,n);
	}
}


void intercambiar(int *a, int *b){
  int temporal = *a;
  *a = *b;
  *b = temporal;
}
