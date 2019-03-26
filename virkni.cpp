#include <iostream>
#include <string>
#include "klasar.h"

void Nemandi::skraAfanga(int id, string nafn, double einkunn)
{
     if(head == nullptr){
         head = new Hnutur(id, nafn, einkunn);
     } else {
         Hnutur *nyttStak = new Hnutur(id, nafn, einkunn);
         if(head -> afangi.getID() > id){
             nyttStak -> next = head;
             head = nyttStak;
         } else {
             Hnutur *cur = head;
             Hnutur *prv = head;
             while(cur && cur -> afangi.getID() < id){
                 prv = cur;
                 cur = cur -> next;
             }
             prv -> next = nyttStak;
             nyttStak -> next = cur;
         }
     }
};

void Nemandi::prenta()
{
    cout << "Id: " << id << " Nafn: " << nafn << "\n";

    //Hnutur* i;
    //for (i = head; i != nullptr; i = i -> next){
        //cout << i ->  afangi.getID() << " - " << i -> next << "\n";
    //}
};

int main(){
    Nemandi andri = Nemandi(11, "Andri");
    andri.prenta();
    andri.skraAfanga(22, "KEST", 6.0);

    return 0;
};