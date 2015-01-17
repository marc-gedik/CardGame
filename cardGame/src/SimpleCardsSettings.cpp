#include "SimpleCardsSettings.hpp"

template <typename Suit, typename Rank>
void SimpleCardsSettings<Suit, Rank>::setTrump(Suit& suit){
  trump = suit;
}

template <typename Suit, typename Rank>
void SimpleCardsSettings<Suit, Rank>::setValue(Rank& rank, int value){
  values.insert(rank, value);
}

template <typename Suit, typename Rank>
int SimpleCardsSettings<Suit, Rank>::compare(const Card& cardA, const Card& cardB){
  if(cardA.getSuit() == trump)
    if(cardB.getSuit() == trump)
      return cardA.getRank() - cardB.getRank();
    else
      return 1;
  else
    if(cardB.getSuit() == trump)
      return -1;
    else
      return cardA.getRank() - cardB.getRank();
}
