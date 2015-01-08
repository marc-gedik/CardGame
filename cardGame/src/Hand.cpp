#include "Hand.hpp"

void Hand::add(Card& card){
  hand.push_front (&card);
}

void Hand::add(const CardContainer& cards){
  for(int i = 0; i < cards.getSize(); i++)
    add(cards.getElement(i));
}

CardContainer Hand::remove(Movement& movement){
  throw "Todo";
}

bool Hand::isEmpty(){
  return hand.empty();
}

int Hand::getSize(){
  return hand.size();
}

ostream& Hand::print(ostream& os){
  list<Card*>::iterator
    itCurrent = hand.begin(),
    itEnd = hand.end();

  while(itCurrent++ != itEnd){
    os << *(*itCurrent) << " ";
    itCurrent++;
  }
  return os;
}

ostream& operator<<(ostream& os, Hand& hand){
  return hand.print(os);
}
