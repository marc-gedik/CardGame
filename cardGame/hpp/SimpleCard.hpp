#ifndef H_SIMPLE_CARD
#define H_SIMPLE_CARD

#include "Card.hpp"

template <typename Suit, typename Rank>
class SimpleCard : public Card {
protected:
  bool hidden;
  Suit suit;
  Rank rank;

public:
  virtual bool operator< (const SimpleCard&) const;
  virtual bool operator<=(const SimpleCard&) const;
  virtual bool operator==(const SimpleCard&) const;
  virtual bool operator> (const SimpleCard&) const;
  virtual bool operator>=(const SimpleCard&) const;

  virtual bool isHidden();
  virtual bool isVisible();
};

#endif
