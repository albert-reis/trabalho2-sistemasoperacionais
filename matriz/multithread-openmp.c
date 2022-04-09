
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>
#define SIZE 4

int  result0[SIZE][SIZE],result1[SIZE][SIZE], matriz0[SIZE][SIZE], matriz1[SIZE][SIZE], total_t;
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
   

    for (int i = 0; i < SIZE; i++){
        
        for(int j = 0; j < SIZE; j++){
           
            
            matriz0[i][j] = (i+j)*8;
            
            matriz1[i][j] = (i*j)+3;
        
        }

    }
    
    
}
void mult_m(int id){
	for(int j = 0; j < SIZE; j++){
		(result0[id][j]) = matriz0[id][j] * matriz1[j][id];
	}
}
void mult_pos(int id){
	for(int j = 0; j < SIZE; j++){
		(result1[id][j]) = matriz0[id][j] * matriz1[id][j];
	}
}

int main(int argc, char ** argv){

	//inicio_programa = clock();

	gera_matriz();
	//imprime_matriz(matriz0);
	//imprime_matriz(matriz1);

	#pragma omp parallel num_threads(2 * SIZE + 1)
	{
	int id = omp_get_thread_num();
	if (id == 2 * SIZE)
		inicio_mult = clock();
	if (id < SIZE){//0,1,2,3 SIZE = 4
		mult_m(id);
	} else {//4,5,6,7 SIZE = 4
		mult_pos(id % SIZE);
	} 		
	}
	fim_mult = clock();
	//imprime_matriz(result0);
	//imprime_matriz(result1);
		
//
	//tempo_programa = (double)(fim_programa - inicio_programa) / CLOCKS_PER_SEC;
	//printf("Tempo de programa: ""%f%s\n\n", tempo_programa, " millisegundos!");
//
	tempo_mult = (double)(fim_mult - inicio_mult) / CLOCKS_PER_SEC;
	printf("Tempo de multiplicacao: ""%f%s\n\n", tempo_mult, " millisegundos!");
} 
	
