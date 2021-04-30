#include <stdio.h>
#include <stdlib.h>   
#include <string.h>
#include "lista_interface.h"
#include "lista_privado.h"

void inicializacao (Lista * lista) {     
    lista->inicio = NULL;     
    lista->fim = NULL;     
    lista->tamanho = 0;   
}

/*insercao em lista vazia*/
int ins_em_lista_vazia (Lista * lista, char *dado){     
    elemento *novo_elemento;

    if ((novo_elemento = (elemento *) malloc (sizeof (elemento))) == NULL) return -1;     
    if ((novo_elemento->dado = (char *) malloc (50 * sizeof (char))) == NULL) return -1;     
    
    strcpy (novo_elemento->dado, dado);

    novo_elemento->seguinte = NULL;
    lista->inicio = novo_elemento;
    lista->fim = novo_elemento;
    lista->tamanho++;
    
    return 0;
}

/* insercao no inicio da  lista */   
int ins_inicio_lista (Lista * lista, char *dado){     
    elemento *novo_elemento;

    if ((novo_elemento = (elemento *) malloc (sizeof (elemento))) == NULL) return -1;     
    if ((novo_elemento->dado = (char *) malloc (50 * sizeof (char))) == NULL) return -1;     
    
    strcpy (novo_elemento->dado, dado);

    novo_elemento->seguinte = lista->inicio;
    lista->inicio = novo_elemento;
    lista->tamanho++;

    return 0;   
}

/*insercao no fim da lista */   
int ins_fim_lista (Lista * lista, elemento * atual, char *dado){     
    elemento *novo_elemento;

    if ((novo_elemento = (elemento *) malloc (sizeof (elemento))) == NULL) return -1;     
    if ((novo_elemento->dado = (char *) malloc (50 * sizeof (char))) == NULL) return -1;     
    
    strcpy (novo_elemento->dado, dado);
    
    atual->seguinte = novo_elemento;
    novo_elemento->seguinte = NULL;
    lista->fim = novo_elemento;
    lista->tamanho++;

    return 0;   
}

/* insercao na posicao solicitada */   
int ins_lista (Lista * lista, char *dado, int pos){     
    if (lista->tamanho < 2) return -1;     
    if (pos < 1 || pos >= lista->tamanho) return -1;     

    elemento *atual;
    elemento *novo_elemento;
    
    int i;
    if ((novo_elemento = (elemento *) malloc (sizeof (elemento))) == NULL) return -1;     
    if ((novo_elemento->dado = (char *) malloc (50 * sizeof (char))) == NULL) return -1;

    atual = lista->inicio;
    for (i = 1; i < pos; ++i)
        atual= atual->seguinte;
    if (atual->seguinte == NULL) return -1;     

    strcpy (novo_elemento->dado, dado);     

    novo_elemento->seguinte = atual->seguinte;     
    atual->seguinte = novo_elemento;     
    lista->tamanho++;     
    
    return 0;   
}

/*Remocao no inicio da lista */   
int remov_inicio (Lista * lista){     
    if (lista->tamanho == 0) return -1;     
    
    elemento *remov_elemento;     
    
    remov_elemento = lista->inicio;
    lista->inicio = lista->inicio->seguinte;
    
    if (lista->tamanho == 1) lista->fim = NULL;     
    free (remov_elemento->dado);
    free (remov_elemento);
    lista->tamanho--;
    return 0;
}

/* Remocao de elemento depois da posicao solicitada */   
int remov_na_lista (Lista * lista, int pos){     
    if (lista->tamanho <= 1 || pos < 1 || pos >= lista->tamanho) return -1;     
    
    int i;
    
    elemento *atual;     
    elemento *remov_elemento;     
    
    atual = lista->inicio;     
    for (i = 1; i < pos; ++i)
        atual = atual->seguinte;     
    
    remov_elemento = atual->seguinte;     
    atual->seguinte = atual->seguinte->seguinte;
    
    if(atual->seguinte == NULL) lista->fim = atual;     
    free (remov_elemento->dado);     
    free (remov_elemento);     
    lista->tamanho--;

    return 0;
}   

/* Exibicao da lista */   
void exibe (Lista * lista){
    elemento *atual;     
    atual = lista->inicio;     
    while (atual != NULL){         
        printf ("%p - %s\n", atual, atual->dado);         
        atual = atual->seguinte;     
    }   
}   

/*Destruir lista */   
void destruir (Lista * lista){     
    while (lista->tamanho > 0)
    remov_inicio (lista);   
}   
int menu (Lista *lista,int *k){     
    int selecionar;     

    printf("********** MENU **********\n");     

    if (lista->tamanho == 0){       
        printf ("1. Adicao do 1° elemento\n");       
        printf ("2. Fechar\n");     
    } else if(lista->tamanho == 1 || *k == 1){

        printf ("1. Insercao no inicio da lista\n");
        printf ("2. Insercao no fim da lista\n");
        printf ("4. Remocao no inicio da lista\n");
        printf ("6. Destruir a lista\n");
        printf ("7. Fechar\n");
    } else {       
        printf ("1. Insercao no inicio da lista\n");       
        printf ("2. Insercao no fim da lista\n");       
        printf ("3. Insercao após a posicao especificada\n");       
        printf ("4. Remocao no inicio da lista\n");       
        printf ("5. Remocao após a posicao especificada\n");       
        printf ("6. Destruir a lista\n");       
        printf ("7. Fechar\n");     
    }     
    
    printf ("\n\n Selecionar: ");     
    scanf ("%d", &selecionar);     
    getchar();     
    
    if(lista->tamanho == 0 && selecionar == 2) selecionar = 7;

    return selecionar;   
}   

/* -------- FIM lista_function.h --------- */ 