#ifndef H_CARD
#define H_CARD

#include "Comparable.hpp"

class Card : public Comparable {
public:
  virtual bool operator< (const Card&) = 0;
  virtual bool operator<=(const Card&) = 0;
  virtual bool operator==(const Card&) = 0;
  virtual bool operator> (const Card&) = 0;
  virtual bool operator>=(const Card&) = 0;

  virtual bool isHidden() = 0;
  virtual bool isVisible() = 0;
};

#endif
