
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define SIZE 3

int  result[SIZE][SIZE],  matriz0[SIZE][SIZE], matriz1[SIZE][SIZE];




pthread_mutex_t em = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t eg = PTHREAD_MUTEX_INITIALIZER;

void* multiplica_matriz(void* arg){

    for(int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){
		pthread_mutex_lock(&em);
            (result[i][j]) = matriz0[i][j] * matriz1[j][i];

		pthread_mutex_unlock(&em);
        }
    }

}

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



void multiplica_matriz_pos(){
    
    for(int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){
            pthread_mutex_lock(&em);
           (result[i][j]) = matriz0[i][j] * matriz1[i][j];
           pthread_mutex_unlock(&em);
        }
    }
    return;
}


int main(int argc, char ** argv){
   int* p;
   pthread_t t0,t1;

   clock_t inicio = clock();

   pthread_create(&t0, NULL, (void *) gera_matriz, NULL);
   pthread_create(&t1, NULL, multiplica_matriz, (void*)(p));
   pthread_join(t0, NULL);
   pthread_join(t1, NULL);

//   clock_t inicio = clock();

  
   printf("Matriz A\n\n");
   imprime_matriz(matriz0);
  
   printf("Matriz B\n\n");
   imprime_matriz(matriz1);

//   multiplica_matriz();
  
   printf("Matriz C\n\n");
   imprime_matriz(result);

   //multiplica_matriz_pos();
   //imprime_matriz(result);

   clock_t fim = clock();
   double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
   printf("Tempo: ""%f%s", tempo, " millisegundos!");

   return 0;

}
