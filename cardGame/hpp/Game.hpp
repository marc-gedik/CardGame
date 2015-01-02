#ifndef H_GAME
#define H_GAME

#include "Deck.hpp"
#include "Players.hpp"
#include "DiscardPile.hpp"
#include "Action.hpp"

template<typename T>
class Game {
private:

protected:
  Players<T> players;
  DiscardPile<T> * discardPiles;
  Deck<T> deck;

  bool finished;

  virtual void initPlayersHand() = 0;
  virtual int cardsPerPlayer(int) = 0;
  virtual void checkNumberOfPlayers(int) = 0;

  virtual void printHeader() = 0;
  virtual void play() = 0;

  Game(int nbPlayer, int nbPaquet =1, int nbDiscardPiles =1)
    : players(nbPlayer), deck(nbPaquet)
  {
    discardPiles = new DiscardPile<T> [nbDiscardPiles];
  }

public:
  void run(){
    while(!finished)
      play();
  }
};

#endif
