#ifndef H_ACTION
#define H_ACTION

#include "CardContainer.hpp"
#include "CanAddRemovePile.hpp"
#include "DiscardPile.hpp"
#include "Movement.hpp"

class Action {
private:
  CanAddRemovePile *from;
  DiscardPile * to;
  CardContainer movingCards, destination;
  Movement movement;

  bool moving;
  void checkMovement();
public:
  Action(){}


  void setFrom(CanAddRemovePile& , Movement&);

  void setTo(DiscardPile&, const CardContainer&);

  void countMovingCards(int);

  void movingCardsFromTop();

  CardContainer& getFromCards();

  void apply();

  bool isPioche();
  bool isPlusTwo();
  bool isSkip();
  bool isReverse();
  bool isJoker();
  bool isSuperJoker();

  bool sameRank();
  bool sameColor();

  void reset();
};

#endif
