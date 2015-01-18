#ifndef H_ACTION
#define H_ACTION

#include "CardContainer.hpp"
#include "CanAddRemovePile.hpp"
#include "CanAddPile.hpp"
#include "Movement.hpp"

class Action {
private:
  CanAddRemovePile *from;
  CanAddPile * to;
  CardContainer movingCards, destination;
  Movement movement;

  void checkMovement();
public:
  Action(){}


  void setFrom(CanAddRemovePile& , Movement&);

  void setTo(CanAddPile&, const CardContainer&);

  bool isPioche();

  void countMovingCards(int n);

  void movingCardsFromTop();

  void apply();

  
};

#endif
