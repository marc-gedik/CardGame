#ifndef H_DECK
#define H_DECK

template <typename T>
class Deck {
protected:
  T* cards;
public:
  Deck(int nbrDecks);
  ~Deck() { delete [] cards; }
};

#endif
