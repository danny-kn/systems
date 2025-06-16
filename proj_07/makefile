all: encrypt_copy decrypt_copy mangled_decrypt_copy lab2.zip

encrypt_copy: encrypt_copy.o main.o
	gcc encrypt_copy.o main.o -o encrypt_copy

encrypt_copy.o: encrypt_copy.c
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c -o encrypt_copy.o encrypt_copy.c

decrypt_copy: decrypt_copy.o main.o
	gcc decrypt_copy.o main.o -o decrypt_copy

decrypt_copy.o: decrypt_copy.c
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c -o decrypt_copy.o decrypt_copy.c

mangled_decrypt_copy: mangled_decrypt_copy.o main.o
	gcc mangled_decrypt_copy.o main.o -o mangled_decrypt_copy

mangled_decrypt_copy.o: mangled_decrypt_copy.c
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c -o mangled_decrypt_copy.o mangled_decrypt_copy.c

main.o: main.c
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -g -c -o main.o main.c

lab2.zip: readme makefile *.h *.c *.input *.output *.expected
	echo "Creating lab2.zip ..."
	zip lab2.zip readme makefile *.h *.c *.input *.output *.expected
	echo "lab2.zip created."

clean:
	rm -rf encrypt_copy decrypt_copy mangled_decrypt_copy lab2.zip *.o
