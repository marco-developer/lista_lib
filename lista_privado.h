typedef struct ElementoLista   
{   
  char *dado;   
  struct ElementoLista *seguinte;   
} elemento;

typedef struct ListaDetectada
{
  elemento *inicio;
  elemento *fim;
  int tamanho; 
} Lista;