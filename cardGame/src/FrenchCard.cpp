#include "FrenchCard.hpp"

using namespace fr;

std::ostream& operator<<(std::ostream& os, const FrenchRank& rank){
  switch(rank){
  case Deuce: return os << "2";
  case Three: return os << "3";
  case Four : return os << "4";
  case Five : return os << "5";
  case Six  : return os << "6";
  case Seven: return os << "7";
  case Eight: return os << "8";
  case Nine : return os << "9";
  case Ten  : return os << "10";
  case Jack : return os << "J";
  case Queen: return os << "Q";
  case King : return os << "K";
  case Ace  : return os << "A";
  default   : return os << "_";
  }
}

FrenchRank frenchRanks[] = { Deuce, Three, Four, Five, Six, Seven, Eight, Nine, Ten, Jack, Queen, King, Ace };
int nFrenchRanks = 13;

std::ostream& operator<<(std::ostream& os, const FrenchSuit& suit){
  switch(suit){
  case Heart  : return os << "\xE2\x99\xA5";
  case Diamond: return os << "\xE2\x99\xA6";
  case Club   : return os << "\xE2\x99\xA3";
  case Spade  : return os << "\xE2\x99\xA0";
  default     : return os << "_";
  }
}

FrenchSuit frenchSuits[] = { Heart, Diamond, Club, Spade };
int nFrenchSuits = 4;
