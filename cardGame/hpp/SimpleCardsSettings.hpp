#ifndef H_SIMPLE_CARDS_SETTINGS
#define H_SIMPLE_CARDS_SETTINGS

#include <iostream>
#include <map>

#include "Settings.hpp"

template <typename Suit, typename Rank>
class SimpleCardsSettings : Settings {
private:
  typedef pair<Suit, Rank> key;
  Suit trump;
  map<key, int> values;

public:

  void setTrump(Suit suit){ trump = suit; }

  void setValue(Suit suit, Rank rank, int value){
    values.insert(make_pair(key(suit, rank), value));
  }

  virtual int compare(const Card& cardA, const Card& cardB){
    if(cardA.getSuit() == trump)
      if(cardB.getSuit() == trump)
	return cardA.getRank() - cardB.getRank();
      else
	return 1;
    else
      if(cardB.getSuit() == trump)
	return -1;
      else
	return cardA.getRank() - cardB.getRank();
  }
};

#endif
