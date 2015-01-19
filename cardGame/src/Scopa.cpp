#include "Scopa.hpp"

#include "exception/IllegalMovement.hpp"
#include "exception/IllegalNumberOfPlayer.hpp"

void Scopa::checkNumberOfPlayers(int n){
  if(n < 2 || n > 4)
    throw IllegalNumberOfPlayer(">1 and <5");
}

int Scopa::cardsPerPlayer(int n){
  return 3;
}

void Scopa::deal(){
  int n = players.getNbPlayers();
  int cPP = cardsPerPlayer(n);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < cPP; j++){
      Card& card = deck->deal();
      players.addTo(i, card);
    }
}

void Scopa::initPlayersHand(){
  deal();

  for(int i = 0; i < 4; i ++){
    Card& card = deck->deal();
    discardPiles->add(card);
  }
}

bool Scopa::isFinished(){
  return deck->getSize() == 0;
}

void Scopa::printHeader(){
  cout << "-- Scopa --" << endl;
}

void Scopa::oneAction(){
  CardAction action;
  action.setTo(*discardPiles, CardContainer());
  players.ask(action, Movement::M_ONE);

  try{
    action.countMovingCards(1);
    CardContainer cards = action.getFromCards();
    if(discardPiles->contains(cards)){
      players.discardTo(discardPiles->remove(cards));
      players.discardTo(cards);
    }
    else
      action.apply();
  }
  catch(IllegalMovement e){
    cout << e.what() << endl;
    oneAction();
  }
}

void Scopa::play(){
  cout << "-- Debut de manche --" << endl;
  players.setActualPlayer(0);
  for(int i = 0; i < 3; i++)
    do{
      cout << "\nTable : " <<  *discardPiles << endl;
      oneAction();
      players.next();
    }
    while (players.getActualPlayerId() != 0);
  deal();
}
