#include "Uno.hpp"

#include "Action.hpp"
#include "exception/IllegalMovement.hpp"
#include "exception/IllegalNumberOfPlayer.hpp"

#include <iostream>
using namespace std;

void Uno::checkNumberOfPlayers(int nbPlayer){
  if(nbPlayer <2 || nbPlayer>7)
    throw IllegalNumberOfPlayer();
}

int Uno::cardsPerPlayer(int nbPlayer){
  return 7;
}

bool Uno::isFinished(){
  for(int i = 0; i < players.getNbPlayers(); i++)
    if(players.emptyHand(i))
      return true;
  return false;
}

void Uno::printHeader(){
  cout << "-- Uno --" << endl;
}

void Uno::initPlayersHand(){
  int n = players.getNbPlayers();
  int cPP = cardsPerPlayer(n);

  for(int j = 0; j < cPP; j++)
    for(int i = 0; i < n; i++){
      Card& card = deck->deal();
      players.addTo(i, card);
    }
}

void Uno::first(){
  Action action;
  action.setTo(discardPiles[players.getActualPlayerId()], CardContainer());
  players.ask(action, Movement::M_ONE);

  try{
    action.countMovingCards(1);
    action.movingCardsFromTop();
    action.apply();
  }
  catch(IllegalMovement e){
    cout << e.what() << endl;
    first();
  }
}


void Uno::giveAllTo(int k){
  for(int i = 0; i < players.getNbPlayers(); i++)
    players.addTo(k, discardPiles[i].removeAll());
}

void Uno::play(int n){
  players.setActualPlayer(0);

  do{
    for(int i = 0; i < n; i++)
      first();
    players.next();
  }
  while (players.getActualPlayerId() != 0);

  for(int i = 0; i < players.getNbPlayers(); i++){
    cout << discardPiles[i];
    if(i+1 < players.getNbPlayers())
      cout << " vs ";
  }
  cout << endl;
  //checkUno();
}

void Uno::play(){
  play(1);
}
