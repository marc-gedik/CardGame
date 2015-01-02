#ifndef H_PLAYERS
#define H_PLAYERS

#include "Deck.hpp"
#include "Player.hpp"
#include "Action.hpp"

template <typename T>
class Players {
private:
  Player<T>* players;
  int nbPlayers;
  int actual;
  int order;
public:
  Players(int n, int ord = 1)
    : nbPlayers(n), actual(0), order(ord){
    players = new Player<T>[n];
  }

  Player<T>& next(){
    actual = (actual + order) % nbPlayers;
    return players[actual];
  }

  Player<T>& getActualPlayer(){
    return players[actual];
  }

  void reverseOrder(){
    order = -order;
  }

  int getNbPlayers(){
    return nbPlayers;
  }

  int getActualPlayerId(){
    return actual;
  }

  void setActualPlayer(int i){
    if(i>=0 && i < nbPlayers)
      actual = i;
  }

  void eliminer(int player){
    nbPlayers--;
    //Todo enlever player à la position "player"
  }

  void ask(Action<T>& action){
    players[actual].ask(action);
  }

  void addCard(int i, T& card){
    players[i].add(card);
  }
};

#endif
