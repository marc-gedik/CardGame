#include "Deck.hpp"

#include "Card.hpp"
#include "FrenchCard.hpp"

#include "Melange.hpp"

template <typename Suit, typename Rank>
Card<Suit, Rank>**  init(int nbrDeck, Suit* suits, int nbrSuit, Rank* ranks, int nbrRank){
  int n = nbrDeck * nbrFrenchSuit * nbrFrenchRank;
  Card<Suit, Rank>** cards = new Card<Suit, Rank> * [n];

  for(int i = 0; i < nbrDeck; i++){
    for(int j = 0; j < nbrSuit; j++){
      for(int k = 0; k < nbrRank; k++){
	int nCard = (i + j * nbrDeck) * nbrRank + k;
	cards[nCard] = new Card<Suit, Rank>(suits[j], ranks[k]);
      }
    }
  }
  return cards;
}

template <>
Deck<FrenchCard >::Deck(int nbrDeck){
  nbCards = nbrDeck * nbrFrenchSuit * nbrFrenchRank;
  cards = init(nbrDeck, frenchSuits, nbrFrenchSuit, frenchRanks, nbrFrenchRank);
  shuffle(nbCards);
}

template <typename T>
void Deck<T>::shuffle(int size){
  melangePharaon(cards, size, 10);
}
