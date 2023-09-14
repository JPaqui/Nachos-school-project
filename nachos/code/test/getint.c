#include "syscall.h"

/*
    Lancement du programme : ./nachos -x ../test/getint dans le dossier userprog.

    Ce programme permet de tester la fonction GetInt. Cette fonction prend en paramètre l'entier écrit dans la console par l'utilisateur et ne renvoie rien.
    Pour l'afficher en retour, il faut utiliser la fonction PutInt.

*/

int main(){
  int a;
  GetInt(&a);
  PutInt(a);
    
}