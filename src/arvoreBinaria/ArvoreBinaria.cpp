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
            raiz->esquerda = inserir(raiz->esquerda,num);
        }else {
            raiz->direita = inserir(raiz->direita, num);
         }
        return raiz ; 
    }
}

No* buscar(No *raiz , int num){
    if(raiz == NULL){
        return NULL;
    }
    if(raiz-> valor == num){
        return raiz ; 
    }
    if(raiz->valor < num){
        return buscar(raiz->direita , num);
    }else {
        return buscar(raiz->esquerda , num);
    }
}

No* maior (No *raiz){
    if (raiz == NULL){
        return NULL;
    }
    if(raiz -> direita == NULL){
        return raiz;
    }
    return maior(raiz ->direita) ;
}

No* menor (No *raiz){
    if (raiz == NULL){
        return NULL;
    }
    if(raiz -> esquerda == NULL){
        return raiz;
    }
    return maior(raiz -> esquerda) ;
}

No *remover(No *raiz , int num){
    if(raiz == NULL){
        return NULL ; 
    }
    else {
         if(raiz->valor == num){
            //no folha
            if(raiz -> esquerda == NULL && raiz ->direita == NULL){
                free(raiz);
                return NULL;
            } else {  
                //remove o pai com dois filhos 
                if(raiz->esquerda !=NULL && raiz->direita != NULL){
                    No *aux = raiz->esquerda ; 
                    while(aux->direita != NULL){
                        aux = aux->direita;
                    }
                    raiz->valor = aux->valor ; 
                    raiz->valor = num ; 
                    raiz->esquerda = remover(raiz->esquerda , aux->valor);
                    return raiz ;
                
                }else { 
                    // remove no pai com um filho 
                    No *aux ; 
                    if(raiz->esquerda != NULL){
                        aux = raiz->esquerda;
                    }else {
                        aux = raiz->direita;
                    }
                    free(raiz);
                    return aux ; 
                }
            }
        } else {
            if(raiz->valor > num){
                raiz->esquerda = remover(raiz->esquerda,num);
            }else {
                raiz->direita = remover(raiz->direita, num);
            }
            return raiz ; 
        }
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
