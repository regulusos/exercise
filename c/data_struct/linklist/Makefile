CFLAGS = -fno-builtin -g
all:
	gcc $(CFLAGS) -c *.c
	gcc $(CFLAGS) -o exe *.o
clean:
	rm -fv *.o 
	rm exe || rm a.out
