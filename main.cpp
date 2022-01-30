#include <iostream>
#include <fstream>
#include <cctype>
#include "rapidcsv.h"
#include <string>
#include <random>#include <stdio.h>
#include <cstdlib>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>



using namespace std;

class Employee//obiekt
    {
    public:
        int id=0;
        string imie;
        string nazwisko;
        int stanowisko;
        string password;
        int lider_id;

    void CreatingNewEmp()
        {
        srand (time(NULL));

        string tab[62] = {"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O","U","V","P","Q","R","S","T","W","X","Y","Z","a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","u","v","p","q","r","s","t","w","x","y","z","0","1","2","3","4","5","6","7","8","9"};


        cout <<"stanowisko (1-pracownik, 2-lider , 3-administrator) : ";
        cin >> stanowisko;

        cout << "imie: ";
        cin >> imie;

        cout << "nazwisko: ";
        cin >> nazwisko;

        cout<< "haslo: ";//generowanie randomowego hasla dla nowego pracownika
        password=tab[rand()%62] + tab[rand()%62] + tab[rand()%62] + tab[rand()%62] + tab[rand()%62];
        cout<<password<<endl;

        fstream plik;
        string linia;
        plik.open("lista.csv", ios::in);
        while(getline(plik,linia)){id++;}
        plik.close();
        cout<<"id: "<<id<<endl;

        cout<<"lider id: "<<lider_id;
        }
        };

    struct Data
    {
        string position;
        string f_name;
        string l_name;
        string password;
        int id;
        int lider_id;
    };


int main()
{
    string log_type = "0";
    int log_id;
//logowanie
    bool log = false;
    while (log == false)
    {
    cout<<"++LOGOWANIE++"<<endl<<endl;
    cout<<"imie: ";
    string ch_imie;
    cin>>ch_imie;

    cout<<"nazwisko: ";
    string ch_nazwisko;
    cin>>ch_nazwisko;

    cout<<"haslo: ";
    string ch_password;
    cin>>ch_password;


    ifstream file("lista.csv");
    string line;
    std::vector<Data> items;
    Data rowData;

    while (getline(file, line))
        {
        stringstream splitter(line);

        string dataStr;

        getline(splitter, dataStr, ',');
        stringstream(dataStr) >> rowData.position;

        getline(splitter, dataStr, ',');
        stringstream(dataStr) >> rowData.f_name;

        getline(splitter, dataStr, ',');
        stringstream(dataStr) >> rowData.l_name;

        getline(splitter, dataStr, ',');
        stringstream(dataStr) >> rowData.password;

        getline(splitter, dataStr, ',');
        stringstream(dataStr) >> rowData.id;


        if(ch_imie == rowData.f_name && ch_nazwisko == rowData.l_name && ch_password == rowData.password){log = true; log_type = rowData.position; log_id = rowData.id;}
        if (log == false){system("cls");cout<<"bledne dane, sprobuj ponownie"<<endl;}
    }}
    {
//menu
    cout<<"MENU"<<endl<<endl;
    cout<<"1: dodawanie pracownikow"<<endl;
    cout<<"2: wyswietlanie wszystkich pracownikow"<<endl;
    cout<<log_id;
    if(log_type == "1"){cout<<"3: ustal grafik";}
    int menu;
    cin>>menu;
//dodawanie pracowników

    if (menu == 1)
    {
    system( "cls" );
    fstream plik;
    plik.open("lista.csv", ios::out | ios::app);
    string employers;
    {
    Employee employers;
    employers.CreatingNewEmp();
    plik<<employers.stanowisko<<","<<employers.imie<<","<<employers.nazwisko<<","<<employers.password<<","<<employers.id<<","<<employers.lider_id<<endl;
    }
    plik.close();
    }

//wyswietlenie pracowników/ sortowanie
    if (menu == 2)
    {
    system("cls");
    cout<<"1: pokaz wszystkich pracownikow"<<endl;
    cout<<"2: pokaz pracownikow"<<endl;
    cout<<"3: pokaz liderow"<<endl;
    cout<<"4: pokaz administratorow"<<endl;
    int menu2;
    cin>>menu2;
    ifstream file("lista.csv");
    string line;
    std::vector<Data> items;
    Data rowData;

    while (getline(file, line))
        {
        stringstream splitter(line);

        string dataStr;

        getline(splitter, dataStr, ',');
        stringstream(dataStr) >> rowData.position;

        getline(splitter, dataStr, ',');
        stringstream(dataStr) >> rowData.f_name;

        getline(splitter, dataStr, ',');
        stringstream(dataStr) >> rowData.l_name;

        getline(splitter, dataStr, ',');
        stringstream(dataStr) >> rowData.password;

        getline(splitter, dataStr);
        stringstream(dataStr) >> rowData.id;

        getline(splitter, dataStr);
        stringstream(dataStr) >> rowData.lider_id;

        if (menu2==1){cout<<rowData.f_name<<" "<<rowData.l_name<<endl;}
        //każdy pracownik może wyswietlic imie nazwisko i id przypisanego lidera ale tylko admin ma dostep do hasła,
        // dodając kolejne wartości do danych o użytkowniku takie jak pesel można również łato dodać do nich dostęp jedyniie dla admina
        else if(menu2==2){if(rowData.position=="1"){cout<<rowData.f_name<<" "<<rowData.l_name<<" id:"<<rowData.id<<"id lidera: "<<rowData.lider_id;if(log_type == "3"){cout<<" haslo:"<<rowData.password<<" ";}else{cout<<endl;}}}
        else if(menu2==3){if(rowData.position=="2"){cout<<rowData.f_name<<" "<<rowData.l_name<<" id:"<<rowData.id<<"id lidera: "<<rowData.lider_id;if(log_type == "3"){cout<<" haslo:"<<rowData.password<<" ";}else{cout<<endl;}}}
        else if(menu2==4){if(rowData.position=="3"){cout<<rowData.f_name<<" "<<rowData.l_name<<" id:"<<rowData.id<<"id lidera: "<<rowData.lider_id;if(log_type == "3"){cout<<" haslo:"<<rowData.password<<" ";}else{cout<<endl;}}}
        }
    }
////////////////////////////////////////
    if (menu == 3 && log_type == "1")//zaplanowanie zmiany (jest to dostępne tylko dla pracownikow, jesli chca edytowac swoje zaplanowane dni musza skontaktowac sie z adminem)
    {

    fstream plik1;
    string line1;
    int f_id;
    bool is_exis = false;
    int tab[31];

    ifstream file("work_t.csv");
    string line;

    while (getline(file, line))
    {
    stringstream splitter(line);
    string dataStr;
    getline(splitter, dataStr, ',');
    stringstream(dataStr) >> f_id;

    if(f_id == log_id){is_exis = true; cout<<"zmiana zostala juz zaplanowana, w celu edycji skontaktuj sie z administratorem";}
    }
    if(is_exis == false)
    {

    int hour_count=0;
        for(int i=0; i<31; i++)
        {
            cout<<"dzien: "<<i<<"    wybierz zmiane, (0: wolne)(1: pierwsza zmiana 8-16)(2: druga zmiana 16-24): ";
            cin>>tab[i]; cout<<endl;
            if (tab[i]==1 || tab[i]==2){hour_count += 8;}//zliczanie ile godzin p bedzie pracowal w miesiacu
        }
        bool save = true;
        string save1;
        cout<<endl<<"suma godzin: "<<hour_count<<endl;
        cout<<"czy chcesz zapisać zmiany?  t / n :";
        cin>>save1;
        if(save1 == "t"){plik1.open("work_t.csv", ios::out| ios::app);plik1<<log_id<<","<<"  "; for(int i=0; i<31; i++){plik1<<tab[i]<<",";}plik1<<endl;}//w pliku jako pierwsze widoczne jest id uzytkownika nastepnie kolejno do kazdego dnia ktore zamian 1 2 lub 0 - wolne
    }else if (menu ==3){cout<<"error";}
    }

    }
    int menu=0;

    return 0;
    }


