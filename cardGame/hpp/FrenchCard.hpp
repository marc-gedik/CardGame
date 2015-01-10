#ifndef H_FRENCH_CARD
#define H_FRENCH_CARD

#include <iostream>
#include "SimpleCard.hpp"

enum FrenchSuit { Heart, Diamond, Club, Spade };
enum FrenchRank { Deuce = 2, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };

extern FrenchSuit frenchSuits[];
extern int nFrenchSuits;
extern FrenchRank frenchRanks[];
extern int nFrenchRanks;

std::ostream& operator<<(std::ostream&, const FrenchRank&);
std::ostream& operator<<(std::ostream&, const FrenchSuit&);


#define FrenchCard SimpleCard<FrenchSuit, FrenchRank>

#endif
