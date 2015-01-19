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
  moving = false;
  if(!isPioche())
    checkMovement();
}

void Action::setTo(DiscardPile& to, const CardContainer& destination){
  this->to = &to;
  this->destination = destination;
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

void Action::reset(){
  moving = false;
  from->add(movingCards);
}





bool Action::isPlusTwo(){
  if((to->look()).getRank()==10)
    return true;
  return false;
}


bool Action::isReverse(){
  if((to->look()).getRank()==11)
    return true;
  return false;
}



bool Action::isSkip(){
  cout<<"rank: "<< (to->look()).getRank()<<endl;
  return true;
}





bool Action::isJoker(){
  cout<<"rank : "<< (to->look()).getRank()<<endl;
  return true;
}


bool Action::isSuperJoker(){
  cout<<"rank: "<< (to->look()).getRank()<<endl;
  return true;
}

bool Action::sameRank(){
  if(!moving){
    moving = true;
    movingCards = from->remove(movement);
  }
  for(int i=0; i < movingCards.getSize(); i++)
    if(to->look() !=  movingCards.getElement(i))
      return false;

  return true;
}




bool Action::sameColor(){
  if(!moving){
    cout << "ok" << endl;
    moving = true;
    movingCards = from->remove(movement);
  }
  for(int i=0; i<  movingCards.getSize(); i++)
    if(!(movingCards.getElement(i)).sameSuit((to->look())))
      return false;

  return true;
}
