#ifndef H_GAME
#define H_GAME

#include "Deck.hpp"
#include "Players.hpp"
#include "DiscardPile.hpp"

#include <iostream>

class Game {
protected:
  DiscardPile* discardPiles;
  Players players;
  Deck* deck;

  virtual bool isFinished() = 0;
  virtual void initPlayersHand() = 0;
  virtual int cardsPerPlayer(int) = 0;
  virtual void checkNumberOfPlayers(int) = 0;

  virtual void printHeader() = 0;
  virtual void play() = 0;

  void createDeck(std::string, int);
  void initGame(std::string, int, int, int, bool);

public:
  void run();
};

#endif
