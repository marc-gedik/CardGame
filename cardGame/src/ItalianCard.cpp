#include "ItalianCard.hpp"

std::ostream& operator<<(std::ostream& os, const ItalianRank& rank){
  switch(rank){
  case Ace    : return os << "A";
  case Deuce  : return os << "2";
  case Three  : return os << "3";
  case Four   : return os << "4";
  case Five   : return os << "5";
  case Six    : return os << "6";
  case Seven  : return os << "7";
  case Fante  : return os << "F";
  case Cavallo: return os << "C";
  case Re     : return os << "R";
  default     : return os << "_";
  }
  return os;
}

// ItalianRank italianRanks[] = { Deuce, Three, Four, Five, Six, Seven, Fante, Cavallo, Re };
// int nbrItalianRank = 10;

std::ostream& operator<<(std::ostream& os, const ItalianSuit& suit){
  switch(suit){
  case Spade  : return os << "_";
  case Bastoni: return os << "_";
  case Denari : return os << "_";
  case Coppe  : return os << "_";
  default     : return os << "_";
  }
}

// ItalianSuit italianSuits[] = { Spade, Bastoni, Denari, Coppe };
// int nbrItalianSuit = 4;
