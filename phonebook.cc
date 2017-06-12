#include "phonebook.h"
#include <iostream>

/** funkcja sluzy TYLKO do zapisywania do pliku **/
ostream & operator<< (ostream &wyjscie, const CPhoneBook &book)
{
    CPhoneData *wsk;

    for(wsk=book.getList(); wsk!=NULL; wsk=wsk->getNext())
    {
        wyjscie << wsk->showSurname() << "#" << wsk->showName() << "#" \
                << wsk->showNumber() << "#";
    }
    return wyjscie;
}

CPhoneBook::CPhoneBook()
{
    char linec[255];
    string tab[4];
    filename = "phonebook.dat";
    ifstream input(filename.c_str());
    list = NULL;

    if(input)
    {
        int i=0;
        int full=0;
        while(!input.eof())
        {
            if(full==1)
            {
                this->add(tab);
                full=0;
            }
            input.getline(linec, 125, '#');
            string line(linec);
            if(line.length() == 0)
                break;
            switch(i%3)
            {
                case 0:
                    tab[1] = line;
                break;
                case 1:
                    tab[0] = line;
                break;
                case 2:
                    tab[2] = line;
                    full = 1;
            }
            i++;
        }
        input.close();
    }
}

CPhoneBook::~CPhoneBook()
{
    CPhoneData *wsk;
    CPhoneData *nast;

    wsk = getList();
    if(wsk!=NULL)
    {
        ofstream output(filename.c_str());
        output << *this;
        output.close();
        for(; wsk->getNext()!=NULL; wsk=wsk->getNext())
        {
            nast = wsk->getNext();
            delete wsk;
        }
    }
}

CPhoneData* CPhoneBook::getList() const
{
    return list;
}

void CPhoneBook::setList(CPhoneData *pnew)
{
    if(pnew == NULL)
        list = NULL;
    else
        list = pnew;
}

void CPhoneBook::attachToList(CPhoneData **proot, CPhoneData *pnew)
{
    CPhoneData *wsk;

    if(*proot == NULL)
        *proot = pnew;
    else
    {
        for(wsk=*proot; wsk->getNext()!=NULL; wsk=wsk->getNext());
        wsk->setNext(pnew);
    }
}

void CPhoneBook::add(string tab[])
{
    CPhoneData *tmp = this->getList();
    CPhoneData *pnew = new CPhoneData(tab[0], tab[1], tab[2]);
    if(tmp == NULL)
        this->setList(pnew);
    else
        attachToList(&tmp, pnew);
    incCounter();
}

void CPhoneBook::edit(int num, string tab[])
{
    CPhoneData *wsk = this->getList();
    int i;

    for(i=1; i<num; i++)
        wsk=wsk->getNext();
    if(tab[0] != "x")
        wsk->setName(tab[0]);
    if(tab[1] != "x")
        wsk->setSurname(tab[1]);
    if(tab[2] != "x")
        wsk->setNumber(tab[2]);
}

void CPhoneBook::del(int num)
{
    CPhoneData *wsk=getList(), *prev=NULL;

    for(int i=1; i<num; i++, wsk=wsk->getNext())
        if(i == num-1)
            prev = wsk;
    if(prev == NULL)
        this->setList(wsk->getNext());
    else
    {
        prev->setNext(wsk->getNext());
        delete wsk;
    }
    decCounter();
}

