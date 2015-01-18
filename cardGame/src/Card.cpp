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

bool Card::sameSuit(const Card card) { return getSuit() == card.getSuit(); }

ostream& operator<<(ostream& os, Card& card){
  return card.print(os);
}
