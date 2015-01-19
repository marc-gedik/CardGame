#include "CardAction.hpp"

#include "exception/IllegalMovement.hpp"
#include "exception/IllegalEntry.hpp"

void CardAction::checkMovement(){
  if(movement.getMin() < 0 || movement.getMax() >= from->getSize())
    throw IllegalEntry();
  //  else
  //    try{form->revome(momvement)}
  //    catch(... e){ throw IllegalEntry }
}

bool CardAction::isPioche(){
 return movement.isPioche();
}
void CardAction::setFrom(CanAddRemovePile& from, Movement& movement){
  this->movement = movement;
  this->from = &from;
  moving = false;
  if(!isPioche())
    checkMovement();
}

void CardAction::setTo(DiscardPile& to, const CardContainer& destination){
  this->to = &to;
  this->destination = destination;
}

void CardAction::countMovingCards(int n){
  if(movement.getSize() != n)
    throw IllegalMovement("Number of cards is invalid");
}

void CardAction::movingCardsFromTop(){
  for(int i = 0; i < movement.getSize(); i++)
    if(movement[i] != i)
      throw IllegalMovement("Cards must be taken from the top of you hand");
}

void CardAction::flip(){
  if(!moving){
    moving = true;
    movingCards = from->remove(movement);
  }
  for(int i = 0; i < movingCards.getSize(); i++)
    movingCards.getElement(i).flip();
}

CardContainer& CardAction::getFromCards(){
  moving = true;
  movingCards = from->remove(movement);
  return movingCards;
}

void CardAction::apply(){
  if(moving)
    to->add(movingCards);
  else
    to->add(from->remove(movement));
}

void CardAction::reset(){
  moving = false;
  from->add(movingCards);
}

bool CardAction::sameRank(){
  if(!moving){
    moving = true;
    movingCards = from->remove(movement);
  }
  cout << to->look() << endl;
  for(int i=0; i < movingCards.getSize(); i++)
    if(to->look() !=  movingCards.getElement(i))
      return false;

  return true;
}

bool CardAction::sameColor(int color){
  if(!moving){
    moving = true;
    movingCards = from->remove(movement);
  }
  for(int i=0; i<  movingCards.getSize(); i++)
    if(movingCards.getElement(i).getSuit() != color)
      return false;
  return true;
}

bool CardAction::sameColor(){
  if(!moving){
    moving = true;
    movingCards = from->remove(movement);
  }
  for(int i=0; i<  movingCards.getSize(); i++)
    if(!(movingCards.getElement(i)).sameSuit((to->look())))
      return false;

  return true;
}
