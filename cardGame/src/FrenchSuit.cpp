#include <iostream>

#include "FrenchSuit.hpp"

std::ostream& operator<<(std::ostream& os, const FrenchSuit& suit){
  switch(suit){
  case Hearts:
    os << "\xE2\x99\xA5";
    break;
  case Diamonds:
    os << "\xE2\x99\xA6";
    break;
  case Clubs:
    os << "\xE2\x99\xA3";
    break;
  case Spades:
    os << "\xE2\x99\xA0";
    break;
  }
  return os;
}

FrenchSuit frenchSuits[] = { Hearts, Diamonds, Clubs, Spades };
int nbrFrenchSuit = 4;
