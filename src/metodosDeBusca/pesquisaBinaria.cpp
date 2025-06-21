#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    int tamanho = 15, vetor[tamanho], copia, troca, chave = 2;
    int inicio = 0, fim = tamanho - 1, meio, encontrado = 0;

   
    printf("Vetor original:\n");
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 16;
        printf("%d ", vetor[i]);
    }
    printf("\n");

    
    do {
        troca = 0;
        for (int i = 0; i < tamanho - 1; i++) {
            if (vetor[i] > vetor[i + 1]) {
                copia = vetor[i];
                vetor[i] = vetor[i + 1];
                vetor[i + 1] = copia;
                troca = 1;
            }
        }
    } while (troca == 1);

    printf("Vetor ordenado:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");

    
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;

        if (vetor[meio] == chave) {
            encontrado = 1;
        } else if (vetor[meio] > chave) {
            fim = meio - 1; // Busca na parte esquerda
        } else {
            inicio = meio + 1; // Busca na parte direita
        }
    }

    if (encontrado == 0) {
        printf("Elemento não encontrado!\n");
    }

    return 0;
}