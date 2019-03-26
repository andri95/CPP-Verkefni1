# CPP-Verkefni1 - Andri Fannar
**Eins og ég skrifaði í athugasemd inni á Innu er ég alltaf að fá Segmentation fault þegar ég kalla í eitthvað með this->**  
**Hérna er nákvæmlega errorinn:**   
Program received signal SIGSEGV, Segmentation fault.  
0x0000000000400b76 in Afangi::getID (this=0x20105025  
8d4c54) at main.cpp:21                                
21                  return this -> id;              
(gdb)  
**Hérna er linked list tímaverkefnið nema 3 int breytum í constructor í Afangi og það virkar ekki**   

```cpp
#include <iostream>
#include <sstream>

using namespace std;

class Afangi {
    private:
        int id;
        int nafn;
        int einkunn;
    public:
        Afangi() : id(0), nafn(0), einkunn(0){}

        Afangi(int id, int nafn, int einkunn) {
            this->id = id;
            this->nafn = nafn;
            this->einkunn = einkunn;
        }

        int getID() {
            return this -> id;
        }

        void prentaGogn() {
            cout << "ID: " << this->id << " Numer: " << this->nafn << "Einkunn: " << this->einkunn << endl;
        }
};

class Node {
    public:
        Afangi data; // aukaverkefni: breyta data í pointer
        Node *next;
        Node(int id, int nafn, int einkunn) {
            data = Afangi(id, nafn, einkunn);
            next = nullptr;
        }

};

class Nemandi {
    private:
        int id;
        std::string nafn;
        Node *head;
    public:

        Nemandi(int nId, string nNafn){
            id = nId;
            nafn = nNafn;
        }
        Nemandi() {
            head = nullptr;
        }

        void skraAfanga(int id, int nafn, int einkunn) {
            if(head == nullptr) {
                head = new Node(id, nafn, einkunn);
            } else {
                Node *nyttStak = new Node(id, nafn, einkunn);
                if(head->data.getID() > id) {
                    nyttStak->next = head;
                    head = nyttStak;
                } else {
                    Node *current = head;
                    Node *prev = head;
                    while(current && current->data.getID() < id) {
                        prev = current;
                        current = current->next;
                    }
                    prev->next = nyttStak;
                    nyttStak->next = current;
                }
            }
        }
};

int main() {
    
    Nemandi andri = Nemandi(11, "Andri");

    andri.skraAfanga(33, 22, 11);
    
    return 0;
}
```
