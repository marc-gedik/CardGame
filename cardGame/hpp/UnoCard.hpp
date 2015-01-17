#ifndef H_UNO_CARD
#define H_UNO_CARD

#include <iostream>
#include "SimpleCard.hpp"

enum UnoSuit { Blue, Green, Red, Yellow, NoColor };
enum UnoRank { Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, PlusTwo, PlusFour, Reverse, Skip, Joker, SuperJoker };

extern UnoSuit unoSuits[];
extern int nUnoSuits;
extern UnoRank unoRanks[];
extern int nUnoRanks;

std::ostream& operator<<(std::ostream&, const UnoRank&);
std::ostream& operator<<(std::ostream&, const UnoSuit&);


#define UnoCard SimpleCard<UnoSuit, UnoRank>

#endif
