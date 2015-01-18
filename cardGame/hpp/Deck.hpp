#ifndef H_DECK
#define H_DECK

#include "Melange.hpp"
#include "Card.hpp"
#include "CardContainer.hpp"

#include <iostream>

class Deck {
private:
  Card** cards;
  int nbCards;
public:
  Deck() {}
  Deck(int, CardContainer);
  ~Deck();

  Card& deal();

  void shuffle();

  CardContainer removeAll();
  int getSize();
};

#endif
