#include "CardFactory.hpp"

#include "FrenchCard.hpp"
//#include "UnoCard.hpp"

template <typename Suit, typename Rank>
CardContainer CardFactory::createCards(Suit* suits, int nSuits, Rank* ranks, int nRanks){
   int n = nSuits * nRanks;
   Card** cards = new Card * [n];

   for(int i = 0; i < nSuits; i++)
     for(int j = 0; j < nRanks; j++)
       cards[i*nRanks + j] = new SimpleCard<Suit, Rank>(suits[i], ranks[j]);

   return CardContainer(cards, n);
}

CardContainer CardFactory::createCards(string s){
  if(s == "Fr") return createCards(frenchSuits, nFrenchSuits, frenchRanks, nFrenchRanks);
  if(s == "It") return CardContainer();
  if(s == "Uno") return CardContainer();
  throw s + " is not a type of card";
}
