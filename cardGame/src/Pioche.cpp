#include "Pioche.hpp"

Pioche::Pioche(CardContainer& cards){
  for(int i = 0; i < cards.getSize(); i++)
    pioche.push(&cards.getElement(i));
}

Card& Pioche::draw(){
  Card* tmp = pioche.top();
  pioche.pop();
  return *tmp;
}
