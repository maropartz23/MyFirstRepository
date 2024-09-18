//Martin ROPARTZ

#include <stdio.h>

int* repeat(int t1[],int t2[], int tailletableau){
    int *p;
    int somme=0;
    for (int i=0; i< tailletableau ;i++){
            somme += t1[i];
    }
    int tab[somme];
    for (int i=0;i< tailletableau; i++){
        for(int j=0; j<t1[i];j++){
            tab[i+j]=t2[i];
        }
    }
    //for (int i=0; i< somme; i++){
    p=tab;
    //}
     
    return p;
    
}

int * main(void){
    int t1[3]={1,7,2};
    int t2[3]={1,2,3};
    return repeat(t1,t2,3);

}