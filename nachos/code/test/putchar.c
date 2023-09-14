#include "syscall.h"

/*
    Lancement du programme : ./nachos -x ../test/putchar dans le dossier userprog.

    Ce programme permet de tester la fonction PutChar. Cette fonction prend en paramètre un code entier représentant un caractère et l'affiche dans la console.
    Plus précisément, l'entier doit correspondre à un code d'un caractère ascii, sinon la fonction n'affiche rien dans la console.

*/


void print(char c, int n){
    int i;
    for (i = 0; i < n; i++) {
        PutChar(c + i);
    }
    PutChar('\n');
}

int main(){
    //print('a',4);
    //print('a',1000);
    //PutChar('a');
    PutChar(255);
    //Halt();
}