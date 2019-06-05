all:
	nasm -g -felf64 for_loop_version.asm -l for_loop_version.lst -o for_loop_version.o
	gcc -no-pie -m64 for_loop_version.o -g -o main -pthread 
	./main

