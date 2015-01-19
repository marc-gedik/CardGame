#ifndef H_CARD_ACTION
#define H_CARD_ACTION

#include "Action.hpp"
#include "CardContainer.hpp"
#include "CanAddRemovePile.hpp"
#include "DiscardPile.hpp"
#include "Movement.hpp"

class CardAction : public Action {
private:
  CanAddRemovePile *from;
  DiscardPile * to;
  CardContainer movingCards, destination;
  Movement movement;

  bool moving;
  void checkMovement();
public:
  CardAction(){}


  void setFrom(CanAddRemovePile& , Movement&);

  void setTo(DiscardPile&, const CardContainer&);

  void countMovingCards(int);

  void movingCardsFromTop();

  void flip();

  CardContainer& getFromCards();

  void apply();

  bool isPioche();

  bool sameRank();
  bool sameRank(int rank);

  bool sameColor();
  bool sameColor(int color);

  void reset();
};

#endif
