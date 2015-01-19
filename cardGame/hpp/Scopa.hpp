#ifndef H_SCOPA
#define H_SCOPA

#include "Game.hpp"
#include "ScoreSettings.hpp"

class Scopa : public Game {
private:
  virtual void checkNumberOfPlayers(int);
  virtual int cardsPerPlayer(int);
  virtual void initPlayersHand() ;
  virtual bool isFinished();
  virtual void theWinnerIs();
  virtual void printHeader();
  virtual void play();

  ScoreSettings scores;
  void initScores();

  void deal();
  void oneAction();


public:
  Scopa(int nbPlayers, bool ia){
    initGame("It", nbPlayers, 1, 1, ia);
  }
};

#endif
