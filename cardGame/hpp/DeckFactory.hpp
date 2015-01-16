#ifndef H_DECK_FACTORY
#define H_DECK_FACTORY

#include "Deck.hpp"
#include <iostream>

class DeckFactory {
public:
  enum Decks { French, Italian, Uno };

  Deck* createDeck(std::string, int);
};

#endif
