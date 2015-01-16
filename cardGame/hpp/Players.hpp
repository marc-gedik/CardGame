#ifndef H_PLAYERS
#define H_PLAYERS

#include "Deck.hpp"
#include "Player.hpp"
#include "Action.hpp"

#include <iostream>
using namespace std;

class Players {
private:
  Player** players;
  int nbPlayers;
  int actual;
  int order;
public:
  Players() {}
  Players(int, bool humans = true, int ord = 1);
  Player& next();
  Player& getActualPlayer();

  void reverseOrder();

  int getNbPlayers();

  int getActualPlayerId();

  void setActualPlayer(int);

  void eliminer(int);

  void ask(Action&);

  void addTo(int, Card&);
  void addTo(int, const CardContainer&);

  bool emptyHand(int);

};

#endif
