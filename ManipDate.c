#include <stdio.h>

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
    int jour;
    Mois mois;
    int annee;
}Date;

int main(void){
    Date d;
    initialiseDate(&d);
    afficheDate(&d);
}

void InitialiseDate(Date *d) {
    
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
    printf("la date est %d",d->jour," %d", Mois(d->mois), " %d", d->annee)
}


