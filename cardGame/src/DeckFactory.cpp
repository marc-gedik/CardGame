#include "DeckFactory.hpp"

#include "CardFactory.hpp"

Deck* DeckFactory::createDeck(std::string s, int n){
  CardFactory cardFactory;

  return new Deck(n, cardFactory.createCards(s));

}
