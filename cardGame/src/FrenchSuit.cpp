#include <iostream>

#include "FrenchSuit.hpp"

std::ostream& operator<<( std::ostream& os, const FrenchSuit &suit){
  switch(suit){
  case Hearts:
    os << "Heart";
    break;
  case Diamonds:
    os << "Diam";
    break;
  case Clubs:
    os << "Club";
    break;
  case Spades:
    os << "Spade";
    break;
  }
  return os;
}

FrenchSuit frenchSuits[] = { Hearts, Diamonds, Clubs, Spades };
int nbrFrenchSuit = 4;
