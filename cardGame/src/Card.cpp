#include "Card.hpp"

Card::~Card(){
  cout << "Carte detruit" << endl;
}

bool Card::operator< (const Card& card) const { return getRank() <  card.getRank(); }
bool Card::operator<=(const Card& card) const { return getRank() <= card.getRank(); }
bool Card::operator> (const Card& card) const { return getRank() >  card.getRank(); }
bool Card::operator>=(const Card& card) const { return getRank() >= card.getRank(); }

bool Card::operator!=(const Card& card) const { return getRank() != card.getRank(); }
bool Card::operator==(const Card& card) const { return getRank() == card.getRank(); }

ostream& operator<<(ostream& os, Card& card){
  return card.print(os);
}
