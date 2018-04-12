//<sql db="scuola" query="SELECT * FROM Studenti WHERE...">
#include "TCP.hpp"
#include "errore.h"
#include <string.h>

#define RQST_CTRL "GET "
#define TAGSQL "<sql"

int main(int argc, char* argv[]){
	if(argc!=3){
		printf("USAGE: %s PORT ROOT", argv[0]);
		return -1;
	}
	int port = atoi(argv[1]);
	char* root = argv[2];
	
	ServerTCP myself(port, true);
	Connection* connection = myself.accetta();
	char* rqst = connection.ricevi();
	
	if(cmpstr(strstr(rqst, RQST_CTRL), rqst)!=0){
		printf("The message received is not a HTML request\n");
		return -2;
	}
	
	char* filename = getFileName(rqst);
	char* filecontent = getFileContent(filename);
	char* tmp;
	
	if(tmp = strstr(filecontent, TAGSQL)!=NULL){
		//connetti al db
		//esegui query
		//crea tabella A pointer to the first occurrence in str1 of the entire sequence of characters specified in str2, or a null pointer if the sequence is not present in str1.
	}
	
	char* response = compileResponse(filecontent, tmp);
	connection.invia(response);
	


	
	
	
	
	
	
	
	
	
	free(filecontent);
	free(filename);
	delete(connection);
	delete(myself);
}

//riceve la richiesta e restituisce il nome del file richiesto
char* getFileName(char* request){
	char* ret[MAX_STR];
	request+=4;
	int i=0;
	while(*request && *request!='\n'){
		ret[i] = *request;
		ret++;
		i++;
	}
	ret[i]='\0';
	return ret;
}

//inserisce il contenuto in un file in una stringa
char* getFileContent(char* filename){
	FILE *f = fopen(filename, "r");
	fseek(f, 0, SEEK_END);
	long fsize = ftell(f);
	fseek(f, 0, SEEK_SET);  //same as rewind(f);

	char *string = malloc(fsize + 1);
	fread(string, fsize, 1, f);
	fclose(f);

	string[fsize] = '\0';
}

//compila la risposta da inviare al client
char* compileResponse(char* filecontent, char* tmp){
	
}
