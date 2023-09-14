#include "userthread.h"
#include "thread.h"
#include "copyright.h"
#include "system.h"
#include "addrspace.h"
#include "noff.h"
#include "userfork.h"
void StartUserProc(void * arg){
    (void *)arg;
    currentThread->space->InitRegisters();
    DEBUG('s',"puis ici \n");
    machine->DumpMem("addrspace.svg");
    machine->Run();
}
int do_ForkExec(const char *s){
    printf("%s\n",s);
    OpenFile * openfile = fileSystem->Open(s);
    if (openfile == NULL)
      {
          printf ("Unable to open file %s\n", s);
          return 0;
      } 
    AddrSpace * addrspace= new AddrSpace(openfile);
    Thread * thread = new Thread(s);
    DEBUG('o', "valeur du bitmap: %d\n",currentThread->find);
    thread->space= addrspace;
    //thread->space->semaphore->Acquire();
    delete openfile;
    
    DEBUG('s',"on est là \n");
    thread->Start(StartUserProc, (void *)NULL);
    //thread->space->semaphore->Release();
    return 1;
}
