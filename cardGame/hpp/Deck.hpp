#ifndef H_DECK
#define H_DECK

#include "Melange.hpp"

#include <iostream>

template <typename T>
class Deck {
protected:
  T** cards;
  int nbCards;
public:
  Deck(int nbrDecks);
  ~Deck() {
    std::cout << "Deck detruit" << std::endl;
    for(int i = 0; i < nbCards; i++)
      delete cards[i];
    delete [] cards;
  }

  T& pop(){
    return *cards[--nbCards];
  }

  void shuffle(int size){   melangePharaon(cards, size, 10); }
  int getSize(){ return nbCards; }
};

#endif
