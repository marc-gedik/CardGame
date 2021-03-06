#include "UnoCard.hpp"

namespace uno {

  std::ostream& operator<<(std::ostream& os, const UnoRank& rank){
    switch(rank){
    case Zero	 : return os << "O";
    case One	 : return os << "1";
    case Two	 : return os << "2";
    case Three	 : return os << "3";
    case Four 	 : return os << "4";
    case Five 	 : return os << "5";
    case Six  	 : return os << "6";
    case Seven	 : return os << "7";
    case Eight	 : return os << "8";
    case Nine 	 : return os << "9";
    case PlusTwo : return os << "+2";
    case Reverse : return os << "\xE2\x86\xBA";
    case Skip	 : return os << "Skip";
    case Joker	 : return os << "J";
    case SuperJoker: return os << "+4";
    default        : return os << "_";
    }
  }

  UnoRank unoRanks[] = { Zero, One, Two, Three, Four, Five, Six, Seven, Eight, Nine, PlusTwo, Reverse, Skip, Joker, SuperJoker };
  int nUnoRanks = 15;

  std::ostream& operator<<(std::ostream& os, const UnoSuit& suit){
    switch(suit){
    case Blue  	: return os << "B";
    case Green	: return os << "G";
    case Yellow : return os << "Y";
    case Red  	: return os << "R";
    case NoColor: return os << "~";
    default     : return os << "_";
    }
  }

  UnoSuit unoSuits[]= { Blue, Green, Red, Yellow, NoColor };
  int nUnoSuits = 5;

}
