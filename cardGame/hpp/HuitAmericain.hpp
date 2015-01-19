#ifndef H_8AMERICAIN
#define H_8AMERICAIN

#include "GameWithPioche.hpp"

class HuitAmericain : public GameWithPioche {
private:
  int colorOfPile;
  virtual void checkNumberOfPlayers(int);
  virtual int cardsPerPlayer(int);
  virtual void initPlayersHand() ;
  virtual bool isFinished();
  virtual void printHeader();
  virtual void play();


public:
  HuitAmericain(int nbPlayers){
    cout<<"Jouons aux 8 Americain"<<endl;
    int nbDiscardPile=1;
    int nbDeck=1;
    initGame("Fr", nbPlayers, nbDeck, nbDiscardPile);
    cout <<"Jeu uno initialise"<<endl;

  }
};

#endif
