#ifndef H_PLAYER
#define H_PLAYER

#include "Card.hpp"
#include "Hand.hpp"
#include "Action.hpp"

class Player {
protected:
  Hand hand;
public:
  virtual void ask(Action&) = 0;

  void add(Card&);
  void add(const CardContainer&);

  bool emptyHand();
};

#endif
