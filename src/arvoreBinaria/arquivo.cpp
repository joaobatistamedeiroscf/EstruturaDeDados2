#include <stdio.h>
#include <stdlib.h>



typedef struct no {
    int valor ;
    struct no *esquerda ; 
    struct no *direita ;
}No ; 

No* inserir(No *raiz , int num){
    if(raiz == NULL){
        No *novo  = new No ; 
        novo->valor = num ; 
        novo->esquerda = NULL;
        novo->direita = NULL;

        return novo ;
    }
    else {
        if(raiz->valor > num){
            raiz->esquerda = inserir(raiz->esquerda , num);
        }else {
            raiz->direita = inserir(raiz->direita, num);
        }
        return raiz ; 
    }
}

void imprimir(No *raiz){
    if(raiz){
        printf("%d " , raiz->valor);
        imprimir(raiz->esquerda);
        imprimir(raiz->direita);
    }
}

int main(){

    No *raiz = NULL ; 
    
    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz , 70);
    raiz = inserir(raiz , 20);

    imprimir(raiz);



    return 0 ; 
}
