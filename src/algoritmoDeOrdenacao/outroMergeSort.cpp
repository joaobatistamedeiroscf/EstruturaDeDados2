#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

void merge(int arr[], int inicio, int meio, int fim) {
    int i, j, k;
    int n1 = meio - inicio + 1;
    int n2 = fim - meio;

    // Criando arrays temporários
    int L[n1], R[n2];

    // Copiando dados para os arrays temporários
    for (i = 0; i < n1; i++)
        L[i] = arr[inicio + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[meio + 1 + j];

    // Mesclando os arrays temporários de volta em arr[inicio..fim]
    i = 0; // índice inicial de L
    j = 0; // índice inicial de R
    k = inicio; // índice inicial do array original

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiando os elementos restantes de L (se houver)
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiando os elementos restantes de R (se houver)
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
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