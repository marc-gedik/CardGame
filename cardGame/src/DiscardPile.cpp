#include "DiscardPile.hpp"

void DiscardPile::add(Card &x){
  discardPile.push(&x);
}

void DiscardPile::add(const CardContainer& c){
  for(int i = 0; i < c.getSize(); i++)
    add(c.getElement(i));
}

CardContainer DiscardPile::removeAll(){
  int size = discardPile.size();
  Card** tabCard = new Card *[size];

  for(int i = 0; i < size; i++){
    tabCard[i] = discardPile.top();
    discardPile.pop();
  }
  return CardContainer(tabCard, size);
}

Card& DiscardPile::look(){
  return *discardPile.top();
}

ostream& DiscardPile::print(ostream& os){
  if(discardPile.size() == 0)
    return os << "Pile vide";
  else
    return os << *discardPile.top();
  return os;
}

ostream& operator<<(ostream& os, DiscardPile& pile){
  return pile.print(os);
}
