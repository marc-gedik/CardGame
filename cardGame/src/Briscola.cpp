#include "Briscola.hpp"

#include "exception/IllegalNumberOfPlayer.hpp"
#include "exception/IllegalMovement.hpp"

void Briscola::checkNumberOfPlayers(int nbPlayer){
  if(nbPlayer < 2 || nbPlayer > 5)
    throw IllegalNumberOfPlayer(">1 and <6");
}

int  Briscola::cardsPerPlayer(int){
  return 3;
}

void Briscola::deal(){
  int n = players.getNbPlayers();
  int cPP = cardsPerPlayer(n);

  for(int i = 0; i < n; i++)
    for(int j = 0; j < cPP; j++){
      Card& card = deck->deal();
      players.addTo(i, card);
    }
}

void Briscola::initPlayersHand(){
  deal();

  last = &deck->deal();
  settings.setTrump(last->getSuit());
}

bool Briscola::isFinished(){
  return deck->getSize() == 0;
}

void Briscola::printHeader(){
  cout << "-- Briscola --" << endl;
}

void Briscola::oneAction(){
  Action action;
  action.setTo(*discardPiles, CardContainer());
  players.ask(action, Movement::M_ONE);

  try{
    action.countMovingCards(1);
    action.apply();
  }
  catch(IllegalMovement e){
    cout << e.what() << endl;
    oneAction();
  }
}

void Briscola::play(){
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
