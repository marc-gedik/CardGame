#ifndef H_PLAYERS
#define H_PLAYERS

#include "Deck.hpp"
#include "Player.hpp"
#include "CardAction.hpp"
#include "Question.hpp"

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

  void ask(CardAction&, int, int request=0);
  void ask(Question&, int, int request=0);

  void addTo(int, Card&);
  void add(Card&);
  void addTo(int, const CardContainer&);

  void discardTo(int, CardContainer&);
  void discardTo(CardContainer);

  bool emptyHand(int);

};

#endif
