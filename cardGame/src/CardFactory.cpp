#include "CardFactory.hpp"

#include "FrenchCard.hpp"
#include "ItalianCard.hpp"
#include "UnoCard.hpp"

template <typename Suit, typename Rank>
CardContainer CardFactory::createCards(Suit* suits, int nSuits, Rank* ranks, int nRanks){
  int n = nSuits * nRanks;
  Card** cards = new Card * [n];

  for(int i = 0; i < nSuits; i++)
    for(int j = 0; j < nRanks; j++)
      cards[i*nRanks + j] = new SimpleCard<Suit, Rank>(suits[i], ranks[j]);

  return CardContainer(cards, n);
}

template <typename Suit, typename Rank>
CardContainer CardFactory::createUnoCards(Suit* suits, int nSuits, Rank* ranks, int nRanks){
  int indice = 0;
  int nbCard = 108;
  Card** cards = new Card * [nbCard];
  for(int i = 0; i < nSuits-1; i++)
    cards[indice++] = new SimpleCard<Suit, Rank>(suits[i], uno::Zero);


  for(int i = 1; i < nRanks-2; i++){
    for(int j = 0; j < nSuits-1; j++){
      cards[indice++] = new SimpleCard<Suit, Rank>(suits[j], ranks[i]);
      cards[indice++] = new SimpleCard<Suit, Rank>(suits[j], ranks[i]);
    }
  }

  for(int i = 0; i < 4; i++){
    cards[indice++] = new SimpleCard<Suit, Rank>(uno::NoColor, uno::Joker);
    cards[indice++] = new SimpleCard<Suit, Rank>(uno::NoColor, uno::SuperJoker);
  }

  return CardContainer(cards, nbCard);
}

CardContainer CardFactory::createCards(string s){
  if(s == "Fr") return createCards(frenchSuits, nFrenchSuits, frenchRanks, nFrenchRanks);
  if(s == "It") return createCards(italianSuits, nItalianSuits, italianRanks, nItalianRanks);
  if(s == "Uno") return createUnoCards(unoSuits, nUnoSuits, unoRanks, nUnoRanks);
  throw s + " is not a type of card";
}
