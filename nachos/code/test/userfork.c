#include "syscall.h"


int main(){
    int i=0;
    for (;i<2;i++){
        ForkExec("../test/putchar");
        //ForkExec("../test/matmult");
        ForkExec("../test/userthreadtest");
    }
    //while(1);
    return 3;
}