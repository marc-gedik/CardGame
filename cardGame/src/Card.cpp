#include "Card.hpp"

bool Card::operator< (const Card& card) const{
  getValue() < card.getValue();
}

bool Card::operator<=(const Card& card) const{
  getValue() <= card.getValue();
}

bool Card::operator==(const Card& card) const{
  getValue() == card.getValue();
}

bool Card::operator> (const Card& card) const{
  getValue() > card.getValue();
}

bool Card::operator>=(const Card& card) const{
  getValue() >= card.getValue();
}
