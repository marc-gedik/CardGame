#ifndef H_SCOPA
#define H_SCOPA

#include "Game.hpp"

class Scopa : public Game {
private:
  virtual void checkNumberOfPlayers(int);
  virtual int cardsPerPlayer(int);
  virtual void initPlayersHand() ;
  virtual bool isFinished();

  virtual void printHeader();
  virtual void play();

  void deal();
  void oneAction();


public:
  Scopa(int nbPlayers){
    initGame("It", nbPlayers, 1, 1);
  }
};

#endif
