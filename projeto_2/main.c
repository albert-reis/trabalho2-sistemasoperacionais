#include <stdlib.h>
#include <stdio.h>
//#include <pthread.h>
#include <time.h>


#define SIZE 100 //tem que ser par
void inicializa_vetor();
void sort(int tamanho);
int vet[SIZE];
void ordenar_th0();
void ordenar_th1();
//pthread_mutex_t er = PTHREAD_MUTEX_INITIALIZER; 

int main(int argc, char ** argv){
    inicializa_vetor();
    sort(0, SIZE);
    //pthread_t t0, t1, t2;

    //pthread_create(&t0, NULL, (void *) ordenar_th0 , NULL);
    //pthread_create(&t1, NULL, (void *) ordenar_th1, NULL);
    //pthread_join(t0, NULL);
    //pthread_join(t1, NULL);
    //pthread_create(&t2, NULL, (void *) ordenar_th2, NULL);
    //pthread_join(t2, NULL);
    return 0;
}
void sort(int pos, int tamanho){
    int aux;
    for(int i = pos; i < tamanho; i++){
        for(int j = i + 1; j < tamanho; j++){
            //pthread_mutex_lock(&er);
            if (vet[i] < vet[j]){
                aux = vet[i];
                vet[i] = vet[j];
                vet[j] = aux;
            }
            //pthread_mutex_unlock(&er);
        }
    }
}

void ordenar_th0(){
    sort(0, SIZE/2);
}

void ordenar_th1(){
    sort(SIZE/2, SIZE/2);
}

void ordenar_th2(){
    sort(0, SIZE);
}

void inicializa_vetor(){
    srand(time(NULL));
    for(int i = 0; i < SIZE; i++){
        vet[i] = rand() % SIZE;
    }
}