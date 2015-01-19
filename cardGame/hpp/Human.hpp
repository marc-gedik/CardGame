#ifndef H_HUMAN
#define H_HUMAN

#include "Player.hpp"
#include "CardAction.hpp"
#include "Question.hpp"

class Human : public Player {
public:
  Human(){}
  virtual void ask(CardAction&, int,  int request=0);
  virtual void ask(Question&, int,  int request=0);

};

#endif
