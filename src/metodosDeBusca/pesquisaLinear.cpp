#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int pesquisaLinear(int arr[], int tam, int cha) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == cha) {
            return i ; 
        }
    }
    return -1 ;
}

int main() {
    srand(time(NULL));

    int tamanho = 10; 
    int array[tamanho]; 
    int chave = 30; // Número a ser procurado

    printf("Vetor gerado:\n");
    for (int i = 0; i < tamanho; i++) {
        array[i] =  rand() % 31;
        printf("%d ", array[i]);
    }
    printf("\n");

    int resultado = pesquisaLinear(array, tamanho, chave);

    if(resultado != -1){
        printf("Elemento encontrado, na posicao %d",resultado);
    }else {
        printf("Elemento nao encontrado");
    }
    return 0;
}