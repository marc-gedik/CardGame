#ifndef H_FRENCH_SUIT
#define H_FRENCH_SUIT

#include <iostream>

enum FrenchSuit {
  Hearts,
  Diamonds,
  Clubs,
  Spades
};

std::ostream& operator<<(std::ostream&, const FrenchSuit&);

extern FrenchSuit frenchSuits[];
extern int nbrFrenchSuit;

#endif
