#ifndef PHONEDATA_H
#define PHONEDATA_H

#include "data.h"

class CPhoneData : public CData
{
    private:
        string number;
        CPhoneData *next;
    public:
        CPhoneData(string n_name, string n_surname, string n_number);

        string showNumber();
        void setNumber(string n_number);
        CPhoneData *getNext();
        void setNext(CPhoneData *pnext);
};

#endif
