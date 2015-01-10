#ifndef H_ITALIAN_CARD
#define H_ITALIAN_CARD

#include <iostream>
#include "SimpleCard.hpp"

enum ItalianSuit { Spade, Bastoni, Denari, Coppe };
enum ItalianRank { Ace = 1, Deuce, Three, Four, Five, Six, Seven, Fante, Cavallo, Re };

std::ostream& operator<<(std::ostream&, const ItalianRank&);
std::ostream& operator<<(std::ostream&, const ItalianSuit&);

#define ItalianCard SimpleCard<ItalianSuit, ItalianRank>


#endif
