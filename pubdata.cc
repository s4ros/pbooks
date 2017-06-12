#include "pubdata.h"

CPubData::CPubData(string n_name, string n_surname, string n_number, string n_title)
{
    name = n_name;
    surname = n_surname;
    number = n_number;
    title = n_title;
    next = NULL;
}

string CPubData::showTitle()
{
    return title;
}

string CPubData::showNumber()
{
    return number;
}

void CPubData::setTitle(string n_title)
{
    title = n_title;
}

void CPubData::setNumber(string n_number)
{
    number = n_number;
}

CPubData* CPubData::getNext()
{
    return next;
}

void CPubData::setNext(CPubData *pnew)
{
    next = pnew;
}
