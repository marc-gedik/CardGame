#ifndef H_ACTION
#define H_ACTION

#include "IllegalMovement.hpp"
#include "CardContainer.hpp"
#include "CanAddRemovePile.hpp"
#include "CanAddPile.hpp"

template<typename T>
class Action {
private:
  CanAddRemovePile<T> *from;
  CanAddPile<T> *to;
  CardContainer<T> movingCards, destination;
  int* cardsToMove;
  int nbCardsToMove;

public:
  Action(){}

  void setFrom(CanAddRemovePile<T>* from, int* cardsToMove, int nbCardsToMove){
    this->cardsToMove = cardsToMove;
    this->nbCardsToMove = nbCardsToMove;
    this->from = from;
  }

  void setTo(CanAddPile<T>* to, CardContainer<T> destination){
    this->to = to;
    this->destination = destination;
  }

  void countMovingCards(int n){

    if(nbCardsToMove != n)
      throw IllegalMovement("The number of cards must be : " + n);
  }

  void movingCardsFromTop(){
    for(int i = 0; i < nbCardsToMove; i++)
      if(cardsToMove[i] != i)
	throw IllegalMovement("Cards must be taken from the top of you hand");
  }

  void apply(){
    to->add(from->remove(cardsToMove, nbCardsToMove));
  }
};

#endif
