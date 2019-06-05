all:
	nasm -g -felf64 phase_3.asm -l phase_3.lst -o phase_3.o
	gcc -no-pie -m64 phase_3.o -g -o main -pthread 
	./main
clean:
	rm *.o *.lst 
redo:
	nasm -g -felf64 redo.asm -l redo.lst -o redo.o
	gcc -no-pie -m64 redo.o -g -o main -pthread 
	./main

