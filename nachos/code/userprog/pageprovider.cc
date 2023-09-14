#include "pageprovider.h"
#include "system.h"


PageProvider::PageProvider(){
    bitmap=new BitMap(NumPhysPages);
    numPage=-1;
}

PageProvider::~PageProvider(){
    delete bitmap;
}


int PageProvider::GetEmptyPage(){
    /*
    numPage = (rand() % (bitmap->NumClear()));
    int i=0;
    int numClear= bitmap->Find();
    if (numClear==-1){
        return -1;
    }
    while(bitmap->Test(numPage) == TRUE){
        numPage = (rand() % (bitmap->NumClear()));
        printf(" BOUCLE WHILE ITERATION : %d\n et NumPage : %d",i,numPage);
        i++;
    }
    
    bitmap->Mark(numPage);
    */
   
    numPage= bitmap->Find();

    if (numPage==-1){
        return -1;
    }
    
    memset(&(machine->mainMemory[numPage*PageSize]), 0, PageSize);
    return numPage;
}
void PageProvider::ReleasePage(int which)
{
    if (which!=-1 ){
        bitmap->Clear(which);
    }
}
int PageProvider::NumAvailPage(){
    return bitmap->NumClear();
}

