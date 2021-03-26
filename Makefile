CC := gcc
.c.o:
	$(CC) -Wall -o gtype gtype.c 
clean:
	rm -f BF
