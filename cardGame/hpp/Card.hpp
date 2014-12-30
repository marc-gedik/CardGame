#ifndef H_CARD
#define H_CARD

#include <iostream>

using namespace std;

class Card {
protected:
  virtual int getValue() const = 0;
  virtual int getRealValue() const = 0;


public:
  virtual bool isHidden() const = 0;
  virtual bool isVisible() const = 0;
  virtual void flip() = 0;

  bool operator< (const Card&) const;
  bool operator<=(const Card&) const;
  bool operator==(const Card&) const;
  bool operator> (const Card&) const;
  bool operator>=(const Card&) const;

  virtual ostream& print(ostream&) const = 0;
  friend ostream& operator<<(ostream&, Card&);
};

#endif
