all : read write
read: sharedmemoryread.c sharedmemory.h
	gcc -o read.out sharedmemoryread.c -lpthread -lrt
	
write: sharedmemorywrite.c sharedmemory.h
	gcc -o write.out sharedmemorywrite.c -lpthread -lrt
	
runread:
	./read.out

runwrite:
	./write.out

clean:
	rm -rf *.out *.o
