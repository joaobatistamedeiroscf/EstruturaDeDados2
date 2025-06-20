#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partionamento(int *vetor , int inicio , int fim)
{
    int pivo =  (vetor[inicio] + vetor[fim] + vetor[(inicio + fim)/2] )/ 3 ;

    while(inicio < fim)
    {
        while(inicio < fim && vetor[inicio] <= pivo)
        {
            inicio += 1 ;
        }
        while(inicio < fim && vetor[fim] > pivo)
        {
            fim -= 1 ; 
        }
      
        int copia =  vetor[inicio] ;
        vetor[inicio] = vetor[fim] ; 
        vetor[fim] = copia ;
    
    }

    return inicio  ;
}

void quickSort(int *vetor ,  int inicio , int fim)
{
    if(inicio < fim)
    {
        int pos =  partionamento(vetor , inicio , fim); 
        quickSort(vetor, inicio , pos - 1); // esquerda 
        quickSort(vetor ,  pos , fim ); // direita
    }
}


int main(){
    srand(time(NULL));

    int tamanho ;


    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tamanho); 

    int vetor[tamanho] ; 
    int inicio = 0 , fim =  tamanho ; 

    printf("Vetor preechido com numeros aleatorios:\n");
    for(int i = 0 ; i < tamanho ; i++)
    {
        vetor[i] = rand() % 100 ;
        printf("%d -> ",vetor[i]); 
    }

    printf("FIM");

    printf("\nOrdenando o vetor usando o Quick Sort:\n");

    quickSort(vetor ,inicio , fim );

    for(int i = 0 ; i < tamanho ; i++)
    {
        printf("%d -> ",vetor[i]); 
    } 

    printf("FIM");
    
    return 0 ; 
}