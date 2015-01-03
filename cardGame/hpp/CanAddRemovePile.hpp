#ifndef H_CAN_ADD_REMOVE_PILE
#define H_CAN_ADD_REMOVE_PILE

#include "CanAddPile.hpp"
#include "CanRemovePile.hpp"

template<typename T>
class CanAddRemovePile
  : public CanAddPile<T>,
    public CanRemovePile<T> {
};

#endif
