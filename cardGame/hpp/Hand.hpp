#ifndef H_HAND
#define H_HAND

#include <list>
#include <iostream>

#include "CanAddRemovePile.hpp"
#include "CardContainer.hpp"
#include "Card.hpp"
#include "Movement.hpp"

using namespace std;

class Hand : public CanAddRemovePile {
private:
  list<Card*> hand ;

public:
  Hand(){}

  virtual void add(Card&);
  virtual void add(const CardContainer&);
  virtual int getSize();

  virtual CardContainer remove(Movement&);

  bool isEmpty();

  ostream& print(ostream&);

  friend ostream& operator<<(ostream&, Hand&);
};

#endif
