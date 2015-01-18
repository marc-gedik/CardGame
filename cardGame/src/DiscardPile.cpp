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

bool DiscardPile::contains(CardContainer cards){
  if(cards.getSize() == 1){
    Card& c = cards.getElement(0);

    int size = discardPile.size();
    list<Card*>::iterator it = discardPile.begin();

    for(int i = 0; i < size; i++)
      if (**it == c)
	return true;
  }
  return false;
}

CardContainer DiscardPile::remove(CardContainer cards){
  if(cards.getSize() == 1){
    Card& c = cards.getElement(0);
    int size = discardPile.size();
    list<Card*>::iterator it = discardPile.begin();

    for(int i = 0; i < size; it++,i++)
      if (**it == c){
	Card* card = *it;
	discardPile.erase(it);
	return CardContainer(*card);
      }
    return cards;
  }
  else
    throw "Not needed";
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
