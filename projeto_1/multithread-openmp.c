
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>
#define SIZE 3

int  result[SIZE][SIZE],  matriz0[SIZE][SIZE], matriz1[SIZE][SIZE], total_t;
double tempo_programa, tempo_mult;

clock_t inicio_programa,fim_programa,inicio_mult,fim_mult;

void imprime_matriz(int matriz[SIZE][SIZE]){
    for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			printf("%d  ", matriz[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n");
}

void gera_matriz(){
    srand(time(NULL));
    

    for (int i = 0; i < SIZE; i++){
        
        for(int j = 0; j < SIZE; j++){
           
            
            matriz0[i][j] = rand() % 10;
            
            matriz1[i][j] = rand() % 10;
        
        }

    }
    
    
}

int main(int argc, char ** argv){

inicio_programa = clock();

gera_matriz();
imprime_matriz(matriz0);
imprime_matriz(matriz1);

inicio_mult = clock();
 #pragma omp parallel num_threads(2)
 {
 
 	#pragma omp single
	{
	  for(int i = 0; i < SIZE; i++){

		for(int j = 0; j < SIZE; j++){
		    (result[i][j]) = matriz0[i][j] * matriz1[j][i];
			}
		    }
        
        imprime_matriz(result);
	}
	
	#pragma omp single
	{
	   for(int i = 0; i < SIZE; i++){

		for(int j = 0; j < SIZE; j++){
		   (result[i][j]) = matriz0[i][j] * matriz1[i][j];
			}
		    }
fim_mult = clock();
fim_programa = clock();
	
        imprime_matriz(result);
	   tempo_programa = (double)(fim_programa - inicio_programa) / CLOCKS_PER_SEC;
	   printf("Tempo de programa: ""%f%s\n\n", tempo_programa, " millisegundos!");

	   tempo_mult = (double)(fim_mult - inicio_mult) / CLOCKS_PER_SEC;
	   printf("Tempo de multiplicacao: ""%f%s\n\n", tempo_mult, " millisegundos!");
	} 
 }
}