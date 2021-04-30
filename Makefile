CC=gcc
FLAGS=-Wall -g

default: app

lista.o: lista.c lista_interface.h lista_privado.h
	$(CC) $(FLAGS) -c lista.c -o lista.o

app: main.c lista.o
	$(CC) $(FLAGS) main.c lista.o -o app
	

clean:
	rm -f *.o lista