#include <list>
<<<<<<< HEAD
#include "Card.hpp"
=======
>>>>>>> e21b3e502b899f731540533c716d59a27d5ed1b7
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

