all: main lab4.zip

main: main.o Stack1.o Stack2.o
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -pg main.o Stack1.o Stack2.o -o main

main.o: main.c
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -pg -c -o main.o main.c

Stack1.o: Stack1.c
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -pg -c -o Stack1.o Stack1.c

Stack2.o: Stack2.c
	gcc -ansi -pedantic -Wimplicit-function-declaration -Wreturn-type -O -pg -c -o Stack2.o Stack2.c

lab4.zip: readme makefile *.h *.c *.txt *.out
	echo "Creating lab4.zip ..."
	zip lab4.zip readme makefile *.h *.c *.txt *.out
	echo "lab4.zip created."

clean:
	rm -rf main *.o lab4.zip
