#ifndef H_UNO
#define H_UNO

#include "GameWithPioche.hpp"

class Uno : public GameWithPioche {
private:
  int colorOfPile;
  virtual void checkNumberOfPlayers(int);
  virtual int cardsPerPlayer(int);
  virtual void initPlayersHand() ;
  virtual bool isFinished();
  void testSameRankOrColor();
  virtual void printHeader();
  virtual void play();

  bool isWhat(int);
  bool isPlusTwo();
  bool isSkip();
  bool isReverse();
  bool isJoker();
  bool isSuperJoker();

public:
  Uno(int nbPlayers){
    int nbDiscardPile=1;
    int nbDeck=1;
    initGame("Uno", nbPlayers, nbDeck, nbDiscardPile);
  }
};

#endif
