#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void troca(int *a , int *b){
    int copia = *a ; 
    *a = *b ; 
    *b = copia ; 
}


void heapify(int *arr,int n,int i){
//MAX HEAP 
    int maior = i ; 
    
    int f_esq = 2 * i + 1 ; //filho da esquerda
    int f_dir = 2 * i + 2 ; // filho da direita 

    if(f_esq < n && arr[f_esq] > arr[maior])
    {
        maior = f_esq ; 
    }
    if(f_dir < n && arr[f_dir] > arr[maior])
    {
        maior = f_dir ; 
    } 

    if (maior !=  i){
        int troca = arr[i] ; 
        arr[i] = arr[maior];
        arr[maior] = troca ;
        heapify(arr , n , maior) ;  
    }
}

void heapSort(int *arr , int n ){

    //Construir a max-heap
    for(int i = n / 2 - 1; i >= 0 ; i --){
        heapify(arr , n , i ) ; 
    }

    // Fase 2: Repetidamente extrair o maior elemento da heap

    for(int i  = n - 1 ; i > 0 ; i--){
        int troca  = arr[0];
        arr[0] = arr[i];
        arr[i] = troca; 

        heapify(arr , i , 0 );
    }
}

void imprimir(int *arr , int n){
    for(int i = 0 ; i < n ; i++){
        printf("%d -> ", arr[i]);
    }
    printf("FIM!\n");
}
    

int main() {
    srand(time(NULL));
    int tamanho;
   
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    printf("Vetor preenchido com numeros aleatorios:\n");
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 100;
        
    }

    imprimir(vetor , tamanho) ;
    
    heapSort(vetor ,tamanho );
    
    imprimir(vetor , tamanho) ; 
    



    return 0;
}
