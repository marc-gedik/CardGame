#include <iostream>
#include "Hand.hpp"
using namespace std;


int main(){
  Hand h;
  h.addCard(13);
  h.addCard(67);
  h.addCard(16);
  h.addCard(14);
  int c[] ={75,23,65,42,13};
  h.addCards(c, 5);

  h.printHand();
  h.removeCard(5);
  cout<<"coucou"<<endl;
  h.printHand();
  return 0;
}
