#include "pubbook.h"

/** funkcja sluzy TYLKO do zapisywania do pliku **/
ostream & operator<< (ostream &wyjscie, const CPubBook &book)
{
    CPubData *wsk;

    for(wsk=book.getList(); wsk!=NULL; wsk=wsk->getNext())
    {
        wyjscie << wsk->showSurname() << "#" << wsk->showName() << "#" \
                << wsk->showNumber() << "#" << wsk->showTitle() << "#";
    }
    return wyjscie;
}

CPubBook::CPubBook()
{
    char linec[255];
    string tab[4];
    filename = "pubbook.dat";
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
            switch(i%4)
            {
                case 0:
                    tab[1] = line;
                break;
                case 1:
                    tab[0] = line;
                break;
                case 2:
                    tab[2] = line;
                break;
                case 3:
                    tab[3] = line;
                    full = 1;
            }
            i++;
        }
        input.close();
    }
}

CPubBook::~CPubBook()
{
    CPubData *wsk;
    CPubData *nast;

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

CPubData* CPubBook::getList() const
{
    return list;
}

void CPubBook::setList(CPubData *pnew)
{
    if(pnew == NULL)
        list = NULL;
    else
        list = pnew;
}

void CPubBook::attachToList(CPubData **proot, CPubData *pnew)
{
    CPubData *wsk;

    if(*proot == NULL)
        *proot = pnew;
    else
    {
        for(wsk=*proot; wsk->getNext()!=NULL; wsk=wsk->getNext());
        wsk->setNext(pnew);
    }
}

void CPubBook::add(string tab[])
{
    CPubData *tmp = this->getList();
    CPubData *pnew = new CPubData(tab[0], tab[1], tab[2], tab[3]);
    if(tmp == NULL)
        this->setList(pnew);
    else
        attachToList(&tmp, pnew);
    incCounter();
}

void CPubBook::edit(int num, string tab[])
{
    CPubData *wsk = this->getList();
    int i;

    for(i=1; i<num; i++)
        wsk=wsk->getNext();
    if(tab[0] != "x")
        wsk->setName(tab[0]);
    if(tab[1] != "x")
        wsk->setSurname(tab[1]);
    if(tab[2] != "x")
        wsk->setNumber(tab[2]);
    if(tab[3] != "x")
        wsk->setTitle(tab[3]);
}

void CPubBook::del(int num)
{
    CPubData *wsk=getList(), *prev=NULL;

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
