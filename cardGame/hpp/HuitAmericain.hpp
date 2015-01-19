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


  void testSameRankOrColor();

  bool isWhat(int);
  bool isQueen();
  bool isSeven();
  bool isTen();
  bool isJack();
  bool isJoker();
  

public:
  HuitAmericain(int nbPlayers, bool ia){
    cout<<"Jouons aux 8 Americain"<<endl;
    int nbDiscardPile=1;
    int nbDeck=1;
    initGame("Fr", nbPlayers, nbDeck, nbDiscardPile, ia);
    cout <<"Jeu 8 Americain initialise"<<endl;
    
  }
};

#endif
