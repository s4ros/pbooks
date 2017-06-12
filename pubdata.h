#ifndef PUBDATA_H
#define PUBDATA_H

#include "data.h"

class CPubData : public CData
{
    private:
        string title;
        string number;
        CPubData *next;
    public:
        CPubData(string n_name, string n_surname, string n_number, string n_title);

        string showTitle();
        string showNumber();
        void setTitle(string n_title);
        void setNumber(string n_number);
        CPubData* getNext();
        void setNext(CPubData *pnext);
};

#endif
