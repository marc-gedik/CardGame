#include "Briscola.hpp"

#include "exception/IllegalNumberOfPlayer.hpp"

void Briscola::checkNumberOfPlayers(int nbPlayer){
  if(nbPlayer < 2 || nbPlayer > 5)
    throw IllegalNumberOfPlayer();
}

int  Briscola::cardsPerPlayer(int){
  return 3;
}

void Briscola::initPlayersHand(){}

bool Briscola::isFinished(){
  
}

void Briscola::printHeader(){
  cout << "-- Briscola --" << endl;
}

void Briscola::play(){}
