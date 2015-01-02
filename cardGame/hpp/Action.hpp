#ifndef H_ACTION
#define H_ACTION

#include "IllegalMovement.hpp"
#include "CardContainer.hpp"

template<typename T>
class Action {
private:
  CanAddPile<T>* from, *to;
  CardContainer<T> movingCards, destination;
public:
  Action(){}

  void setFrom(CanAddPile<T>* from, CardContainer<T> movingCards){
    this->movingCards = movingCards;
    this->destination = destination;
  }

  void setTo(CanAddPile<T>* to, CardContainer<T> destination){
    this->to = to;
    this->destination = destination;
  }

  void countMovingCards(int n){
    if(movingCards.getSize() != n){
      from->add(movingCards);
      throw IllegalMovement("The number of cards must be : " + n);
    }
  }

  void apply(){
    to->add(movingCards);
  }
};

#endif
