#ifndef H_CARD
#define H_CARD

#include <iostream>

using namespace std;

template<typename Suit, typename Rank>
class Card {
protected:
  bool hidden;
  Suit suit;
  Rank rank;
public:
  Card() {}
  Card(Suit s, Rank r, bool hide = false)
    : suit(s), rank(r), hidden(hide) {}
  ~Card(){
    //    cout << "Carte detruit";
  }
  bool isHidden()  const { return hidden; }
  bool isVisible() const { return !hidden; }
  void flip() { hidden = !hidden; }

  bool operator< (const Card& card) const { return rank <  card.rank; }
  bool operator<=(const Card& card) const { return rank <= card.rank; }
  bool operator> (const Card& card) const { return rank >  card.rank; }
  bool operator>=(const Card& card) const { return rank >= card.rank; }

  //  bool operator!=(const Card& card) const { return rank != card.rank || suit != card.suit; }
  //  bool operator==(const Card& card) const { return rank == card.rank && suit == card.suit; }
  bool operator!=(const Card& card) const { return rank != card.rank; }
  bool operator==(const Card& card) const { return rank == card.rank; }

  ostream& print(ostream& os) { return isVisible() ? os << rank << suit : os << "["; }

  friend ostream& operator<<(ostream& os, Card<Suit,Rank>& card){
    return card.print(os);
  }

};

#endif
