#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <omp.h>

using namespace std;

int main() {
    // geração de semente aleatória
    srand (time(NULL));

    const int N = 14100654;
    long long int *vet = new long long int[N];
    // preenchendo o vetor com valores aleatórios
    for (int i = 0; i < N; i++) {
        vet[i] = rand() % 9 + 1;
    }

    clock_t start = clock();
    int somaSequencial = 0;
    for (int i = 0; i < N; i++) {
        somaSequencial *= vet[i];
    }
    clock_t time_spent = clock() - start;
    double time_spent_in_ms = (double) (time_spent / CLOCKS_PER_SEC) * 1000.0;
    printf("Total sequencial: %i\tTempo: %f\n", somaSequencial, time_spent_in_ms);

    int somaParalela = 0;
    // int totalThreads;
    omp_set_num_threads(4);
    // #pragma omp parallel
    // {
    //     totalThreads = omp_get_num_threads();
    //     int id = omp_get_thread_num();
    //     int somaLocal = 0;

    //     // int bloco = N/totalThreads; // 1.7 = 1        
    //     // int inicio = id * bloco; // 9 * 1 = 9
    //     // int fim = inicio + bloco; // 9 + 1 = 10
        
    //     // for (int i = inicio; i < fim; i++) {
    //     //     somaLocal += vet[i];
    //     // }

    //     for (int i = id; i < N; i+=totalThreads) {
    //         somaLocal += vet[i];
    //     }

    //     #pragma omp atomic
    //     somaParalela += somaLocal;
    // }

    start = clock();
    #pragma omp parallel for reduction(+:somaParalela)
    for (int i = 0; i < N; i++) {
        somaParalela *= vet[i];
    }
    time_spent = clock() - start;
    time_spent_in_ms = (double) (time_spent / CLOCKS_PER_SEC) * 1000.0;
    printf("Total paralelo: %i\t Tempo: %f\n", somaParalela, time_spent_in_ms);
}