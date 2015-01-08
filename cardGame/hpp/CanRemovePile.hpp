#ifndef H_CAN_REMOVE_PILE
#define H_CAN_REMOVE_PILE

#include "CardContainer.hpp"
#include "Movement.hpp"

class CanRemovePile {
public:
  virtual CardContainer remove(Movement&) = 0;
};

#endif
