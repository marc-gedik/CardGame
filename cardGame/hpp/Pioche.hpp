#ifndef H_PIOCHE
#define H_PIOCHE

#include <stack>

#include "CardContainer.hpp"

class Pioche {

private:
  stack<Card*> pioche ;

public:
  Pioche(CardContainer);

  Card& draw();
};

#endif
