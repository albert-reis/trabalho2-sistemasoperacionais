#include <stdlib.h>
#include <stdio.h>

#include <time.h>
#include <omp.h>


#define SIZE 4//tem que ser par

int vet[SIZE], soma =0;
void func_soma(int pos, int tamanho, int total);

void inicializa_vetor(){
    for(int i = 0; i < SIZE; i++){
        vet[i] = i * i;
    }
}

int main(int argc, char ** argv){
    inicializa_vetor();
    int totalThreads;
    omp_set_num_threads(4); 
    clock_t inicio, fim;
    #pragma omp parallel
    {
        totalThreads = omp_get_num_threads();
        int id = omp_get_thread_num();

        int bloco = SIZE/totalThreads; // 1.7 = 1
        int comeco = id * bloco; // 9 * 1 = 9
        int termino = inicio + bloco; // 9 + 1 = 1
       
        if(id == 0){
            inicio = clock();
            func_soma(id, SIZE, totalThreads);
        }
        func_soma(id, SIZE, totalThreads);
        
    } 
    fim = clock();
    double tempo;
    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de programa: ""%f%s\n\n", tempo, " millisegundos!");
    printf("soma: %i\n\n", soma);
    return 0;
}
void func_soma(int pos, int tamanho, int total){
    for(int i = pos; i < tamanho; i+=total){
     
     soma +=vet[i];
    
		
    }
}

