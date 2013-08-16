CFLAGS=-I/home/yans/code/valgrind-3.8.1/inst/include/valgrind --std=c99
LDFLAGS=-L/home/yans/code/valgrind-3.8.1/inst/lib/valgrind -lvex-amd64-linux -largtable2
CC=gcc

angr: common.o main.o vexir.o
	gcc $+ $(LDFLAGS) -o angr

clean:
	rm -f v *.o
