#ifndef PUBBOOK_H
#define PUBBOOK_H

#include "book.h"
#include "pubdata.h"
#include <fstream>

class CPubBook : public IBook
{
    private:
        CPubData *list;
        string filename;
    public:
        CPubBook();
        ~CPubBook();

        CPubData *getList() const;
        void setList(CPubData *pnew);
        void attachToList(CPubData **proot, CPubData *pnew);
        void add(string tab[]);
        void edit(int num, string tab[]);
        void del(int num);
        friend ostream & operator<< (ostream &wyjscie, const CPubBook &book);
};

#endif
