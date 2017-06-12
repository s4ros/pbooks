#ifndef DATA_H
#define DATA_H

#include <string>

using namespace std;

class CData
{
    protected:
	string name;
	string surname;
	
    public:
	string showName();
	string showSurname();
	void setName(string n_name);
	void setSurname(string n_surname);
};

#endif