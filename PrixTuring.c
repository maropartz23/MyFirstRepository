#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

 typedef struct {
        unsigned short annee;
        char * nom;
        char * nature;
    }turing;


typedef struct{
    turing * winners;
    int numberOfWinners;
}Winners;


int numberOfWinners(FILE * f){
    int nbWinners=0;
    char buffer[1024];
    while (feof(f)==0){
        fgets(buffer,1024,f);
        nbWinners++;
    }
    return nbWinners;
    
}

void readWinners(Winners * listWinners,FILE * f){
    int maxline =1024;
    int nbrWinners = numberOfWinners(f);
    int i =0;
    char * ligne;

    ligne = malloc(maxline*sizeof(char));
    listWinners->winners = malloc(nbrWinners*sizeof(turing));
    listWinners->numberOfWinners = nbrWinners;

    while(fgets(ligne, maxline, f) != NULL) {
		if(strcmp(ligne, "\n") != 0){
			char *token;

			token = strtok(ligne, ";");
			listWinners->winners[i].annee = atoi(token);

			token = strtok(NULL, ";");
			listWinners->winners[i].nom = strdup(token);

			token = strtok(NULL, "\n");
			listWinners->winners[i].nature = strdup(token);

			i++;
		}
    }
}

void printYear(int year){
    char tabYear[5];
    sprintf(tabYear, "%d", year);
}

void printWinners(FILE * f,Winners * listOfWinners){
    int maxline = 1024;
    int nbrOfWinners = numberOfWinners(f);
    char * ligne;

    rewind(f);
    ligne=malloc(nbrOfWinners*sizeof(char));

    for(int i=0; i< nbrOfWinners; i++){
            int year = listOfWinners->winners[i].annee;
            char tabYear[5];
            sprintf(tabYear, "%d", year);
            sprintf(ligne,"%s;%s;%s\n",tabYear,listOfWinners->winners[i].nom, listOfWinners->winners[i].nature);
            fputs(ligne, f );
            printf("%s", ligne);
    }
    free(ligne);
}

void infosAnnee(Winners * listOfWinners, unsigned short year){
    int nbrOfWinners = listOfWinners->numberOfWinners;
    for(int i =0; i< nbrOfWinners; i++){
        if(listOfWinners->winners[i].annee==year){
            printf("l'année %hu, le(s) gagnant(s) ont été: %s\nNature des travaux:%s",year, listOfWinners->winners[i].nom, listOfWinners->winners[i].nature );
        }
    }
    
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

    Winners * listOfWinners;
    readWinners(listOfWinners, f);

    Winners * winners;
    readWinners(winners, f);


    Winners * WinnersPrint;
    printWinners(f, WinnersPrint);
    infosAnnee(WinnersPrint, 2003);

    

    fclose(f);
    fclose(output);

	return EXIT_SUCCESS;
}

