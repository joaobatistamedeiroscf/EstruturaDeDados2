#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Estrutura da lista duplamente encadeada
typedef struct No {
    int valor;
    struct No* prox;
    struct No* ant;
} No;

// Insere valor no final da lista
void inserir_final(No** inicio, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No* temp = *inicio;
        while (temp->prox != NULL)
            temp = temp->prox;

        temp->prox = novo;
        novo->ant = temp;
    }
}

// Imprime a lista
void imprimir_lista(No* inicio) {
    while (inicio != NULL) {
        printf("%d->", inicio->valor);
        inicio = inicio->prox;
    }
    printf("FIM\n");
}

// Bubble Sort para lista duplamente encadeada
void bubble_sort_lista(No* inicio) {
    int troca;
    No* ptr;
    No* fim = NULL;

    if (inicio == NULL) return;

    do {
        troca = 0;
        ptr = inicio;

        while (ptr->prox != fim) {
            if (ptr->valor > ptr->prox->valor) {
                // Troca os valores (como no vetor)troca o dado inicio  c
                int temp = ptr->valor;
                ptr->valor = ptr->prox->valor;
                ptr->prox->valor = temp;
                troca = 1;
            }
            ptr = ptr->prox;
        }
        fim = ptr;
    } while (troca);
}

// Função principal
int main() {
    srand(time(NULL));
    int tamanho;
    No* lista = NULL;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanho);

    printf("Lista preenchida:\n");
    for (int i = 0; i < tamanho; i++) {
        int num = rand() % 100;
        inserir_final(&lista, num);
    }
    imprimir_lista(lista);

    bubble_sort_lista(lista);

    printf("Lista ordenada:\n");
    imprimir_lista(lista);

    return 0;
}
