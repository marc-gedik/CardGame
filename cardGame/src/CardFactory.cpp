#include "CardFactory.hpp"
#include "FrenchCard.hpp"
#include "UnoCard.hpp"

template <typename Suit, typename Rank>
CardContainer CardFactory::createCards(Suit* suits, int nSuits, Rank* ranks, int nRanks){
  int n = nSuits * nRanks;
  Card** cards = new Card * [n];

  for(int i = 0; i < nSuits; i++)
    for(int j = 0; j < nRanks; j++){
      cards[i*nRanks + j] = new SimpleCard<Suit, Rank>(suits[i], ranks[j]);
      cout<< *cards[i*nRanks + j]<<endl;
    }
  return CardContainer(cards, n);
}

template <typename Suit, typename Rank>
CardContainer CardFactory::createUnoCards(Suit* suits, int nSuits, Rank* ranks, int nRanks){
  int indice =0;
  int nbCard = 108;
  Card** cards = new Card * [nbCard];
  for(int i = 0; i < nSuits-1; i++){
    cards[indice] = new SimpleCard<Suit, Rank>(suits[i], uno::Zero);
    indice ++;
  }

  for(int i = 1; i < nRanks-2; i++){
    for(int j = 0; j < nSuits-1; j++){
      cout <<"facto "<<ranks[i]<<endl;
      cards[indice] = new SimpleCard<Suit, Rank>(suits[j], ranks[i]);
      indice++;
      cards[indice] = new SimpleCard<Suit, Rank>(suits[j], ranks[i]);
      indice++;
    }
  }

  for(int i = 0; i < 4; i++){
    cards[indice] = new SimpleCard<Suit, Rank>(uno::NoColor, uno::Joker);
    indice ++;
    cards[indice] = new SimpleCard<Suit, Rank>(uno::NoColor, uno::SuperJoker);
    indice ++;
  }
  /*
  for(int i = 0; i < 108; i++){
    cout << *cards[i]<<endl ;
    }*/

 
  return CardContainer(cards, nbCard);
}

CardContainer CardFactory::createCards(string s){
  if(s == "Fr") return createCards(frenchSuits, nFrenchSuits, frenchRanks, nFrenchRanks);
  if(s == "It") return CardContainer();
  if(s == "Uno") return createUnoCards(unoSuits, nUnoSuits, unoRanks, nUnoRanks);
  throw s + " is not a type of card";
}
