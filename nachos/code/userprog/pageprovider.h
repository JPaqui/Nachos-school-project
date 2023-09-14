#ifndef PAGEPROVIDER_H
#define PAGEPROVIDER_H

#include "bitmap.h"

class PageProvider:public dontcopythis
{
    public:
        PageProvider ();
        ~PageProvider ();
        int GetEmptyPage();
        void ReleasePage(int which);
        int NumAvailPage();
    private:
        BitMap * bitmap;
        int numPage;
        
};

#endif