
#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>

#define SIZE 150


int  result0[SIZE][SIZE],result1[SIZE][SIZE], matriz0[SIZE][SIZE], matriz1[SIZE][SIZE];

clock_t inicio_programa,fim_programa,inicio_mult,fim_mult;

double tempo_programa, tempo_mult;

//pthread_mutex_t er = PTHREAD_MUTEX_INITIALIZER;

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
            
            matriz1[i][j] = (i+j)*5;
        
        }

    }
    
    
}



void multiplica_matriz(){
    for(int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){
           //pthread_mutex_lock(&er);
            (result0[i][j]) = matriz0[i][j] * matriz1[j][i];
            //pthread_mutex_unlock(&er);
        }
    }
    return;
}


void multiplica_matriz_pos(){
    
    for(int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){
           // pthread_mutex_lock(&er);
           (result1[i][j]) = matriz0[i][j] * matriz1[i][j];
         //  pthread_mutex_unlock(&er);
        }
    }
    return;
}

int main(int argc, char ** argv){
inicio_programa = clock();
    gera_matriz();
    //imprime_matriz(matriz0);
    //imprime_matriz(matriz1);
   
   // imprime_matriz(result);

    pthread_t t0,t1;

inicio_mult = clock();
    pthread_create(&t0, NULL, (void *) multiplica_matriz, NULL);
    pthread_create(&t1, NULL, (void *) multiplica_matriz_pos, NULL);
    pthread_join(t0, NULL);
    pthread_join(t1, NULL); 
fim_mult = clock(); 


//imprime_matriz(result0);
//imprime_matriz(result1);

fim_programa = clock();

   tempo_programa = (double)(fim_programa - inicio_programa) / CLOCKS_PER_SEC;
   printf("Tempo de programa: ""%f%s\n\n", tempo_programa, " millisegundos!");

   tempo_mult = (double)(fim_mult - inicio_mult) / CLOCKS_PER_SEC;
   printf("Tempo de multiplicacao: ""%f%s\n\n", tempo_mult, " millisegundos!");
    
    return 0;

}