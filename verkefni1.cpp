#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Afangi {
    private:
        int id;
        string nafn;
        double einkunn;
    public:
        Afangi() : id(0), nafn(""), einkunn(0) {}

        Afangi(int id, string nafn, double einkunn) {
            this->id = id;
            this->nafn = nafn;
            this->einkunn = einkunn;
        }

        int getID() {
            return this ->id;
        }
        string getNafn(){
            return this -> nafn;
        }
        double getEink(){
            return this -> einkunn;
        }

        void prentaGogn() {
            cout << "ID: " << this->id << " Numer: " << this->nafn << "Einkunn: " << this->einkunn << endl;
        }
};

class Node {
    public:
        Afangi data;
        Node *next;
        Node(int id, string nafn, double einkunn) {
            data = Afangi(id, nafn, einkunn);
            next = nullptr;
        }

        ~Node() {
            delete next;
        }

};

class Nemandi {
    private:
        int id;
        string nafn;
        Node *head;
    public:

        Nemandi(int nId, string nNafn) {
            id = nId;
            nafn = nNafn;
            head = nullptr;
        }
        Nemandi() {
            head = nullptr;
        }

        ~Nemandi() {
            delete head;
        }

        void skraAfanga(int id, string nafn, double einkunn) {
            if(head == nullptr) {
                head = new Node(id, nafn, einkunn);
            } else {
                Node *nyttStak = new Node(id, nafn, einkunn);
                nyttStak->next = head;
                head = nyttStak;
            }
        }
        void prenta(){

            double medal = 0;
            int teljari = 0;
            double medaleinkunn = 0;

            cout << "ID: " << this -> id << " - Nafn: " << this -> nafn << endl;
            Node *i;
            for (i = head; i != nullptr; i = i -> next) {
                cout << "ID: " << i -> data.getID() << " - Nafn: " << i -> data.getNafn() << " - Einkunn: " << i -> data.getEink() <<endl;

                medal += i -> data.getEink();
                teljari++;
            }
            medaleinkunn = medal / teljari;
            cout << "Meðaleinkunn: " << medaleinkunn;
        }
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