#ifndef H_BRISCOLA
#define H_BRISCOLA

#include "Game.hpp"
#include "SameOrTrumpSettings.hpp"
#include "ScoreSettings.hpp"
#include "ItalianCard.hpp"

class Briscola : public Game {
private:
  virtual void checkNumberOfPlayers(int);
  virtual int cardsPerPlayer(int);
  virtual void initPlayersHand() ;
  virtual bool isFinished();
  virtual void theWinnerIs();

  virtual void printHeader();

  ScoreSettings scores;
  void initScores();

  void deal();
  void oneAction();
  void initSettings();
  virtual void play();

  SameOrTrumpSettings settings;
  Card *last;
public:
  Briscola(int nbPlayers, bool ia){
    int nbDiscardPile = nbPlayers;
    initGame("It", nbPlayers, 1, nbDiscardPile, ia);
    initSettings();
  }
};

#endif
