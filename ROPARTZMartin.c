//Martin ROPARTZ

#include <stdio.h>
#include <stdlib.h>



int* repeat(int t1[],int t2[], int tailletableau, int *somme){
    *somme=0;
    for (int i=0; i< tailletableau ;i++){
            *somme += t1[i];
    }
    int * res= malloc(*somme*sizeof(int)); 
    int current = 0;
    for (int i=0;i< tailletableau; i++){
        for(int j=0; j<t1[i];j++){
            res[current]=t2[i];
            current++;
        }
    }
   
    return res;
    
}

int main(void){
    int t1[3]={1,7,2};
    int t2[3]={1,2,3};

    int tailleRes;
    int *res = repeat(t1,t2,3,&tailleRes);

    for (int i=0; i< tailleRes ;i++){
        printf("%d\n",res[i]);
    }

    free(res);
    return 0;

}

