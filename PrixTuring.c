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
    rewind(f);
    int nbWinners=0;
    char buffer[1024];
    while (feof(f)==0){
        char * ligne;
        ligne= fgets(buffer, 1023, f);
        if (ligne !=NULL){
            nbWinners++;
        }     
    }
    return nbWinners;
    
}

void readWinners(Winners * listWinners,FILE * f){
    rewind(f);
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

void printWinners(FILE * out,Winners * listOfWinners){
    rewind(out);
    int maxline = 1024;
    int nbrOfWinners = listOfWinners->numberOfWinners;
    char * ligne;
    ligne=malloc(maxline*sizeof(char));

    for(int i=0; i< nbrOfWinners; i++){
            //ligne[0]='\0';
            int year = listOfWinners->winners[i].annee;
            char tabYear[5];
            sprintf(tabYear, "%d", year);
            sprintf(ligne,"%s;%s;%s\n",tabYear,listOfWinners->winners[i].nom, listOfWinners->winners[i].nature);
            fputs(ligne, out);
            printf("%s", ligne);
    }
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
    

    // if(f==NULL){
    //     printf("Code de l'erreur: %d\n",  errno);
    // }
    // else{
    //     while (feof(f)==0)
    //     {
    //         char lettre = fgetc(f);
    //         putc(lettre, output);
            
    //     }
        
    // }

    int winner = numberOfWinners(f);
    printf("le nombre de vainceur est: %d\n",winner);

    Winners listOfWinners;
    readWinners(&listOfWinners, f);

    printWinners(output, &listOfWinners);
    infosAnnee(&listOfWinners, 2003);

    

    fclose(f);
    fclose(output);

	return EXIT_SUCCESS;

    //  char *filename = NULL;
    // char *outputFilename = NULL;
    // int annee = -1; 
    // int sort = 0; 

    // for (int i = 1; i < argc; i++) {
    //     if (strcmp(argv[i], "-o") == 0) {
    //         if (i + 1 < argc) {
    //             outputFilename = argv[++i];  
    //         } else {
    //             fprintf(stderr, "L'option -o nécessite un nom de fichier.\n");
    //             return EXIT_FAILURE;
    //         }
    //     } else if (strcmp(argv[i], "--info") == 0) {
    //         if (i + 1 < argc) {
    //             annee = atoi(argv[++i]);  
    //         } else {
    //             fprintf(stderr, "L'option --info nécessite une année.\n");
    //             return EXIT_FAILURE;
    //         }
    //     } else if (strcmp(argv[i], "--sort") == 0) {
    //         sort = 1;  
    //     } else {
    //         filename = argv[i];  
    //     }
    // }

    // if (filename == NULL) {
    //     fprintf(stderr, "Aucun fichier d'entrée spécifié.\n");
    //     return EXIT_FAILURE;
    // }

    // FILE *dataFile = fopen(filename, "r");
    // if (dataFile == NULL) {
    //     perror("Erreur lors de l'ouverture du fichier d'entrée");
    //     return EXIT_FAILURE;
    // }

    // Winners listeGagnants;
    // readWinners( &listeGagnants, dataFile);
    // fclose(dataFile);

    // if (annee != -1) {
    //     infosAnnee(&listeGagnants, annee);  
    // }

    // // if (sort == 1) {
    // //     sortTuringWinnersByYear(&listeGagnants);
    // // }

    // if (outputFilename != NULL) {
    //     FILE *outputFile = fopen(outputFilename, "w");
    //     if (outputFile == NULL) {
    //         perror("Erreur lors de l'ouverture du fichier de sortie");
    //         free(listeGagnants.winners); 
    //         return EXIT_FAILURE;
    //     }

    //     printWinners(outputFile, &listeGagnants);  
    //     fclose(outputFile);  
    // }

    // free(listeGagnants.winners);

    // return EXIT_SUCCESS;

}

