#ifndef H_CARD_FACTORY
#define H_CARD_FACTORY

#include <iostream>

#include "CardContainer.hpp"

class CardFactory {

private:
  template <typename Suit, typename Rank>
  CardContainer createCards(Suit*, int, Rank*, int);

  template <typename Suit, typename Rank>
  CardContainer createUnoCards(Suit*, int, Rank*, int);
  

public:
  CardContainer createCards(string);

};

#endif
