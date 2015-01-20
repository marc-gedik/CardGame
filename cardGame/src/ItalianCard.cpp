#include "ItalianCard.hpp"

namespace it{

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

  ItalianRank italianRanks[] = { Deuce, Three, Four, Five, Six, Seven, Fante, Cavallo, Re };
  int nItalianRanks = 10;

  std::ostream& operator<<(std::ostream& os, const ItalianSuit& suit){
    switch(suit){
    case Spade  : return os << "S";
    case Bastoni: return os << "B";
    case Denari : return os << "D";
    case Coppe  : return os << "Co";
    default     : return os << "_";
    }
  }

  ItalianSuit italianSuits[] = { Spade, Bastoni, Denari, Coppe };
  int nItalianSuits = 4;
}
