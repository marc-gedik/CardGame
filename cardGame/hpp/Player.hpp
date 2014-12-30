#ifndef H_PLAYER
#define H_PLAYER

#include "Hand.hpp"

class Player {
private:
  Hand<Card*> hand;
public:
  Player(){}
};

#endif
