#include "TrumpSettings.hpp"

void TrumpSettings::setTrump(int suit){
  trump = suit;
}

void TrumpSettings::setValue(int rank, int value){
  values[rank] = value;
}

int TrumpSettings::get(const Card& card) const{
  int rank = card.getRank();

  if(values.count(rank)>0)
    return values.at(rank);
  else
    return rank;
}

int TrumpSettings::compare(const Card& cardA, const Card& cardB) const{
  int a = get(cardA);
  int b = get(cardB);
  if(cardA.getSuit() == trump)
    if(cardB.getSuit() == trump)
      return a - b;
    else
      return 1;
  else
    if(cardB.getSuit() == trump)
      return -1;
    else if (cardB.getSuit() == cardA.getSuit())
      return a - b;
    else
      return 1;
}
