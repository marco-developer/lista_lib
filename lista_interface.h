typedef struct ElementoLista elemento;
typedef struct ListaDetectada Lista;

/* inicializacao da lista */   
void inicializacao (Lista * lista);   

/* INSERÇÃO */   

/*insercao em lista vazia */   
int ins_em_lista_vazia (Lista * lista, char *dado);   

/* insercao no inicio da lista */   
int ins_inicio_lista (Lista * lista, char *dado);   

/* insercao no fim da lista */   
int ins_fim_lista (Lista * lista, elemento * atual, char *dado);   

/* Insercao em outro lugar */   
int ins_lista (Lista * lista, char *dado, int pos);   

/* REMOÇÃO */   

int remov_inicio (Lista * lista);   
int remov_na_lista (Lista * lista, int pos);   

int menu (Lista *lista,int *k);   
void exibir (Lista * lista);   
void destruir (Lista * lista);   
 