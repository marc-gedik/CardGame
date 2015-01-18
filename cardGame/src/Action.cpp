#include "Action.hpp"

#include "exception/IllegalMovement.hpp"
#include "exception/IllegalEntry.hpp"

void Action::checkMovement(){
  if(movement.getMin() < 0 || movement.getMax() >= from->getSize())
    throw IllegalEntry();
  //  else
  //    try{form->revome(momvement)}
  //    catch(... e){ throw IllegalEntry }
}

bool Action::isPioche(){
 return movement.isPioche();
}
void Action::setFrom(CanAddRemovePile& from, Movement& movement){
  this->movement = movement;
  this->from = &from;
  if(!isPioche())
    checkMovement();
}

void Action::setTo(DiscardPile& to, const CardContainer& destination){
  this->to = &to;
  this->destination = destination;
}


bool Action::sameRank(){
  moving = true;
  movingCards = from->remove(movement);
  for(int i=0; i<  movingCards.getSize(); i++){
    if(to->look() !=  movingCards.getElement(i))
      from->add(movingCards);
      return false;
  }
  moving= false;
  return true;
}

void Action::countMovingCards(int n){
  if(movement.getSize() != n)
    throw IllegalMovement("The number of cards must be : " + n );
}

void Action::movingCardsFromTop(){
  for(int i = 0; i < movement.getSize(); i++)
    if(movement[i] != i)
      throw IllegalMovement("Cards must be taken from the top of you hand");
}

CardContainer& Action::getFromCards(){
  moving = true;
  movingCards = from->remove(movement);
  return movingCards;
}

void Action::apply(){
  if(moving)
    to->add(movingCards);
  else
    to->add(from->remove(movement));

}
