#ifndef H_ITALIAN_CARD
#define H_ITALIAN_CARD

#include <iostream>
#include "SimpleCard.hpp"

namespace it {
  enum ItalianSuit { Spade, Bastoni, Denari, Coppe };
  enum ItalianRank { Ace = 1, Deuce, Three, Four, Five, Six, Seven, Fante, Cavallo, Re };

extern ItalianSuit italianSuits[];
extern int nItalianSuits;
extern ItalianRank italianRanks[];
extern int nItalianRanks;

std::ostream& operator<<(std::ostream&, const ItalianRank&);
std::ostream& operator<<(std::ostream&, const ItalianSuit&);

}

class ItalianCard : public SimpleCard<it::ItalianSuit, it::ItalianRank> {};


#endif
