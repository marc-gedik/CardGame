#include "Card.hpp"

bool Card::operator< (const Card& card) const{
 return getValue() < card.getValue();
}

bool Card::operator<=(const Card& card) const{
return  getValue() <= card.getValue();
}

bool Card::operator==(const Card& card) const{
 return getValue() == card.getValue();
}

bool Card::operator> (const Card& card) const{
  return getValue() > card.getValue();
}

bool Card::operator>=(const Card& card) const{
  return getValue() >= card.getValue();
}

void Card::printCard(){
  std::cout<<"carte : " << this->getValue() << std::endl;
}
