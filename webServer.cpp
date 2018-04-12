//<sql db="scuola" query="SELECT * FROM Studenti WHERE...">
#include "TCP.hpp"
#include "errore.h"
#include <string.h>

#define RQST_CTRL "GET "
#define TAGSQL "<sql"

char* getFileName(char* request);
char* getFileContent(char* filename);
char* compileResponse(char* filecontent, char* tmp);
char* getDbName(char* filecontent);
char* concat(char* first_string,char* second_string);

int main(int argc, char* argv[]){
	if(argc!=3){
		printf("USAGE: %s PORT ROOT", argv[0]);
		return -1;
	}
	//prende porta e root del file
	int port = atoi(argv[1]);
	char* root = argv[2];
	
	//apre un socket TCP, si mette in ascolto per ricevere una request
	ServerTCP myself(port, true);
	Connection* connection = myself.accetta();
	char* rqst = connection.ricevi();
	
	if(cmpstr(strstr(rqst, RQST_CTRL), rqst)!=0){
		printf("The message received is not a HTML request\n");
		return -2;
	}
	
	//trova il filename nella richiesta, lo unisce al root
	//e ne prende il contenuto
	char* filename = getFileName(rqst);
	char* filepath = concat(root, filename);
	char* filecontent = getFileContent(filepath);
	
	char* tmp;
	if(tmp = strstr(filecontent, TAGSQL)!=NULL){
		//prende il nome del db
		char* dbName = getDbName(tmp);
		char* sqlQuery = getQuery(tmp);
		//connetti al db
		sqlite3* db;
		int rc;
		
		rc = sqlite3_open(dbName ,&db);
		//esegui query
		
		
		//crea tabella
	}
	
	char* response = compileResponse(filecontent, tmp);
	connection.invia(response);	
	
	
	
	
	//fri
	free(filecontent);
	free(filename);
	//ttata
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
	char* ret;
	
	return ret;
}

//prende il nome del db presente nel tag sql
char* getDbName(char* filecontent){
	char* ret;
	
	return ret;
}

//concatena due stringhe
char* concat(char* first_string,char* second_string) {
	char* ret=(char*)malloc(strlen(first_string)+strlen(second_string)+1);
	char* tmp = ret;

	for(;*tmp = *first_string; tmp++, first_string++) { }
	for(;*tmp = *second_string; tmp++, second_string++) { }

	return ret;
}


char* getQuery(char* ){
	
}
