#ifndef H_PLAYER
#define H_PLAYER

#include "Card.hpp"
#include "Hand.hpp"
#include "CardAction.hpp"
#include "Question.hpp"

#include <iostream>
#include "DiscardPile.hpp"

class Player {
protected:
  Hand hand;
  DiscardPile discardPile;
  int score;
  std::string name;
public:
  virtual void ask(CardAction&, int, int request=0) = 0;
  virtual void ask(Question&, int, int request=0) = 0;

  void add(Card&);
  void add(const CardContainer&);

  void discard(CardContainer&);

  void incrementScore(int);
  bool emptyHand();

  int getScore();
  std::string getName();
};

#endif
