#include "syscall.h"

/*
    Lancement du programme : ./nachos -x ../test/getchar dans le dossier userprog.

    Ce programme permet de tester la fonction GetChar. Cette fonction ne prend pas de paramètre. Une fois exécutée, elle attend qu'un caractère soit écrit par l'utilisateur
    dans la console. Une fois qu'un caractère valide a été écrit, elle retourne sa valeur immédiatement. Donc, pour récupérer ce caractère il faut une variable pour stocker 
    la valeur de retour.

*/

int main(){
    int a=GetChar();
    PutChar(a);
    Halt();
}