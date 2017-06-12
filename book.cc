#include "book.h"
#include <iostream>

IBook::IBook()
{
    counter = 0;
}

int IBook::showCounter()
{
    return counter;
}

void IBook::incCounter()
{
    counter++;
}

void IBook::decCounter()
{
    counter--;
}

int IBook::find(string key, string buff)
{
    int i, j;
    int many=key.length();
    int len=buff.length();
    int match;

    for(i=0; i<len-many; i++)
    {
        match=0;
        for(j=0; j<many; j++)
        {
            if(buff[i+j] == key[j])
                match++;
            if(match==many)
                return 1;
        }
    }
    return 0;
}
