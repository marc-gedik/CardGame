#ifndef H_CARD
#define H_CARD

#include <iostream>

class Card {
protected:
  virtual int getValue() const = 0;
public:
  virtual bool isHidden() const = 0;
  virtual bool isVisible() const = 0;

  bool operator< (const Card&) const;
  bool operator<=(const Card&) const;
  bool operator==(const Card&) const;
  bool operator> (const Card&) const;
  bool operator>=(const Card&) const;

  void printCard();
};

#endif
