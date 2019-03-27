#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Afangi
{
    private:
        
        int id;
        string nafn;
        double einkunn;

    public:

        Afangi() : id(0), nafn(""), einkunn(0){}
        Afangi(int id, string nafn, double einkunn){
            this -> id = id;
            this -> nafn = nafn;
            this -> einkunn = einkunn;
        }

        int getID();

        string getNafn();

        double getEink();
};

class Hnutur
{
    public:
        Afangi afangi;
        Hnutur *next;
        Hnutur(int id, string nafn, double einkunn){
            afangi = Afangi(id, nafn, einkunn);
            next = nullptr;
        }
        
        ~Hnutur();
};

class Nemandi
{
    private:
        int id;
        string nafn;
        Hnutur *head;

    public:
        Nemandi(int nId, string nNafn){
            id = nId;
            nafn = nNafn;
            head = nullptr;
        }

        Nemandi(){
            head = nullptr;
        }

        ~Nemandi();

        void skraAfanga(int id, string nafn, double einkunn);

        void prenta();
};