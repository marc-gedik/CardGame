#include "Bataille.hpp"
#include "Action.hpp"
#include "IllegalMovement.hpp"

#include <iostream>
using namespace std;

void Bataille::checkNumberOfPlayers(int nbPlayer){
  if(nbPlayer < 2)
    //throw IllegalNumberOfPlayers(nbPlayer, ">2");
    throw 444;
}

int Bataille::cardsPerPlayer(int nbPlayer){
  return deck.getSize()/nbPlayer;
}

void Bataille::printHeader(){
  cout << "-- Bataille --" << endl;
}

void Bataille::initPlayersHand(){
    int n = players.getNbPlayers();
    int cPP = cardsPerPlayer(n);

    for(int j = 0; j < cPP; j++)
      for(int i = 0; i < n; i++){
	players.addCard(i, deck.pop());
      }
}

void Bataille::play(){
  Action<FrenchCard> action;
  action.setTo(&discardPiles[players.getActualPlayerId()], CardContainer<FrenchCard>());
  players.ask(action);
  try{
    action.countMovingCards(1);
  }
  catch(IllegalMovement e){
    e.what();
    play();
  }
  action.apply();
  discardPiles[players.getActualPlayerId()].print();

}
