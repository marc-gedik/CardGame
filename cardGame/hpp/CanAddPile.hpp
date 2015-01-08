#ifndef H_CAN_ADD_PILE
#define H_CAN_ADD_PILE

#include "CardContainer.hpp"

class CanAddPile {
public:
  virtual void add(const CardContainer&) = 0;
};

#endif
