#ifndef H_GAME
#define H_GAME

#include "Deck.hpp"
#include "Players.hpp"
#include "DiscardPile.hpp"

class Game {
protected:
  DiscardPile* discardPiles;
  Players players;
  Deck deck;

  bool finished;

  virtual void initPlayersHand() = 0;
  virtual int cardsPerPlayer(int) = 0;
  virtual void checkNumberOfPlayers(int) = 0;

  virtual void printHeader() = 0;
  virtual void play() = 0;

  Game(int, int, int);

public:
  void run();
};

#endif
