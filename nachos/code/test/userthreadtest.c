#include "syscall.h"

/*
    Lancement du programme : ./nachos -rs 1234 -d x -x ../test/userthreadtest dans le dossier userprog.

    Ce programme permet de tester la fonction ThreadCreate. Cette fonction prend en paramètre deux arguments : la fonction que l'utilisateur veut exécuter dans le nouveau
    thread qui sera crée grâce à ThreadCreate ainsi que l'argument de cette fonction.

*/

void f(int a){
    volatile int i = 0;
    
    //PutString(a);
    //PutChar(a);
    ThreadExit();
}

void f2(int b){
    volatile int i = 0;
    
    PutString("Bonjour");
    //PutChar(b);
    ThreadExit();
}

int main(){
    int i=0;
    /*for (;i<30;i++){
        ThreadCreate(f,"Bonjour");
        ThreadCreate(f2,"Coucou");
    }*/
    ThreadCreate(f,"Bonjour");
    ThreadCreate(f2,"Coucou");
    ThreadExit();
}