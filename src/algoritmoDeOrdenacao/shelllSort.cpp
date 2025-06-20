#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//divide a estrutura conforme um determinado gap 



int main(){
    srand(time(NULL));
    int tam ; 

    printf("Digite o tamanho do vetor: ");
    scanf("%d",&tam) ;

    int vetor[tam] ; 
    
    printf("Vetor:\n");
    
    for(int i = 0 ; i < tam ; i ++){
        vetor[i] = rand() % 100 ;
        printf("%d -> ", vetor[i]); 
    }
    
    printf("FIM!");

    








    return 0 ; 
}