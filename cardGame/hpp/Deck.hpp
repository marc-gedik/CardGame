#ifndef H_DECK
#define H_DECK

template <typename T>
class Deck {
protected:
  T** cards;
  int nbCards;
public:
  Deck(int nbrDecks);
  ~Deck() {
    for(int i = 0; i < nbCards; i++)
      delete cards[i];
    delete [] cards;
  }
  void shuffle(int);

};

#endif
