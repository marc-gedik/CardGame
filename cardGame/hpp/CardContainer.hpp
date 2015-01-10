#ifndef H_CARD_CONTAINER
#define H_CARD_CONTAINER

#include "Card.hpp"

class CardContainer {
private:
  Card** cards;
  int size;

public:

  CardContainer() : size(0) {}
  CardContainer(Card**, int);
  CardContainer(Card&);

  int getSize() const;

  Card& getElement(int i) const;

};
#endif
