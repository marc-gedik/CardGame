#ifndef H_BATAILLE
#define H_BATAILLE

#include "Game.hpp"
#include "FrenchCard.hpp"

class Bataille : public Game<FrenchCard> {
private:
  virtual void checkNumberOfPlayers(int);
  virtual int cardsPerPlayer(int);
  virtual void initPlayersHand() ;

  virtual void printHeader();
  virtual void play();

  void play(int);
  void giveAllTo(int);
  void first();
  void checkBataille();

public:
  Bataille(int nbPlayers) : Game<FrenchCard>(nbPlayers, 1, nbPlayers) {
        initPlayersHand();
  }
};

#endif
