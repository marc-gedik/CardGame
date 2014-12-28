#include "Deck.hpp"

#include "SimpleCard.hpp"
#include "FrenchCard.hpp"

#include <iostream>
template <typename Suit, typename Rank>
SimpleCard<Suit, Rank>*  init(int nbrDeck, Suit* suits, int nbrSuit, Rank* ranks, int nbrRank){
  int n = nbrDeck * nbrFrenchSuit * nbrFrenchRank;
  SimpleCard<Suit, Rank>* cards = new SimpleCard<Suit, Rank>[n];

  for(int i = 0; i < nbrDeck; i++){
    for(int j = 0; j < nbrSuit; j++){
      for(int k = 0; k < nbrRank; k++){
	int nCard = (i + j * nbrDeck) * nbrRank + k;
	cards[nCard] = SimpleCard<Suit, Rank>(suits[j], ranks[k]);
      }
    }
  }
  return cards;
}

template <>
Deck<FrenchCard >::Deck(int nbrDeck){
  cards = init(nbrDeck, frenchSuits, nbrFrenchSuit, frenchRanks, nbrFrenchRank);
}

