#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>


void shellSort(int array[], int n) {
    // Começa com um grande intervalo, depois vai diminuindo
    for (int gap = n / 2; gap > 0; gap /= 2) {
        // Faz uma inserção modificada para este gap
        for (int i = gap; i < n; i++) {
            int temp = array[i];
            int j;

            // Move elementos que estão à frente do elemento atual
            for (j = i; j >= gap && array[j - gap] > temp; j -= gap) {
                array[j] = array[j - gap];
            }

            array[j] = temp;
        }
    }
}


void shellSortK(int vetor[], int n){
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
        

    shellSortK(vetor, tam);

     printf("\nVetor Ordenado usando o shell sort :\n");
    
    for(int i = 0 ; i < tam ; i ++){
        printf("%d -> ", vetor[i]); 
     }
     
     printf("FIM!");
    

    


    








    return 0 ; 
}