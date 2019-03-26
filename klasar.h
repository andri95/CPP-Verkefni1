#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Afangar
{
    private:
        
        int id;
        string nafn;
        double einkunn;

    public:

        //Afangar() : id(id), nafn(nafn), einkunn(einkunn){}
        Afangar() : id(), nafn(), einkunn(){}
        Afangar(int id, string nafn, double einkunn){
            this -> id = id;
            this -> nafn = nafn;
            this -> einkunn = einkunn;
        }

        int getID(){
            return this -> id;
        }

        void prentaGogn(){
            cout << "ID: " << this -> id << "Nafn: " << this -> nafn << "Einkunn: " << this -> einkunn << endl;
        }

};

class Hnutur
{
    public:
        Afangar afangi;
        Hnutur *next;
        Hnutur(int id, string nafn, double einkunn){
            afangi = Afangar(id, nafn, einkunn);
            next = nullptr;
        }

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
        }

        Nemandi(){
            head = nullptr;
        }

        void skraAfanga(int id, string nafn, double einkunn);

        void prenta();
};