#include "SameOrTrumpSettings.hpp"

int SameOrTrumpSettings::compare(const Card& cardA, const Card& cardB) const{
  int a = get(cardA);
  int b = get(cardB);
  cout << "Atout : " << trump;
  cout << "(" << a << "," << cardA.getSuit() << ")"
       << " vs " << "(" << b << "," << cardB.getSuit() << ")";
  if(cardA.getSuit() == trump)
    if(cardB.getSuit() == trump)
      return a - b;
    else
      return 1;
  else
    if(cardB.getSuit() == trump)
      return -1;
    else
      return a - b;
}
