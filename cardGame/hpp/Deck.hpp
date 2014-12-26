#ifndef H_DECK
#define H_DECK

template <typename T>
class Deck {
private:
  T* cards;
public:
  Deck(int nbrDecks);
  ~Deck();
};

#endif
