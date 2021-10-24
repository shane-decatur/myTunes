all: main.o library.o songnode.o
	gcc main.o library.o songnode.o

main.o: main.c songnode.h library.h
	gcc -c main.c

library.o: library.c library.h songnode.h
	gcc -c library.c

songnode.o: songnode.c songnode.h
	gcc -c songnode.c

run:
	./a.out
