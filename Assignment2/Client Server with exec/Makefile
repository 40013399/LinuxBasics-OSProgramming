all: Server Client

Server: Serverexec.c clientserverexec.h
	gcc -o Server.out Serverexec.c -lrt
	
Client: Clientexec.c clientserverexec.h
	gcc -o Client.out Clientexec.c -lrt
	
runClient:
	./Client.out

runServer:
	./Server.out

clean:
	rm -rf *.out *.o
