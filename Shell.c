

#include <stdio.h>
#include <stdlib.h>

#define N 100

void ordenacionShell(int a[], int n);
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
	
	ordenacionShell(v, n);
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

void ordenacionShell(int a[], int n){//double
	
	int i, j, k;
	int intervalo = n / 2;
	
	printf("\n %d intervalo: %d ",n,intervalo);
	while(intervalo>0){
		for(i=intervalo; i<n; i++){ //
			j=i-intervalo;
			while(j >= 0){
				k=j + intervalo;
				if(a[j] <= a[k]) j = -1; //asi termina el bucle par ordenado
				else{
					intercambiar(&a[j], &a[k]);
					j=j-intervalo;
					
				}
			}
		}
		imprimirLista(a,n);
		intervalo = intervalo / 2;
		printf("\n %d intervalo: %d ",n,intervalo);
	}
}


void intercambiar(int *a, int *b){
  int temporal = *a;
  *a = *b;
  *b = temporal;
}
