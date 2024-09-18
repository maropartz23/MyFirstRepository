#include <stdio.h>

// 1 bottle of beer on the wall, 1 bottle of beer.
// Take it down and pass it around, no more bottles of beer on the wall.

// No more bottles of beer on the wall, no more bottles of beer.
// Go to the store and buy some more, 99 bottles of beer on the wall.

void main(void){
    int i;
    for(i=99; i>1;i--){
        if (i==1){
            printf("1 bottle of beer on the wall, 1 bottle of beer.\n
            Take it down and pass it around, no more bottles of beer on the wall.\n
            No more bottles of beer on the wall, no more bottles of beer.\n
            Go to the store and buy some more, 99 bottles of beer on the wall.");
        }
        printf("%d bottles of beer on the wall, %d bottles of beer\n 
        Take it down and pass it around,%d bottles of beer on the wall",i,i,i-1);
    }
}