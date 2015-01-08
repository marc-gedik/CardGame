#include "CardContainer.hpp"

CardContainer::CardContainer(Card** xs, int nbCard)
  : size(nbCard) {
  cards = new Card *[size];
  for (int i=0; i<nbCard; i++)
    cards[i]=xs[i];
}

CardContainer::CardContainer(Card& x){
  size = 1;
  cards = new Card*[size];
  cards[0] = &x;
}

int CardContainer::getSize() const {
  return size;
}

Card& CardContainer::getElement(int i) const {
  return *cards[i];
}
