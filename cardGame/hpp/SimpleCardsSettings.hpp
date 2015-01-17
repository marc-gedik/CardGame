#ifndef H_SIMPLE_CARDS_SETTINGS
#define H_SIMPLE_CARDS_SETTINGS

#include <iostream>
#include <map>

#include "Settings.hpp"

template <typename Suit, typename Rank>
class SimpleCardsSettings : Settings {
  friend class Card;
private:
  Suit trump;
  std::map<Suit, int> values;
public:
  SimpleCardsSettings() {}
  void setTrump(Suit&);
  void setValue(Rank&, int);
  virtual int compare(const Card&, const Card&) = 0;

};

#endif
