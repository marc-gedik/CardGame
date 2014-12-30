#include "Card.hpp"

bool Card::operator< (const Card& card) const{
 return getValue() < card.getValue();
}

bool Card::operator<=(const Card& card) const{
return  getValue() <= card.getValue();
}

bool Card::operator==(const Card& card) const{
 return getRealValue() == card.getRealValue();
}

bool Card::operator> (const Card& card) const{
  return getValue() > card.getValue();
}

bool Card::operator>=(const Card& card) const{
  return getValue() >= card.getValue();
}

ostream& operator<<(ostream& os, Card& c){
  if(c.isVisible())
    return c.print(os);
  else
    return os << "[";
}

