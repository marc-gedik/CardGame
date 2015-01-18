#include "DiscardPile.hpp"

void DiscardPile::add(Card &x){
  discardPile.push_front(&x);
}

void DiscardPile::add(const CardContainer& c){
  for(int i = 0; i < c.getSize(); i++)
    add(c.getElement(i));
}

CardContainer DiscardPile::removeAll(){
  int size = discardPile.size();
  Card** tabCard = new Card *[size];

  list<Card*>::iterator it = discardPile.begin();

  for(int i = 0; i < size; i++){
    tabCard[i] = *it;
    it = discardPile.erase(it);
  }
  return CardContainer(tabCard, size);
}

Card& DiscardPile::remove(Card& c){
  return c;
}

Card& DiscardPile::look(){
 return *discardPile.front();
}

ostream& DiscardPile::print(ostream& os){
  list<Card*>::iterator
    itCurrent = discardPile.begin(),
    itEnd = discardPile.end();

  while(itCurrent != itEnd){
    os << *(*itCurrent) << " ";
    itCurrent++;
  }
  return os;
}

ostream& operator<<(ostream& os, DiscardPile& pile){
  return pile.print(os);
}
