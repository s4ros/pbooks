#ifndef PHONEBOOK_H
#define PHONEBOOK_H

#include "book.h"
#include "phonedata.h"
#include <fstream>

class CPhoneBook : public IBook
{
    private:
        CPhoneData *list;
        string filename;
    public:
        CPhoneBook();
        ~CPhoneBook();

        CPhoneData *getList() const;
        void setList(CPhoneData *pnew);
        void attachToList(CPhoneData **proot, CPhoneData *pnew);
        void add(string tab[]);
        void edit(int num, string tab[]);
        void del(int num);
        friend ostream & operator<< (ostream &wyjscie, const CPhoneBook &book);
};

#endif
