#include <iostream>

#include "FrenchRank.hpp"

std::ostream& operator<<(std::ostream& os, const FrenchRank& rank){
  switch(rank){
  case(Jack):
    os << "Jack";
    break;
  case(Queen):
    os << "Queen";
    break;
  case(King):
    os << "King";
    break;
  case(Ace):
    os << "Ace";
    break;
  default:
    os << rank;
  }
  return os;
}

FrenchRank frenchRanks[] = { Deuce, Three, Four, Five, Six, Seven, Height, Nine, Ten, Jack, Queen, King, Ace };
int nbrFrenchRank = 13;
