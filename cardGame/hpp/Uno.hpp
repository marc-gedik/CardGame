#ifndef H_UNO
#define H_UNO

#include "GameWithPioche.hpp"

class Uno : public Game {
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

public:
  Uno(int nbPlayers){
    int nbDiscardPile=1;
    cout<<"Jouons tous a UNO"<<endl;
    initGame("Uno", nbPlayers, 1, nbDiscardPile);
    initPlayersHand();
    cout <<"Jeu uno initialise"<<endl;

  }
};

#endif
