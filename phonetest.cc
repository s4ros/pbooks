#include "phonebook.h"
#include <iostream>
#include <cstdlib>

int menu();
void showContact(CPhoneData *wsk);
void showBook(CPhoneData *wsk);

int main()
{
    CPhoneBook ksiazka;
    CPhoneData *wsk;
    string tab[4];
    string key;
    int c, tmp;

    do
    {
        c=menu();
        switch(c)
        {
        /** Opcja 1 - wyswietlanie ksiazki **/
            case 1:
                cout << "*** Ksiazka telefoniczna ***" << endl;

                /** tutaj wyswietlanie ksiazki **/
                showBook(ksiazka.getList());
            break;

        /** Opcja 2 - Dodawanie nowego kontaktu **/
            case 2:
                cout << "*** Dodawanie nowego kontaktu ***" << endl;

                /** tutaj dodawanie nowego kontaktu **/
                cout << "Imie: ";
                cin >> tab[0];
                cout << "Nazwisko: ";
                cin >> tab[1];
                cout << "Nr tel.: ";
                cin >> tab[2];
                ksiazka.add(tab);
            break;

        /** Opcja 3 - Wyszukaj kontakt */
            case 3:
                cout << "*** Wyszukaj kontakt ***" << endl;
                cout << "Podaj maske wyszukiwania (np. kawalek nazwiska/imienia/numeru tel.): ";
                cin >> key;
                cout << "Klucz: " << key << endl;
                for(wsk=ksiazka.getList(); wsk!=NULL; wsk=wsk->getNext())
                {

                    /** wyszukiwanie kontaktu **/
                    if(ksiazka.find(key, wsk->showSurname())    || \
                       ksiazka.find(key, wsk->showName())       || \
                       ksiazka.find(key, wsk->showNumber()))
                    {
                        cout << "[!] Znalazlem kontakt: " << endl;
                        cout << "\t";
                        showContact(wsk);
                        cout << "---" << endl;
                    }
                }
            break;
        /** Opcja 4 - Edytuj kontkt **/
                case 4:
                    cout << "*** Edytuj kontakt ***" << endl;

                    /** wyswietlanie calej ksiazki **/
                    showBook(ksiazka.getList());

                    cout << "------" << endl;
                    cout << "Prosze wpisac numer kontaktu do edycji (1-"<<ksiazka.showCounter()<<", lub 0 by anulowac): ";
                    cin >> key;
                    tmp = atoi(key.c_str());
                    if((tmp>=1) && (tmp<=ksiazka.showCounter()))
                    {
                        CPhoneData *wsk=ksiazka.getList();
                        int i;

                        for(i=1; i<tmp; i++)
                            wsk=wsk->getNext();

                        cout << "\tProsze wpisac \"x\", aby pozostawic wartosc w nawiastach []" << endl;
                        cout << "Imie [" << wsk->showName() <<"]: ";
                        cin >> tab[0];
                        cout << "Nazwisko: [" << wsk->showSurname() << "]: ";
                        cin >> tab[1];
                        cout << "Nr telefonu: [" << wsk->showNumber() << "]: ";
                        cin >> tab[2];
                        ksiazka.edit(tmp, tab);
                    }
                    else
                        cout << "Edycja anulowana!" << endl;
                break;

        /** Opcja 5 - Usun kontakt **/
            case 5:
                //CPhoneData *prev;

                /** wyswietlanie calej ksiazki!! **/
                showBook(ksiazka.getList());
                cout << endl << "*** Usun kontakt ***" << endl;
                cout << "Podaj numer kontaktu do usuniecia (1.." << ksiazka.showCounter() << "): ";
                cin >> key;
                tmp = atoi(key.c_str());
                if((tmp>=1) && (tmp<=ksiazka.showCounter()))
                {
                    ksiazka.del(tmp);
                }
                else
                {
                    cout << "Usuwanie anulowane (kontakt o podanym numerze nie istnieje?)" << endl;
                }
            break;
        /** Opcja 0 - wyjscie z programu **/
            case 0:
                cout << "Znaki inne niz cyfry od 1..9 sa niepozadane!" << endl;
            break;
        }
    }while(c!=9);

    return 0;
}

int menu()
{
    string choice;
    int c;

    cout << endl << "*-----------------------*" << endl;
    cout << " 1. Pokaz ksiazke" << endl;
    cout << " 2. Dodaj nowy kontakt" << endl;
    cout << " 3. Wyszukaj kontakt" << endl;
    cout << " 4. Edytuj kontakt" << endl;
    cout << " 5. Usun kontakt" << endl << endl;
    cout << " 9. Wyjscie" << endl;
    cout << endl << "Wybor: ";

    cin >> choice;
    cin.clear();

    system("clear");
    c=atoi(choice.c_str());

    cout << endl;
    return c;
}

void showContact(CPhoneData *wsk)
{
    cout << wsk->showName() << " " << wsk->showSurname() << " " << wsk->showNumber() << endl;
}

void showBook(CPhoneData *wsk)
{
    CPhoneData *p;
    int i;

    for(i=1, p=wsk; wsk!=NULL; wsk=wsk->getNext(), i++)
    {
        cout << i << ". ";
        showContact(wsk);
    }
}
