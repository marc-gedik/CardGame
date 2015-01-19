#include "HuitAmericain.hpp"

#include "Action.hpp"
#include "exception/IllegalMovement.hpp"
#include "exception/IllegalNumberOfPlayer.hpp"
#include <iostream>
#include <cstdlib>
using namespace std;

void HuitAmericain::checkNumberOfPlayers(int nbPlayer){
  if(nbPlayer <2 || nbPlayer>5)
    throw IllegalNumberOfPlayer();
}

int HuitAmericain::cardsPerPlayer(int nbPlayer){
  return 8;
}

bool HuitAmericain::isFinished(){
  for(int i = 0; i < players.getNbPlayers(); i++){
    if(players.emptyHand(i))
      return true;
  }
  return false;
}

void HuitAmericain::printHeader(){ 
  cout << "-- Huit Amercain --" << endl;
}

void HuitAmericain::initPlayersHand(){
  int n = players.getNbPlayers();
  int cPP = cardsPerPlayer(n);

  for(int j = 0; j < cPP; j++)
    for(int i = 0; i < n; i++){
      Card& card = deck->deal();
      players.addTo(i, card);
    }
  pioche= new Pioche(deck->removeAll());
  discardPiles->add(pioche->draw());
}




void HuitAmericain::play(){
  
}


