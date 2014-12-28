#ifndef H_SIMPLE_CARD
#define H_SIMPLE_CARD

#include <iostream>
#include "Card.hpp"

template <typename Suit, typename Rank>
class SimpleCard : public Card {
private:
  bool hidden;
  Suit suit;
  Rank rank;
protected:
  virtual int getValue() const { return rank; }
public:
  SimpleCard() {}
  SimpleCard(Suit s, Rank r)
    : suit(s), rank(r), hidden(false) {}
  virtual bool isHidden()  const {return hidden; }
  virtual bool isVisible() const {return !hidden;}
};

#endif
