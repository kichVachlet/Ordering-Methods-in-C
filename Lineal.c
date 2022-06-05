//Ordenacion lineal

#include <stdio.h>
#include <stdlib.h>

#define N 100

void ordSeleccion(int a[], int n);
void imprimirLista(int a[], int n);
void entradaLista(int a[], int n);
void intercambiar(int *a, int *b);

int main(int argc, char *argv[]) {
	
	int n;
	int v[N];//int v[N];
	
	do{
		printf("\nIntroduzca el numero de elementos: ");
		scanf("%d", &n);
	}while((n<1) && (n>N));
	
	entradaLista(v,n);
	
	printf("\nLista original de %d elementos",n);
	imprimirLista(v,n);
	
	
	ordSeleccion(v, n);
	printf("\nLista ordenada de %d elementos",n);
	imprimirLista(v,n);
	 
	system("pause");
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

ordSeleccion(int a[], int n){
	
	int indiceMenor, i,j;
	int aux;
	
	for(i=0; i<n-1; i++){
		indiceMenor = i;
		for(j=i+1; j<n; j++)
		if(a[j] < a[indiceMenor])
			indiceMenor = j;
		
		if(i != indiceMenor){
			double aux = a[i];
			a[i] = a[indiceMenor];
			a[indiceMenor] = aux;
			
		}
		
	}
	

}


void intercambiar(int *a, int *b){
  int temporal = *a;
  *a = *b;
  *b = temporal;
}


