#ifndef H_BRISCOLA
#define H_BRISCOLA

#include "Game.hpp"
#include "SameOrTrumpSettings.hpp"
#include "ItalianCard.hpp"

class Briscola : public Game {
private:
  virtual void checkNumberOfPlayers(int);
  virtual int cardsPerPlayer(int);
  virtual void initPlayersHand() ;
  virtual bool isFinished();


  virtual void printHeader();
  void deal();
  void oneAction();
  void initSettings();
  virtual void play();

  SameOrTrumpSettings settings;
  Card *last;
public:
  Briscola(int nbPlayers){
    int nbDiscardPile = nbPlayers;
    initGame("It", nbPlayers, 1, nbDiscardPile);
    initSettings();
  }
};

#endif
