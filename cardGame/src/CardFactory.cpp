#include "CardFactory.hpp"
#include "FrenchCard.hpp"
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
  int n = nSuits * nRanks;
  int indice =0;
  Card** cards = new Card * [108];

  //creation carte 0-9-+2-skip-reverse-skip pour charque couleur
  for(int i = 0; i < nSuits-1; i++){
    cards[indice] = new SimpleCard<Suit, Rank>(suits[i], ranks[0]);
    indice ++;
  }/*
  for(int i = 0; i < nRanks-2; i++){
    for(int j = 0; j < nSuits-1; j++){
      cards[indice] = new SimpleCard<Suit, Rank>(suits[j], ranks[i]);
      indice++;
      cards[indice] = new SimpleCard<Suit, Rank>(suits[j], ranks[i]);
      indice++;			    
    }
  }

  for(int i = 0; i < 4; i++){
    cards[indice] = new SimpleCard<Suit, Rank>(suits[5], ranks[nRanks]);
    indice ++;
    cards[indice] = new SimpleCard<Suit, Rank>(suits[5], ranks[nRanks-1]);
    indice ++;
    }*/
  return CardContainer(cards, 108);
}

CardContainer CardFactory::createCards(string s){
  if(s == "Fr") return createCards(frenchSuits, nFrenchSuits, frenchRanks, nFrenchRanks);
  if(s == "It") return CardContainer();
  if(s == "Uno") return createUnoCards(unoSuits, nUnoSuits, unoRanks, nUnoRanks);
  throw s + " is not a type of card";
}
