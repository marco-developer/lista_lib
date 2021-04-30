#include <stdio.h>
#include <stdlib.h>   
#include <string.h>
#include "lista_interface.h"
#include "lista_privado.h"   

int main (void) {     
char selecionar;     
char *nome;     
Lista *lista;     
elemento *atual;  

if ((lista = (Lista *) malloc (sizeof (Lista))) == NULL) return -1;     
if ((nome = (char *) malloc (50)) == NULL) return -1;     

atual = NULL;     
selecionar = 'o';     
inicializacao (lista);     
int pos, k;     

while (selecionar != 7){         
    selecionar = menu (lista, &k);         
    switch (selecionar){           
        case 1:          
            printf ("Inserir um elemento: ");             
            scanf ("%s", nome);             
            getchar ();             
            if (lista->tamanho == 0)               
                ins_em_lista_vazia (lista, nome);             
            else
                ins_inicio_lista (lista, nome);             
            printf ("%d elementos:inicio=%s,fim=%s\n", lista->tamanho, lista->inicio->dado, lista->fim->dado);             
            exibe (lista);             
        break;           
        case 2:             
            printf ("Inserir um elemento:");             
            scanf ("%s", nome);             
            getchar ();             
            ins_fim_lista (lista, lista->fim, nome);             
            printf ("%d elementos:inicio=%s,fim=%s\n", lista->tamanho, lista->inicio->dado, lista->fim->dado);             
            exibe (lista);             
        break;           
        case 3:             
            printf ("Inserir um elemento:");             
            scanf ("%s", nome);             
            getchar ();             
            do {
                printf ("Inserir a posicao:");                 
                scanf ("%d", &pos);
            } while (pos < 1 || pos > lista->tamanho);             
            getchar ();             
            if (lista->tamanho == 1 || pos == lista->tamanho){
                k = 1;                 
                printf("-----------------------------------------------\n");                 
                printf("/!\\A insercao falhou. Utilize o menu {1|2} /!\\\n");                 
                printf("-----------------------------------------------\n");                 
                break;
            }             
            ins_lista (lista, nome, pos);             
            printf ("%d elementos:inicio=%s,fim=%s\n", lista->tamanho, lista->inicio->dado, lista->fim->dado);             
            exibe (lista);             
        break;           
        case 4:             
            remov_inicio (lista);             
            if (lista->tamanho != 0)
                printf ("%d elementos:inicio=%s,fim=%s\n", lista->tamanho, lista->inicio->dado, lista->fim->dado);             
            else 
                printf ("lista vazia\n");             
            exibe (lista);             
        break;           
        case 5:             
            do{
                printf ("Inserir a posicao: ");                 
                scanf ("%d", &pos);
            } while (pos < 1 || pos > lista->tamanho);             
            getchar ();             
            remov_na_lista (lista, pos);             
            if (lista->tamanho != 0)               
                printf ("%d elementos:inicio=%s,fim=%s\n", lista->tamanho, lista->inicio->dado, lista->fim->dado);             
            else 
                printf ("lista vazia\n");             
            exibe (lista);             
        break;           
        case 6:             
            destruir (lista);             
            printf ("A lista foi destruida: %d elementos\n", lista->tamanho);
            break;
    } 
} 
return 0;
}
