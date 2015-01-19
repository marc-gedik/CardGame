#ifndef H_BATAILLE
#define H_BATAILLE

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
  Bataille(int nbPlayers, bool ia){
    initGame("Fr", nbPlayers, 1, nbPlayers, ia);
  }
};

#endif
