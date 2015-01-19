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

void Briscola::theWinnerIs(){
  //TODO
}

void Briscola::initScores(){
  scores.setScore(it::Seven  , 0);
  scores.setScore(it::Six    , 0);
  scores.setScore(it::Five   , 0);
  scores.setScore(it::Four   , 0);
  scores.setScore(it::Three  , 10);
  scores.setScore(it::Deuce  , 0);
  scores.setScore(it::Re     , 4);
  scores.setScore(it::Cavallo, 3);
  scores.setScore(it::Fante  , 2);
  scores.setScore(it::Ace    , 11);
}

void Briscola::initSettings(){
  settings.setValue(it::Deuce  ,1);
  settings.setValue(it::Four   ,2);
  settings.setValue(it::Five   ,3);
  settings.setValue(it::Six    ,4);
  settings.setValue(it::Seven  ,5);
  settings.setValue(it::Fante  ,6);
  settings.setValue(it::Cavallo,7);
  settings.setValue(it::Re     ,8);
  settings.setValue(it::Three  ,9);
  settings.setValue(it::Ace    ,11);
}

void Briscola::deal(){
  int n = players.getNbPlayers();
  int cPP = cardsPerPlayer(n);
  int i;
  for(i = 0; i < n; i++)
    for(int j = 0; j < cPP; j++){
      if(deck->getSize() != 0){
   	Card& card = deck->deal();
	players.addTo(i, card);
      }
    }
  if(deck->getSize() == 0)
    players.addTo(i, *last);
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
  CardAction action;
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

  int iBest = players.getActualPlayerId();

  for(int i = 0; i < 3; i++){
    cout << "Atout : " << *last << endl;
    do{
      oneAction();
      players.next();
    }
    while (players.getActualPlayerId() != iBest);
    cout << "\nTable : " <<  *discardPiles << endl;
    CardContainer cards = discardPiles->removeAll();
    iBest = 0;
    Card& best = cards.getElement(cards.getSize() -1);
    for(int i = 0; i < cards.getSize() -1; i++)
      if(best.compare(cards.getElement(i), settings)<0){
	best = cards.getElement(i);
	iBest = i;
      }
    players.discardTo(iBest, cards);
    players.setActualPlayer(iBest);

    cout << "Best : " << best << endl;
  }

  deal();
}
