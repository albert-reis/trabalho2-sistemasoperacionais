
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <omp.h>
#define SIZE 3

int  result[SIZE][SIZE],  matriz0[SIZE][SIZE], matriz1[SIZE][SIZE];

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



void multiplica_matriz(){


    for(int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){
            (result[i][j]) = matriz0[i][j] * matriz1[j][i];	  
        }
    }
}


int main(int argc, char ** argv){
 clock_t fim = clock();

 clock_t inicio = clock();
 
 #pragma omp paralell num_threads(4)
 
 #pragma omp single
 {
    srand(time(NULL));
    

    for (int i = 0; i < SIZE; i++){
        
        for(int j = 0; j < SIZE; j++){
           
            #pragma omp atoi
            {
            matriz0[i][j] = rand() % 10;
            
            matriz1[i][j] = rand() % 10;
	    }
        }

    }
}

for(int i = 0; i < SIZE; i++) {
		for(int j = 0; j < SIZE; j++) {
			printf("%d  ", matriz0[i][j]);
		}
		printf("\n\n");
	}
	printf("\n\n");


// double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
// printf("Tempo: ""%f%s", tempo, " millisegundos!");
}

