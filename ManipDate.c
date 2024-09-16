#include <stdio.h>
#include <stdlib.h>

typedef enum{
    Janvier=1,
    Février,
    Mars,
    Avril,
    Mais,
    Juin,
    Juillet,
    Août,
    Spetembre,
    Octobre,
    Novembre,
    Décembre
}Mois;

typedef struct{
    unsigned short jour;
    Mois mois;
    unsigned short annee;
}Date;



void initialiseDate(Date *d) {
    
    int jour, mois, annee;

    printf("Entrez le jour : ");
    scanf("%d", &jour);
    
    printf("Entrez le mois (1-12) : ");
    scanf("%d", &mois);
    
    printf("Entrez l'année : ");
    scanf("%d", &annee);
    
    d->jour = jour;
    d->mois = (Mois)mois;
    d->annee = annee;
}

void afficheDate(Date *d){
    printf("la date est %d/ %d/ %d",d->jour, d->mois, d->annee);
}

Date creerDateParCopie(){
    Date d;
    initialiseDate(&d);
    return d;
}


Date* newDate(){
    Date* dataDate = (Date*)malloc(sizeof(Date));
    initialiseDate(dataDate);
    return dataDate;
}

int main(void){
    int nbDates;
    printf("nombre de date:")
    scanf("%i",&nbDates);
    Date *tabDate[nbDates];
    int i;
    for(i=0; i<nbDates;i++)
        tabDAte[i]=newDate();
    for(i=0; i<nbDates;i++)
        afficheDate(tabDate[i]);
    for(i=0; i<nbDates;i++)
        free(tabDate[i]);
    return 0
}


