#ifndef H_UNO_CARD
#define H_UNO_CARD

#include <iostream>
#include "SimpleCard.hpp"

namespace uno {
  enum UnoSuit { Blue, Green, Red, Yellow, NoColor };
  enum UnoRank { Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, PlusTwo, Reverse, Skip, Joker, SuperJoker };

}
using namespace uno;

extern UnoSuit unoSuits[];
extern int nUnoSuits;
extern UnoRank unoRanks[];
extern int nUnoRanks;

std::ostream& operator<<(std::ostream&, const UnoRank&);
std::ostream& operator<<(std::ostream&, const UnoSuit&);


#define UnoCard SimpleCard<UnoSuit, UnoRank>

#endif
