#ifndef H_BRISCOLA
#define H_BRISCOLA

#include "GameWithPioche.hpp"

class Briscola : Game {
private:
  virtual void checkNumberOfPlayers(int);
  virtual int cardsPerPlayer(int);
  virtual void initPlayersHand() ;
  virtual bool isFinished();

  virtual void printHeader();
  virtual void play();

public:
  Briscola(int nbPlayers){
    int nbDiscardPile = nbPlayers;
    initGame("It", nbPlayers, 1, nbDiscardPile);
  }
};

#endif
