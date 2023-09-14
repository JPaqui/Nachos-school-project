#include "syscall.h"

/*
    Lancement du programme : ./nachos -x ../test/putint dans le dossier userprog.

    Ce programme permet de tester la fonction PutInt. Cette fonction prend en paramètre un argument : l'entier que l'utilisateur veut voir s'afficher dans la console 
    après l'exécution. Fonctionne avec des entiers positifs ou négatifs plus ou moins grands.
    
*/

int main(){

    PutInt(-100000000);
    /*int i;
    for(i = 50; i >= -50; i--){
        PutInt(i);
    }*/
    //PutInt(-64);
    
}