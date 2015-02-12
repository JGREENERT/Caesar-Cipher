cipher: cipher.o
	gcc cipher.o -o cipher
cipher.o: cipher.c

decrypt: decrypt.o
	gcc -Wall -std=c99 decrypt.c -o decrypt
decrypt.o: decrypt.c

test: test1 test2
test1: 
	./cipher 1 5 data.txt data.out
test2:
	./cipher 2 5 data.out data.bak
