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

turing * readWinners(int numberOfTuringWinner,FILE * f){ //fonction à refaire avec les bons arguments 
    turing * winners = calloc(numberOfTuringWinner,sizeof(turing));
    for(int i = 0; i < numberOfTuringWinner; ++i)
        readwinner(&winners[i],f)  //&winners[i] -> adresse d'une struct  et   readwinner à écrire 

    return winners;

    // en dessous partie à revoir  -> fonction readWinner? 
    while(feof(f)==0){
        char buffer[1024];
        fgets(buffer,1024,f);
        int k=0;
        
        while (buffer[k]=="\0"){
            int l=0;
            int m=0;
            
+

            for(int i=0; i<2;i++){
                //mettre une condition si i=0 car int et non char * 
                while(buffer[l]==";"){
                    l++;    
                    }
                char *infoStruct=malloc((l-m)*sizeof(char))
                for (int j=m;j<l-m;j++ ){
                    infoStruct[j]=buffer[j];
                }
                if(i==1):{
                    turing->nom= infoStruct;
                }
                else if (i==2)
                {
                    turing->nature=infoStruct;
                }
                
                m=l;
                l++;
            }
                
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

    turing *winners=readWinners(winner, f);

    

    fclose(f);
    fclose(output);

	return EXIT_SUCCESS;
}

