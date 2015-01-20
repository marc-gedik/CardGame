#ifndef H_DISCARD_PILE
#define H_DISCARD_PILE

#include <list>
#include <iostream>

#include "Card.hpp"
#include "CardContainer.hpp"
#include "CanAddPile.hpp"

using namespace std;

class DiscardPile : public CanAddPile {

private:
  list<Card*> discardPile;

public:

  DiscardPile(){}

  virtual void add(Card &x);
  virtual void add(const CardContainer& c);

  bool isEmpty();
  bool contains(CardContainer&);
  CardContainer remove(CardContainer&);

  CardContainer removeAll();

  Card& look();

  ostream& print(ostream& os);

  friend ostream& operator<<(ostream& os, DiscardPile& x);

};

#endif
