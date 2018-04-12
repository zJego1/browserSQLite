//<sql db="scuola" query="SELECT * FROM Studenti WHERE...">
#include "TCP.hpp"
#include "errore.h"
#include <string.h>
#define TAGSCUOLA "sql"

int main(int argc, char* argv[]){
	if(argc!=3){
		printf("USAGE: %s PORT ROOT", argv[0]);
		return -1;
	}
	int port = atoi(argv[1]);
	char* root = argv[2];
	
	ServerTCP myself(port, true);
	Connection* connection = myself.accetta();
	
}
