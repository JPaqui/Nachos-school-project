#include "syscall.h"

/*
    Lancement du programme : ./nachos -x ../test/putstring dans le dossier userprog.

    Ce programme permet de tester la fonction PutString. De la même façon que PutChar, cette fonction prend en paramètre une chaine de caractères et l'affiche
    dans la console. Comme PutString utilise PutChar, la chaine de caractères doit contenir uniquement des caractères valides afin de permettre à la fonction de fonctionner 
    correctement.

*/

void print(char * buff){
    PutString(buff);
}

int main(){
    print("");
    //print("bbbbbbbbbbbbbbbbbbbbbbbb");
    //print("aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa");
    //print("Allons dans les bois car le loup n'y est pas et si le loup y est il ne nous trouvera pas un deux trois après toi ");
    //print("He didn't say any more but we've always been unusually communicative in a reserved way and I understood that he meant a great deal more than that. In consequence I'm inclined to reserve all judgements, a habit that has opened up many curious natures to me and also made me the victim of not a few veteran bores. Etc... etc... etc...\n");
    Halt();
}