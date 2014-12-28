#include <list>

#include "Card.hpp"

using namespace std;

class Hand {

private:
  list<Card*> myHand ;


  
public:

  Hand();
  void addCard(Card &c);

  void addCards(Card *c[], int size);

  void removeCard(int position);
  void printHand();
};

