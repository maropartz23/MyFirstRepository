#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <assert.h>

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// MAIN
// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

int main(int argc, char** argv){

    
    struct prixTuring{
        int annee;
        char nom;
        char nature;
    };

    typedef struct prixTuring turing;

    

	char filename[] = "turingWinners.csv";
	char outputFilename[] = "out.csv";

    // TODO

	return EXIT_SUCCESS;
}