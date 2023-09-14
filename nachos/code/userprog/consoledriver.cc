#ifdef CHANGED
#include "copyright.h"
#include "system.h"
#include "consoledriver.h"
#include "synch.h"
static Semaphore *readAvail;
static Semaphore *writeDone;

static void ReadAvailHandler(void *arg) { (void) arg; readAvail->V(); }
static void WriteDoneHandler(void *arg) { (void) arg; writeDone->V(); }
ConsoleDriver::ConsoleDriver(const char *in, const char *out)
{
    readAvail = new Semaphore("read avail", 0);
    writeDone = new Semaphore("write done", 0);
    semaphore =new Semaphore("semaphore",1);
    semaphore2 =new Semaphore("semaphore2",1);
    console = new Console (in, out, ReadAvailHandler, WriteDoneHandler, NULL);
    }
ConsoleDriver::~ConsoleDriver()
{
    delete console;
    delete writeDone;
    delete readAvail;
    delete semaphore;
    delete semaphore2;
}
void ConsoleDriver::PutChar(int ch)
{

    semaphore->P();
    console->TX(ch);
    writeDone->P ();
    semaphore->V();


}
int ConsoleDriver::GetChar()
{
    semaphore2->P();
    int ch;
    readAvail->P ();	// wait for character to arrive
    ch = console->RX ();
    semaphore2->V();
    return ch;
    
// ...
}
void ConsoleDriver::PutString(const char *s)
{

    for(size_t i=0;i<strlen(s);i++){ // Pour éviter de lire un espace mémoire invalide
        PutChar(s[i]);

    }
// ...
}
void ConsoleDriver::GetString(char *s, int n)
{
    semaphore2->P();
    int i=0;
    int typedchar=0;
    char charreceived;
    while(i<n){
        
        typedchar=GetChar();
        charreceived=typedchar; 
        if (typedchar==10 || typedchar==0||  typedchar==EOF || charreceived=='\n' || charreceived=='\0'){
            s[i]='\0';
            break;
        }
        s[i]=charreceived;
        i++;
        
    }
    semaphore2->V();
}
void ConsoleDriver::PutInt(int n){
    int log = 20;
    int size=6*sizeof(int)+log;
    char buff[size];  
    snprintf(buff,size,"%f\n",(float)n);
    PutString(buff);

}

unsigned ConsoleDriver::copyStringToMachine(int to, char *from, unsigned size){

        int sizeWrite=0;
		int buff=from[sizeWrite];
		int truesize=( int ) (size);
        while(machine->WriteMem(to+sizeWrite,1,buff)){
			if (sizeWrite>=truesize){
				break;
			}
			sizeWrite+=1; 
            if (from[sizeWrite]=='\0'){
                break;
            }else{
                buff=from[sizeWrite];
            }
		}
        from[sizeWrite]='\0';
		return sizeWrite;
}

void ConsoleDriver::GetInt(int *n){
    char buff[100*sizeof(char)];
    GetString(buff,100*sizeof(char));
    long int TEST_MAX_INT=0;
    sscanf(buff,"%lu\n", &TEST_MAX_INT );
    if (TEST_MAX_INT> 32767 || TEST_MAX_INT<-32767){
        GetInt(n);
    }else{
        sscanf(buff,"%d\n", n);
    }
    
}


unsigned ConsoleDriver::copyStringFromMachine(int from, char *to, unsigned size){

		int sizeRead=0;
		int buff=0;
		int truesize=( int ) (size);
        while(machine->ReadMem(from+sizeRead,1,&buff)){
			if (sizeRead>=truesize){
				break;
			}
            char c=buff;
            if (c=='\0'){
                break;
            }else{
                to[sizeRead]=c;
            }
			sizeRead+=1;
		}
		return sizeRead;
}


#endif // CHANGED