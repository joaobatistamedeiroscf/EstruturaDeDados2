#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>



void shellSort(int vetor[], int n){
     int h = 1  ; 
     
     while(h < n/3){
        h  = 3 * h + 1 ; 
     }

     while(h >= 1){
        for(int i = h ; i < n; i++){
            int copia = vetor[i];
            int j ; 

            for(j = i ;  j >= h && vetor[j - h] > copia ; j -= h){
                vetor[j] = vetor[j -h];
            }

            vetor[j] = copia ;
        }

        h = h / 3; 
     }


}





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
        

    shellSort(vetor, tam);

     printf("\nVetor Ordenado usando o shell sort :\n");
    
    for(int i = 0 ; i < tam ; i ++){
        printf("%d -> ", vetor[i]); 
     }
     
     printf("FIM!");
    

    


    








    return 0 ; 
}