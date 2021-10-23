all: testnode.o songnode.o
	gcc testnode.o songnode.o

testnode.o: testnode.c songnode.h
	gcc -c testnode.c

songnode.o: songnode.c songnode.h
	gcc -c songnode.c

run:
	./a.out
