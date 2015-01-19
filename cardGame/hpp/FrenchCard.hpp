#ifndef H_FRENCH_CARD
#define H_FRENCH_CARD

#include <iostream>
#include "SimpleCard.hpp"

namespace fr {
  enum FrenchSuit { Heart, Diamond, Club, Spade };
  enum FrenchRank { Deuce = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

using namespace fr;

extern FrenchSuit frenchSuits[];
extern int nFrenchSuits;
extern FrenchRank frenchRanks[];
extern int nFrenchRanks;

std::ostream& operator<<(std::ostream&, const FrenchRank&);
std::ostream& operator<<(std::ostream&, const FrenchSuit&);

}

class FrenchCard : public SimpleCard<fr::FrenchSuit, fr::FrenchRank> {};

#endif
