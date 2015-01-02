#ifndef H_CAN_ADD_PILE
#define H_CAN_ADD_PILE

#include "CardContainer.hpp"
template<typename T>
class CanAddPile {
public:
  virtual void add(T&) = 0;
  virtual void add(CardContainer<T>) = 0;
};

#endif
