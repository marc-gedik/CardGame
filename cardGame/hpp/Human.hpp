#ifndef H_HUMAN
#define H_HUMAN

#include "Player.hpp"
#include "Action.hpp"

class Human : public Player {
public:
  Human(){}
  virtual void ask(Action&, int);
};

#endif
