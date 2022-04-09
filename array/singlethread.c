#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define SIZE 2000000 //tem que ser par

int vet[SIZE];
double total = 0;
long int soma = 0;
clock_t inicio,fim;

void func_soma(int pos, int tamanho){
    for(int i = pos; i < tamanho; i++){
     soma +=vet[i];
    }
}

void inicializa_vetor(){
    for(int i = 0; i < SIZE; i++){
        vet[i] = i*i;
    }
}


int main(int argc, char ** argv){
    
    inicializa_vetor();
    inicio= clock();    
    func_soma(0, SIZE);

    fim = clock();

    total = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("total: %f\n\n", total);
    printf("soma: %li\n\n", soma);

    return 0;
}


