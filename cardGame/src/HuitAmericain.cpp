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
  cout << "-------------- Huit Americain --------------" << endl;
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


bool HuitAmericain::isWhat(int n){
  return discardPiles->look().getRank() == n;
}


bool HuitAmericain::isJoker (){
  return isWhat(8);
}


void HuitAmericain::testSameRankOrColor(){
  CardAction a;
  a.setTo(*discardPiles, CardContainer());

  players.ask(a, Movement::M_PIOCHE | Movement::M_ONE,1);
  string query;
  if(a.isPioche()){
    players.add(pioche->draw());
    players.next();
  }
  else{
    if(a.sameColor(4)){
      Question question("Choisir une couleur: \n0.Blue\n1.Green\n2.Yellow\n3.Red");
      players.ask(question, 0);
      if(question.getReponse()>=0 && question.getReponse()<=3)
	colorOfPile = question.getReponse();
      a.apply();
    }
    else if(a.sameRank() || a.sameColor(colorOfPile)){
      a.apply();

      colorOfPile=  (discardPiles->look()).getSuit();
      players.next();
    }
    else
      a.reset();
  }
}

void HuitAmericain::play(){
  printHeader();
   cout<<"\nTable : "<<*discardPiles<<endl;

 if(isJoker()){
    cout << "Vous piocher 5 fois" << endl;
    players.add(pioche->draw());
    players.add(pioche->draw());
    players.add(pioche->draw());
    players.add(pioche->draw());
    players.next();
    testSameRankOrColor();
      
  }
 else
  testSameRankOrColor();
}


