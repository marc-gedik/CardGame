#ifndef H_UNO
#define H_UNO

#include "Game.hpp"

class Bataille : public Game {
private:
  virtual void checkNumberOfPlayers(int);
  virtual int cardsPerPlayer(int);
  virtual void initPlayersHand() ;
  virtual bool isFinished();

  virtual void printHeader();
  virtual void play();

  void play(int);
  void giveAllTo(int);
  void first();
  void checkBataille();

public:
  Bataille(int nbPlayers){
    initGame("Fr", nbPlayers, 1, nbPlayers);
    initPlayersHand();
  }
};

#endif
