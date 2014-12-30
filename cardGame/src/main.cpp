#include <iostream>
#include "Hand.hpp"
#include "FrenchSuit.hpp"
#include "FrenchRank.hpp"

using namespace std;

#include "Deck.hpp"
#include "FrenchCard.hpp"

int main(){
  cout << " -- Card Game -- " << endl;

  Deck<FrenchCard> d(1);
  Hand<FrenchCard> h;
  FrenchCard f(Hearts, King);
  FrenchCard f2(Hearts, Queen);

  h.add(f);
  h.add(f2);

  h.printHand();

  FrenchCard *c = new FrenchCard [2];
  c[1]= f;
  c[0]= f2;

  h.add(c, 2);

  h.printHand();
  h.remove(1);
  h.printHand();
  // cout<<"coucou"<<endl;
  // h.printHand();

  return 0;
}
