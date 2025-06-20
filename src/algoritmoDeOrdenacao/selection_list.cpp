#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct No {
    int valor;
    struct No* ant;
    struct No* prox;
} No;

// Inserção no fim da lista
void inserirFim(No** inicio, int valor) {
    No* novo = (No*) malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    if (*inicio == NULL) {
        *inicio = novo;
    } else {
        No* temp = *inicio;
        while (temp->prox != NULL) {
            temp = temp->prox;
        }
        temp->prox = novo;
        novo->ant = temp;
    }
}

// Impressão da lista
void imprimirLista(No* inicio) {
    while (inicio != NULL) {
        printf("%d-> ", inicio->valor);
        inicio = inicio->prox;
    }
    printf("FIM!\n");
}

// Troca dois nós na lista fisicamente
void trocaNos(No** head, No* a, No* b) {
    if (a == b || a == NULL || b == NULL) return;

    // Garante que a vem antes de b
    if (a->prox == b) {
        // a <-> b
        if (a->ant) a->ant->prox = b;
        if (b->prox) b->prox->ant = a;

        a->prox = b->prox;
        b->ant = a->ant;

        a->ant = b;
        b->prox = a;
    } else if (b->prox == a) {
        // b <-> a, inverte para reutilizar o código
        trocaNos(head, b, a);
        return;
    } else {
        // Não adjacentes
        No* aAnt = a->ant;
        No* aProx = a->prox;
        No* bAnt = b->ant;
        No* bProx = b->prox;

        if (aAnt) aAnt->prox = b;
        if (aProx) aProx->ant = b;
        if (bAnt) bAnt->prox = a;
        if (bProx) bProx->ant = a;

        a->ant = bAnt;
        a->prox = bProx;
        b->ant = aAnt;
        b->prox = aProx;
    }

    // Atualizar ponteiro do início da lista se necessário
    if (*head == a) *head = b;
    else if (*head == b) *head = a;
}

// Selection Sort com troca de nós reais
void selectionSortLista(No** head) {
    for (No* i = *head; i != NULL; i = i->prox) {
        No* menor = i;

        for (No* j = i->prox; j != NULL; j = j->prox) {
            if (j->valor < menor->valor) {
                menor = j;
            }
        }

        if (menor != i) {
            trocaNos(head, i, menor);
            // Depois da troca, `i` agora aponta para o menor — devemos corrigir
            i = menor; // manter o loop funcionando corretamente
        }
    }
}

// Função principal
int main() {
    srand(time(NULL));
    int tamanho;
    No* lista = NULL;

    printf("Digite o tamanho da lista: ");
    scanf("%d", &tamanho);

    for (int i = 0; i < tamanho; i++) {
        int numero = rand() % 100;
        inserirFim(&lista, numero);
    }

    printf("\nLista original:\n");
    imprimirLista(lista);

    selectionSortLista(&lista);

    printf("\nLista ordenada (Selection Sort com troca de nós):\n");
    imprimirLista(lista);

    return 0;
}
