#include <iostream>
#include "Hand.hpp"
#include "FrenchSuit.hpp"
#include "FrenchRank.hpp"

using namespace std;

#include "Deck.hpp"
#include "FrenchCard.hpp"

using namespace std;


int main(){
  cout << " -- Card Game -- " << endl;

  Hand h;
  FrenchCard f(Hearts, King);
  FrenchCard f2(Hearts, Queen);

  h.addCard(f);
  h.addCard(f2);

  h.printHand();
  // h.addCard(67);
  // h.addCard(16);
  // h.addCard(14);
  FrenchCard *c[11] ;
  c[1]= &f;
  c[0]= &f2;
  // h.addCards(c, 11);

  // h.printHand();
   h.removeCard(1);
     h.printHand();

  // cout<<"coucou"<<endl;
  // h.printHand();

  return 0;
}
