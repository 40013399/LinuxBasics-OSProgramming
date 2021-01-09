all: pipe pipe1 pipe2

pipe: pipe.c pipe.h
	gcc -o pipe.out pipe.c -lrt
	
pipe1: pipe1.c pipe.h
	gcc -o pipe1.out pipe1.c -lrt
	
pipe2: pipe2.c pipe.h
	gcc -o pipe2.out pipe2.c -lrt
	
runpipe:
	./pipe.out

runpipe1:
	./pipe1.out

runpipe2:
	./pipe2.out

clean:
	rm -rf *.out *.o
