#ifndef H_PLAYER
#define H_PLAYER

#include "Card.hpp"
#include "Hand.hpp"
#include "Action.hpp"
#include "DiscardPile.hpp"

class Player {
protected:
  Hand hand;
  DiscardPile discardPile;
public:
  virtual void ask(Action&, int) = 0;

  void add(Card&);
  void add(const CardContainer&);

  void discard(CardContainer&);

  bool emptyHand();
};

#endif
