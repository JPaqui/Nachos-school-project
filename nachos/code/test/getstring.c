#include "syscall.h"

/*
    Lancement du programme : ./nachos -x ../test/getstring dans le dossier userprog.

    Ce programme permet de tester la fonction GetString. Cette fonction prend en paramètre deux arguments. Le premier étant le buffer qui stockera la chaine de caractères
    entrée par l'utilisateur, le deuxième est taille de la chaine de caractères maximale que la fonction peut lire en une fois.
    
*/

int main(){
    char  chaine[50];
    GetString(chaine, 15);
    PutString(chaine);
    Halt();
    
}