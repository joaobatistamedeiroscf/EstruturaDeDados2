#include <stdio.h>
#include <stdlib.h>
#include <time.h> 


void merge(int *vetor, int inicio, int meio, int fim) {
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;

    tamanho = fim - inicio + 1;
    p1 = inicio;
    p2 = meio + 1;

    temp = (int *) malloc(tamanho * sizeof(int));

    if (temp != NULL) {
        for (i = 0; i < tamanho; i++) {
            if (!fim1 && !fim2) {
                if (vetor[p1] < vetor[p2])
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];

                if (p1 > meio) fim1 = 1;
                if (p2 > fim) fim2 = 1;
            } else {
                if (!fim1)
                    temp[i] = vetor[p1++];
                else
                    temp[i] = vetor[p2++];
            }
        }

        for (j = 0, k = inicio; j < tamanho; j++, k++)
            vetor[k] = temp[j];

        free(temp);
    }
}

void mergeSort(int *vetor , int inicio , int fim ){
    int meio = 0 ; 

    if(inicio < fim){
        meio = (inicio+fim)/2; // divide o vetor no meio 
        mergeSort(vetor, inicio , meio); // divide a primeira metade
        mergeSort(vetor, meio+1 , fim); // divide a segunda metade 
        merge(vetor,inicio , meio , fim); // função merge vai juntar o vetor
    }
}

int main(){
    srand(time(NULL));
    int tamanho; 
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tamanho);

    int vetor[tamanho] ; 
    int inicio = 0 , fim = tamanho -1;

    for(int i = 0 ; i < tamanho ; i ++){
        vetor[i] = rand()  % 100 ;
        printf("%d -> ",vetor[i]); 
    }

    printf("FIM!");

    printf("\nVetor ordenado utilizando Merge Sort:\n");

    mergeSort(vetor , inicio , fim) ; 
    
    for(int i = 0 ; i < tamanho ; i ++){
        printf("%d -> ",vetor[i]); 
    }

    printf("FIM!");













    return 0 ; 
}