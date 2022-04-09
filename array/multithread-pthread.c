#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include <time.h>


#define SIZE 2000000 //tem que ser par
pthread_mutex_t er = PTHREAD_MUTEX_INITIALIZER; 
int vet[SIZE];
double total = 0;
long int soma =0;
clock_t inicio,fim;

void func_soma(int pos, int tamanho){
    for(int i = pos; i < tamanho; i++){
     pthread_mutex_lock(&er);
     soma +=vet[i];
     pthread_mutex_unlock(&er);
		
    }
}

void thread0(){
    func_soma(0, SIZE/4);
}

void thread1(){
    func_soma((SIZE/4), SIZE/2);
}

void thread2(){
    func_soma(SIZE/2, 3*(SIZE/4));
}

void thread3(){
    func_soma(3*(SIZE/4), SIZE);
}
void inicializa_vetor(){
    for(int i = 0; i < SIZE; i++){
        vet[i] = i*i;
    }
}


int main(int argc, char ** argv){
    
    inicializa_vetor();
    
    //func_soma(0, SIZE);
    
    pthread_t t0, t1, t2, t3;
    inicio= clock();
    pthread_create(&t0, NULL, (void *) thread0 , NULL);
    pthread_create(&t1, NULL, (void *) thread1 , NULL);
    pthread_create(&t2, NULL, (void *) thread2 , NULL);
    pthread_create(&t3, NULL, (void *) thread3 , NULL);

    pthread_join(t0, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    pthread_join(t3, NULL);
    fim = clock();

    total = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("total: %f\n\n", total);
    printf("soma: %li\n\n", soma);

    return 0;
}


