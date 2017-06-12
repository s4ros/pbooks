#include "phonedata.h"
#include <iostream>

CPhoneData::CPhoneData(string n_name, string n_surname, string n_number)
{
    name = n_name;
    surname = n_surname;
    number = n_number;
    next = NULL;
}

string CPhoneData::showNumber()
{
    return number;
}

void CPhoneData::setNumber(string n_number)
{
    number = n_number;
}

CPhoneData* CPhoneData::getNext()
{
    return next;
}

void CPhoneData::setNext(CPhoneData *pnext)
{
    next = pnext;
}
