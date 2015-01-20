#include "Deck.hpp"

Deck::Deck(int nbrDeck, CardContainer container){
  int n = container.getSize();
  nbCards = nbrDeck * n;
  cards = new Card * [nbCards];
  for(int i = 0; i < nbrDeck; i++)
    for(int j = 0; j < n; j ++)
      cards[i*n + j] = container.getElement(j).clone();
  shuffle();
}

#include <iostream>
Deck::~Deck(){
  std::cout << "Deck detruit" << std::endl;
  for(int i = 0; i < nbCards; i++)
    delete cards[i];
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


CardContainer Deck::removeAll(){
  return CardContainer(this->cards,this->nbCards);
}
