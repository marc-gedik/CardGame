#include <iostream>

#include "ItalianRank.hpp"

std::ostream& operator<<(std::ostream& os, const ItalianRank& rank){
  switch(rank){
  case(Ace):
    os << "A";
    break;
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
  case(Fante):
    os << "F";
    break;
  case(Cavallo):
    os << "C";
    break;
  case(Re):
    os << "R";
    break;
  }
  return os;
}

ItalianRank italianRanks[] = { Deuce, Three, Four, Five, Six, Seven, Fante, Cavallo, Re };
int nbrItalianRank = 10;
