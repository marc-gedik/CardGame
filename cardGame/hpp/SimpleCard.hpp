#ifndef H_SIMPLE_CARD
#define H_SIMPLE_CARD

#include <iostream>
#include "Card.hpp"

using namespace std;

template <typename Suit, typename Rank>
class SimpleCard : public Card {
public:
  SimpleCard() {}
  SimpleCard(Suit s, Rank r, bool hide = false)
    : suit(s), rank(r), hidden(hide) {}

  virtual bool isHidden()  const {return hidden; }
  virtual bool isVisible() const {return !hidden;}
  virtual void flip() { hidden = !hidden; };

  virtual ostream& print(ostream &os) const { return os << rank << suit;}

};

#endif
