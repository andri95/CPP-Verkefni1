#include <iostream>
#include <string>
#include "klasar.h"

int Afangi::getID(){
    return this ->id;
};

string Afangi::getNafn(){
    return this -> nafn;
};

double Afangi::getEink(){
    return this -> einkunn;
};

Hnutur::~Hnutur() {
    delete next;
};

Nemandi::~Nemandi() {
    delete head;
};

void Nemandi::skraAfanga(int id, string nafn, double einkunn)
{
     if(head == nullptr) {
        head = new Hnutur(id, nafn, einkunn);
        } else {
            Hnutur *nyttStak = new Hnutur(id, nafn, einkunn);
            nyttStak->next = head;
            head = nyttStak;
        }
};

void Nemandi::prenta()
{
    double medal = 0;
    int teljari = 0;
    double medaleinkunn = 0;

    cout << "Einkunnir fyrir " << this -> nafn << ", id: " << this -> id << ":" << endl;
    Hnutur *i;
    for (i = head; i != nullptr; i = i -> next) {
        cout << "Id: " << i -> afangi.getID() << ", Nafn: " << i -> afangi.getNafn() << ", Einkunn: " << i -> afangi.getEink() <<endl;

        medal += i -> afangi.getEink();
        teljari++;
    }
    medaleinkunn = medal / teljari;
    cout << "Meðaleinkunn: " << medaleinkunn;
};

int main() {
    Nemandi andri = Nemandi(11, "Andri");
    
    andri.skraAfanga(33, "KEST", 6.0);
    andri.skraAfanga(34, "FORR", 3.5);
    andri.skraAfanga(35, "ROBO", 10);
    andri.skraAfanga(36, "GAGN", 2.4);
    andri.prenta();
    return 0;
}