all: Server Client

Server: ServerFile.c ClientServerwithfile.h
	gcc -o Server.out ServerFile.c -lrt
	
Client: ClientFile.c ClientServerwithfile.h
	gcc -o Client.out ClientFile.c -lrt
	
runClient:
	./Client.out

runServer:
	./Server.out

clean:
	rm -rf *.out *.o
