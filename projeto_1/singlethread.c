
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define SIZE 3

int  result[SIZE][SIZE],  matriz0[SIZE][SIZE], matriz1[SIZE][SIZE],a;
double tempo_programa, tempo_mult;

clock_t inicio_programa,fim_programa,inicio_mult,fim_mult;

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
            result[i][j] = matriz0[i][j] * matriz1[j][i];
        }
    
    }
}

void multiplica_matriz_pos(){
    
    for(int i = 0; i < SIZE; i++){

        for(int j = 0; j < SIZE; j++){
           // pthread_mutex_lock(&er);
           (result[i][j]) = matriz0[i][j] * matriz1[i][j];
         //  pthread_mutex_unlock(&er);
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


int main(int argc, char ** argv){
   
   inicio_programa = clock(); 
   
   gera_matriz();
   
   printf("Matriz A\n\n");
   imprime_matriz(matriz0);
  
   printf("Matriz B\n\n");
   imprime_matriz(matriz1);

inicio_mult = clock();
   multiplica_matriz();
   
   printf("Matriz C\n\n");
   imprime_matriz(result);
   
   multiplica_matriz_pos();

fim_mult = clock();

   printf("Matriz C\n\n");
   imprime_matriz(result);

   fim_programa = clock();
  
   tempo_programa = (double)(fim_programa - inicio_programa) / CLOCKS_PER_SEC;
   printf("Tempo de programa: ""%f%s\n\n", tempo_programa, " millisegundos!");

   tempo_mult = (double)(fim_mult - inicio_mult) / CLOCKS_PER_SEC;
   printf("Tempo de multiplicacao: ""%f%s\n\n", tempo_mult, " millisegundos!");
   

   return 0;

}
