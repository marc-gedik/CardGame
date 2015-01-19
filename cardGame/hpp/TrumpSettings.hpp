#ifndef H_TRUMP_SETTINGS
#define H_TRUMP_SETTINGS

#include <iostream>
#include <map>

#include "Settings.hpp"

class TrumpSettings : Settings {
protected:
  typedef pair<int, int> key;
  int trump;
  map<key, int> values;

public:

  void setTrump(int suit){ trump = suit; }

  void setValue(int suit, int rank, int value){
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
      else if (cardB.getSuit() == cardA.getSuit())
	return cardA.getRank() - cardB.getRank();
      else
	return 1;
  }
};

#endif
