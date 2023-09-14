#include "syscall.h"

/*
    A FAIRE

*/
int f(void* a){
    PutString(a);
    ThreadExit();
}

int main(){
    //PutChar('a');
    PutString("Bonjour");
    ThreadCreate(f,"Coucou");
    ThreadExit();
}