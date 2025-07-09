#include <stdio.h>
#include <stdlib.h>


typedef struct no {
    int valor ; 
    struct no *esquerda ; 
    struct no *direita ; 
}No ;

No* inserir(No *raiz , int num){
    if(raiz == NULL){
        No *novo =  new No ; 
        novo -> valor = num ;
        novo -> esquerda = NULL ; 
        novo -> direita = NULL ;  
        
        return novo ; 
    }else {
        if(raiz->valor > num){
            raiz->esquerda = inserir(raiz-> esquerda,num);
        }else {
            raiz-> direita = inserir(raiz->direita, num);
        }
        return raiz ;
    }
}

No *busca(No *raiz , int num){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz->valor == num){
        return raiz ; 
    }
    if(raiz-> valor < num){
        return busca(raiz->direita , num);
    }else { 
        return busca(raiz->esquerda , num);
    }
}








int main(){

    No *raiz = NULL ; 






    return 0;

}