#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void insertionSort(int *vetor , int tamanho)
{
    for(int i = 0 ; i < tamanho ; i ++)
    {
        int aux , j = i ; 
        aux = vetor[j] ; 

        while(j > 0 && aux < vetor[j-1])
        {
            vetor[j] = vetor[j - 1] ; 
            j-- ;  
        }
        vetor[j] = aux ; //copia
    } 
    
    
}

void insertionSortRerc(int *vetor , int fim , int tamanho){
    if(fim >= tamanho) return ; 
    int aux , j = fim ; 

    aux = vetor[j] ; 

    while(j > 0 && aux < vetor[j-1])
    {
        vetor[j] = vetor[j-1];
        j--;
    }

    vetor[j] = aux ;
    insertionSortRerc(vetor , fim + 1 , tamanho); 

}



int main() {
    srand(time(NULL));
    int tamanho;
    int fim = tamanho - 1 ;     

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    printf("Vetor preenchido com numeros aleatorios:\n");
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
        printf("%d-> ", vetor[i]);
    }

    printf("FIM!");

    // insertionSort(vetor , tamanho) ;
    insertionSortRerc(vetor ,fim , tamanho );  

    printf("\n");

     for (int i = 0; i < tamanho; i++) {
        printf("%d-> ", vetor[i]);
    }

    printf("FIM!");


    



    return 0;
}
