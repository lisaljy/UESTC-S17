#include <stdlib.h>
#include <stdio.h>

int main(){
    printf("Father is created\n\n");

    fork();//create a child process

    printf("Child is created\n\n");

    int i; scanf("%d",&i);   //prevent exiting
    return 0;
}
