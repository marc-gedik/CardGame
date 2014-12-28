#ifndef H_FRENCH_CARD
#define H_FRENCH_CARD

#include "FrenchSuit.hpp"
#include "FrenchRank.hpp"
#include "SimpleCard.hpp"

//Faire un alias ?
/*
template <>
using FrenchCard = SimpleCard<FrenchSuit, FrenchRank>;
*/
#define FrenchCard SimpleCard<FrenchSuit, FrenchRank>

#endif
