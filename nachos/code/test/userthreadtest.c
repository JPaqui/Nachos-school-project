#include "syscall.h"

/*
    Lancement du programme : ./nachos -rs 1234 -x ../test/userthreadtest dans le dossier userprog.

    Ce programme permet de tester les fonctions nécessaires au bon fonctionnement des threads utilisateurs: ThreadCreate, ThreadExit ainsi que les fonctions pour les sémaphores
    utilisateurs.

    ThreadCreate prend en paramètre deux argument : la fonction que l'utilisateur veut exécuter dans le nouveau thread qui sera crée grâce ainsi qu'un argument de cette fonction.
    Elle retourne 1 si la création s'est faite correctement, 0 si la création n'a pas pu être effectuée par manque d'espace mémoire.

    ThreadExit ne prend pas d'argument et doit être appelée à la fin d'une fonction afin de terminer le thread utilisateur.

    createSemaphore crée un sémaphore, deleteSemaphore le détruit.
    P permet de prendre un token et de bloquer les threads suivants.
    V permet de rendre un token et de libérer un des threads dormants.

*/

int f3(int x, int y){
    return x * y;
}

void f( void* a){
    createSemaphore();
    P();
    //PutInt(f3(4,6));
    PutString(a);
    V();
    deleteSemaphore();
    ThreadExit();
}

void f2(void * b){
    createSemaphore();
    P();
    PutString(b);
    //PutInt(f3(4,6));
    V();
    deleteSemaphore();
    ThreadExit();
}
int main(){
    //int i=0;
    //for(; i<4;i++){
    createSemaphore();
    ThreadCreate(f,"Bonjour");
    ThreadCreate(f,"Coucou");
    deleteSemaphore();
    //}
    ThreadExit();
    return 3;
}