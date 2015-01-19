#ifndef H_SAME_OR_TRUMP_SETTINGS
#define H_SAME_OR_TRUMP_SETTINGS

#include "TrumpSettings.hpp"

class SameOrTrumpSettings : public TrumpSettings {
public:

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
