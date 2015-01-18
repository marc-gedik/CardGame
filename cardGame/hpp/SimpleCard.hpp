#ifndef H_SIMPLE_CARD
#define H_SIMPLE_CARD

#include <iostream>
#include "Card.hpp"

//#include "UnoCard.hpp"

using namespace std;

template <typename Suit, typename Rank>
class SimpleCard : public Card {
protected:
  Suit suit;
  Rank rank;
  bool hidden;
public:
  SimpleCard() {}
  SimpleCard(Suit s, Rank r, bool hide = false)
    : suit(s), rank(r), hidden(hide) {}

  virtual Card* clone() const { return new SimpleCard(*this); }

  virtual int getRank() const { return rank; }
  virtual int getSuit() const { return suit; }

  virtual bool isHidden()  const {return hidden; }
  virtual bool isVisible() const {return !hidden;}
  virtual void flip() { hidden = !hidden; };

  virtual ostream& print(ostream &os) { return os <<" "<< rank <<" "<<  suit<<" coucou";}

};

#endif
