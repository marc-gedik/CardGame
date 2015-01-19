#ifndef H_PLAYER
#define H_PLAYER

#include "Card.hpp"
#include "Hand.hpp"
#include "CardAction.hpp"
#include "Question.hpp"

#include "DiscardPile.hpp"

class Player {
protected:
  Hand hand;
  DiscardPile discardPile;
public:
  virtual void ask(CardAction&, int, int request=0) = 0;
  virtual void ask(Question&, int, int request=0) = 0;

  void add(Card&);
  void add(const CardContainer&);

  void discard(CardContainer&);

  bool emptyHand();
};

#endif
