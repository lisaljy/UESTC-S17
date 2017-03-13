#include <stdlib.h>
#include <stdio.h>
//#include <signal.h>
//#include <sys/prctl.h>

int main(){
    printf("Father is created\n\n");

    fork();//create a child process

    //prctl(PR_SET_PDEATHSIG,SIGHUP);

    printf("Child is created\n\n");

    int i; scanf("%d",&i);   //prevent exiting
    return 0;
}
