#ifndef H_CAN_REMOVE_PILE
#define H_CAN_REMOVE_PILE

#include "CardContainer.hpp"

template<typename T>
class CanRemovePile {
public:
  virtual CardContainer<T> remove(int*, int) = 0;
};

#endif
