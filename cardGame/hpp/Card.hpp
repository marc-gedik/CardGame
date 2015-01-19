#ifndef H_CARD
#define H_CARD

#include <iostream>

using namespace std;

#include "Settings.hpp"

class Card {
public:
  virtual int getRank() const = 0;
  virtual int getSuit() const = 0;

  virtual bool isHidden()  const = 0;
  virtual bool isVisible() const = 0;
  virtual void flip() = 0;

  virtual ostream& print(ostream&) = 0;


public:
  virtual Card* clone() const = 0;

  ~Card();
  bool operator< (const Card&) const;
  bool operator<=(const Card&) const;
  bool operator> (const Card&) const;
  bool operator>=(const Card&) const;

  bool operator!=(const Card&) const;
  bool operator==(const Card&) const;
  bool sameSuit(const Card&);
  int compare(const Card&, const Settings&) const;

  friend ostream& operator<<(ostream&, Card&);
};

#endif
