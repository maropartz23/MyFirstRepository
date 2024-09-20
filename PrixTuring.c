#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

 struct prixTuring{
        unsigned short annee;
        char * nom;
        char * nature;
    };

    typedef struct prixTuring turing;


int numberOfWinners(FILE * f){
    int nbWinners=0;
    char buffer[1024];
    while (feof(f)==0){
        fgets(buffer,1024,f);
        nbWinners++;
    }
    return nbWinners;
    
}

int main(int argc, char** argv){

	char filename[] = "turingWinners.csv";
    char outputFilename[] = "out.csv";
    FILE* f;
    FILE* output;

    f = fopen(filename, "r");
    output = fopen(outputFilename, "w");
    char * line;
    

    if(f==NULL){
        printf("Code de l'erreur: %d\n",  errno);
    }
    else{
        while (feof(f)==0)
        {
            char lettre = fgetc(f);
            putc(lettre, output);
            
        }
        
    }

    int winner = numberOfWinners(f);
    printf("le nombre de vainceur est: %d",winner);

    fclose(f);
    fclose(output);

	return EXIT_SUCCESS;
}

