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
  for(int i = 0; i < players.getNbPlayers(); i++){
    if(players.emptyHand(i))
      return true;
  }
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
  pioche= new Pioche(deck->removeAll());
  cout<<"dicard Pile : "<<*discardPiles<<endl;
  discardPiles->add(pioche->draw());
}





void Uno::play(){
  cout<<"first tour"<<endl;
  cout<<"dicard Pile : "<<*discardPiles<<endl;

  Action a;
  a.setTo(*discardPiles, CardContainer());
  players.ask(a,Movement::M_PIOCHE | Movement::M_ONE);
  cout<<"dicard Pile : "<<*discardPiles<<endl;
  if(a.isPioche()){
    cout<<"j'ai piocher"<<endl;
    players.add(pioche->draw());
    players.next();
  }
  else{
    cout<<"je choisi une carte"<<endl;
    a.apply();
  
    players.next();
  }  
}


