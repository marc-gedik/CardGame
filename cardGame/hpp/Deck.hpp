#ifndef H_DECK
#define H_DECK

#include "Melange.hpp"
#include "Card.hpp"

#include <iostream>

class Deck {
protected:
  Card** cards;
  int nbCards;
public:
  Deck(int nbrDecks);
  ~Deck();

  Card& deal();

  void shuffle();

  int getSize();
};

#endif
