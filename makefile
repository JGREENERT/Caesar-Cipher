decrypt: decrypt.o
	gcc -Wall -std=c99 decrypt.c -o decrypt
decrypt.o: decrypt.c

cipher: cipher.o
	gcc -Wall cipher.c -o cipher
cipher.o: cipher.c

test: test1 test2

test1:
	./cipher 1 5 data.txt encrypted.dat
	./decrypt
	diff -s data.txt final.dat

test2:
	./cipher 1 5 data2.txt encrypted.dat
	./decrypt
	diff -s data2.txt final.dat

