#ifndef H_FRENCH_RANK
#define H_FRENCH_RANK

#include <iostream>

enum FrenchRank {
  Deuce = 2,
  Three,
  Four,
  Five,
  Six,
  Seven,
  Height,
  Nine,
  Ten,
  Jack,
  Queen,
  King,
  Ace
};

std::ostream& operator<<( std::ostream&, const FrenchRank&);

extern FrenchRank frenchRanks[];
extern int nbrFrenchRank;

#endif
