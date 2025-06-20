#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int tamanho;
    int menor;
    int copia;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    printf("Vetor preenchido com numeros aleatorios:\n");
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
        printf("%d ", vetor[i]);
    }

    printf("\nOrdenando o vetor com Selection Sort:\n");

    for (int i = 0; i < tamanho; i++) {
        menor = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[menor]) {
                menor = j;
            }
        }
        copia = vetor[menor];
        vetor[menor] = vetor[i];
        vetor[i] = copia;
    }

    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }

    return 0;
}
