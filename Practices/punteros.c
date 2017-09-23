#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void function(int *numero){
	*numero +=10;
}

void functionArray(int *array,int size){
	int i = 0;
	for (i = 0; i<size;i++){
		array[i] = i;
	}
}

int main(){
	int i,var = 0;
	int arr[10];
	int* puntero;
	function(&var);
	printf("Var: %d\n",var);
	functionArray(arr,10);
	for (i = 0; i<10;i++){
		printf("Array[%d]: %d\n",i,arr[i]);
	}
	*puntero = 3;
	printf("Puntero: %d\n",*puntero);
	//puntero =6;
	function(puntero);
	printf("Puntero: %d\n",*puntero);
	
}
