#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class IBook
{
    protected:
        int counter;
    public:
        IBook();

        int showCounter();
        void incCounter();
        void decCounter();

        int find(string key, string buff);
        virtual void add(string tab[]) = 0;
        virtual void edit(int num, string tab[]) = 0 ;
        virtual void del(int num) = 0;
};

#endif
