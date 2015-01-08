#ifndef H_CARD
#define H_CARD

#include <iostream>

using namespace std;

class Card {
protected:
  virtual int getRank() const = 0;
  virtual int getSuit() const = 0;

  virtual bool isHidden()  const = 0;
  virtual bool isVisible() const = 0;
  virtual void flip() = 0;

  virtual ostream& print(ostream&) = 0;
public:
  bool operator< (const Card& card) const;
  bool operator<=(const Card& card) const;
  bool operator> (const Card& card) const;
  bool operator>=(const Card& card) const;

  bool operator!=(const Card& card) const;
  bool operator==(const Card& card) const;

  friend ostream& operator<<(ostream&, Card&);
};

#endif
