#include <cstdlib>
#include <iostream>
#include <ctime>


#include "Deck.hpp"

#include "SimpleCard.hpp"
#include "FrenchCard.hpp"

using namespace std;

template <typename Suit, typename Rank>
SimpleCard<Suit, Rank>**  init(int nbrDeck, Suit* suits, int nbrSuit, Rank* ranks, int nbrRank){
  int n = nbrDeck * nbrFrenchSuit * nbrFrenchRank;
  SimpleCard<Suit, Rank>** cards = new SimpleCard<Suit, Rank> * [n];

  for(int i = 0; i < nbrDeck; i++){
    for(int j = 0; j < nbrSuit; j++){
      for(int k = 0; k < nbrRank; k++){
	int nCard = (i + j * nbrDeck) * nbrRank + k;
	cards[nCard] = new SimpleCard<Suit, Rank>(suits[j], ranks[k]);
      }
    }
  }
  return cards;
}

template <>
Deck<FrenchCard >::Deck(int nbrDeck){
  nbCards = nbrDeck * nbrFrenchSuit * nbrFrenchRank;
  cards = init(nbrDeck, frenchSuits, nbrFrenchSuit, frenchRanks, nbrFrenchRank);
  shuffle(nbCards);
}

template <typename T>
void Deck<T>::shuffle(int size){

  melangePharaon(cards, size, 10);
  for(int i = 0; i < size; i++)
    cout << *(cards[i]) << "-";


}

template <typename T>
void melangePharaon(T** tab, int size, int n){
  srand(time(0));
  int decallage = size/4;
  int middle;
  for(int j =0; j < n; j++){
    middle = rand()%decallage + (size/2-decallage/2);
    int size1 = middle;
    T** tab1 = new T *[size1];
    int size2 = size-middle;
    T** tab2 = new T *[size2];

    for(int i =0; i < size1; i++)
      tab1[i] = tab[i];
    for(int i =0; i < size2; i++)
      tab2[i] = tab[i+size1];

    if(size1 < size2)
      fusion(tab, tab1, size1, tab2, size2);
    else
      fusion(tab, tab2, size2,  tab1, size1);
    delete [] tab1;
    delete [] tab2;
  }
}

template <typename T>
void fusion(T** tab, T** tab1, int size1, T** tab2, int size2){
  int i, i1, i2;
  for(i = 0, i1 = 0, i2 = 0; i1 < size1;)
    tab[i++] = tab1[i1++], tab[i++] = tab2[i2++];
  for(; i2 < size2;)
    tab[i++] = tab2[i2++];
}
