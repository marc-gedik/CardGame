#include "Deck.hpp"

// template <typename Suit, typename Rank>
// Card**  init(int nbrDeck, Suit* suits, int nbrSuit, Rank* ranks, int nbrRank){
//   int n = nbrDeck * nbrFrenchSuit * nbrFrenchRank;
//   Card** cards = new Card * [n];

//   for(int i = 0; i < nbrDeck; i++){
//     for(int j = 0; j < nbrSuit; j++){
//       for(int k = 0; k < nbrRank; k++){
// 	int nCard = (i + j * nbrDeck) * nbrRank + k;
// 	cards[nCard] = new Card(suits[j], ranks[k]);
//       }
//     }
//   }
//   return cards;
// }

Deck::Deck(int nbrDeck){
  cout << "Todo init deck" << endl;
  throw;
  // nbCards = nbrDeck * nbrFrenchSuit * nbrFrenchRank;
  // cards = init(nbrDeck, frenchSuits, nbrFrenchSuit, frenchRanks, nbrFrenchRank);
  shuffle();
}

#include <iostream>
Deck::~Deck(){
  std::cout << "Deck detruit" << std::endl;
  delete [] cards;
}

Card& Deck::deal(){
    return *cards[--nbCards];
}

void Deck::shuffle(){
  melangePharaon(cards, nbCards, 10);
}

int Deck::getSize(){
  return nbCards;
}
