#include "Hand.hpp"

void Hand::add(Card& card){
  hand.push_front (&card);
}

void Hand::add(const CardContainer& cards){
  for(int i = 0; i < cards.getSize(); i++)
    add(cards.getElement(i));
}

CardContainer Hand::remove(Movement& movement){
  list<Card*>::iterator it = hand.begin();
  int k = 0;
  int n = movement.getSize();
  Card** cards = new Card * [n];
  bool find;
  for (int i = 0; i < n; i++){
    find = false;
    it = hand.begin();
    k = 0;
    while (it != hand.end()){
      if(movement[i] == k){
	cards[i] = *it;
	it = hand.erase(it);
	find = true;
	break;
      }
      k++;
    }
    if(!find)
      throw "Todo Not find";
  }

  return CardContainer(cards, n);
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

  while(itCurrent != itEnd){
    os << *(*itCurrent) << " ";
    itCurrent++;
  }
  return os;
}

ostream& operator<<(ostream& os, Hand& hand){
  return hand.print(os);
}
