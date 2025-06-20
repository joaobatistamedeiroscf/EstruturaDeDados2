#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    srand(time(NULL));
    
    int tamanho ; 
    int copia ; 
    int troca = 0  ;
    
    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tamanho);

    int array[tamanho] ;

    printf("Vetor preenchido:\n");
    
    for(int i = 0 ; i < tamanho ; i++)
    {
        array[i] = rand() % 100 ;
        printf("%d->",array[i]); 
        
    }
    
    do 
    {
        troca = 0 ; 
        for(int i = 0 ; i < tamanho - 1 ; i ++)
        {
            if(array[i] > array[i+1])
            {
                copia = array[i];
                array[i] = array[i+1] ; 
                array[i + 1] = copia ;
                troca = 1  ; 
            }
        }

    }while(troca == 1);

   printf("\nVetor ordenado:\n");
    for(int i = 0 ; i < tamanho ; i++)
    {
        printf("%d->",array[i]); 
    }


    
    return 0 ; 
}