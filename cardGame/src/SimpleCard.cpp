#include "SimpleCard.hpp"

template <typename Suit, typename Rank>
bool SimpleCard<Suit, Rank>::operator< (const SimpleCard& card) const {
  return rank < card.rank;
}

template <typename Suit, typename Rank>
bool SimpleCard<Suit, Rank>::operator<=(const SimpleCard& card) const {
  return rank <= card.rank;
}

template <typename Suit, typename Rank>
bool SimpleCard<Suit, Rank>::operator==(const SimpleCard& card) const {
  return rank == card.rank;
}

template <typename Suit, typename Rank>
bool SimpleCard<Suit, Rank>::operator> (const SimpleCard& card) const {
  return rank > card.rank;
}

template <typename Suit, typename Rank>
bool SimpleCard<Suit, Rank>::operator>=(const SimpleCard& card) const {
  return rank >= card.rank;
}

template <typename Suit, typename Rank>
bool SimpleCard<Suit, Rank>::isHidden(){
  return hidden;
}

template <typename Suit, typename Rank>
bool SimpleCard<Suit, Rank>::isVisible(){
  return !hidden;
}
