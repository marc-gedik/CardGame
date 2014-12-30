#include <iostream>

#include "FrenchRank.hpp"

std::ostream& operator<<(std::ostream& os, const FrenchRank& rank){
  switch(rank){
  case(Deuce):
    os << "2";
    break;
  case(Three):
    os << "3";
    break;
  case(Four):
    os << "4";
    break;
  case(Five):
    os << "5";
    break;
  case(Six):
    os << "6";
    break;
  case(Seven):
    os << "7";
    break;
  case(Eight):
    os << "8";
    break;
  case(Nine):
    os << "9";
    break;
  case(Ten):
    os << "10";
    break;
  case(Jack):
    os << "J";
    break;
  case(Queen):
    os << "Q";
    break;
  case(King):
    os << "K";
    break;
  case(Ace):
    os << "A";
    break;
  }
  return os;
}

FrenchRank frenchRanks[] = { Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
int nbrFrenchRank = 13;
