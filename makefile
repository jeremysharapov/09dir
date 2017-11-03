all: dir.o
	gcc -o dir dir.o

dir.o: dir.c
	gcc -c dir.c

clean:
	rm -f *.o *~ dir
run: all
	./dir
