#ifdef CHANGED
#include "userthread.h"
#include "thread.h"
#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include "noff.h"
#include "consoledriver.h"
#include "syscall.h"
#include "bitmap.h"


static void StartUserThread(void *schmurtz){

    int* tab = (int *)schmurtz;
    int f = tab[0] ;
    int arg =tab[1] ;
    int stackPos=tab[2];

    int i;
    for (i = 0; i < NumTotalRegs; i++)
        machine->WriteRegister (i, 0);

    machine->WriteRegister (PCReg, f);
    DEBUG('x',"écriture de %d\n",f);

    machine->WriteRegister (NextPCReg, machine->ReadRegister(PCReg) + 4);
    machine->WriteRegister (4,arg );
    DEBUG('x',"écriture de %d\n",arg);

    machine->WriteRegister (StackReg, stackPos);
    DEBUG ('x', "Initializing stack register to 0x%x\n",stackPos);

    free(schmurtz);
    machine->DumpMem("threads.svg");
    machine->Run();
}

int do_ThreadCreate(int f, int arg){
    currentThread->space->semaphore->Acquire();
    int find = currentThread->space->bitmap->Find();

    if(find != -1){
        Thread *newThread = new Thread("newThread");
        newThread->space = currentThread->space;
        newThread->find =find;

        int *tab =(int *) malloc(3*sizeof(int));
        int NbStack=newThread->find*256;
        int stackPos = newThread->space->AllocateUserStack(NbStack);

        tab[0]=f;
        tab[1]=arg;
        tab[2]=stackPos;

        newThread->space->cptThread=newThread->space->cptThread+1;
        newThread->Start(StartUserThread,(void *) tab);
        currentThread->space->semaphore->Release();
        return 1;
    }else{
        currentThread->space->semaphore->Release();
        return 0;
    }
}

void do_ThreadExit(void){
    if (currentThread->space->cptThread>1){

        currentThread->space->semaphore->Acquire();
        currentThread->space->cptThread=currentThread->space->cptThread-1;
        currentThread->space->bitmap->Clear(currentThread->find);

        DEBUG('x',"NON EXIT");
        
        currentThread->space->semaphore->Release();
        currentThread->Finish();
    }else{
        DEBUG('x',"EXIT");

        delete currentThread->space->bitmap;
        delete currentThread->space->semaphore;
        delete currentThread->space;
        interrupt->Powerdown();
    }
}
#endif // CHANGED