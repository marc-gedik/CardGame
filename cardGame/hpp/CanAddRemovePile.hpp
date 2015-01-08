#ifndef H_CAN_ADD_REMOVE_PILE
#define H_CAN_ADD_REMOVE_PILE

#include "CanAddPile.hpp"
#include "CanRemovePile.hpp"

class CanAddRemovePile
  : public CanAddPile,
    public CanRemovePile {
public:
  virtual int getSize() = 0;
};

#endif
