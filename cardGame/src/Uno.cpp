#include "Uno.hpp"

#include "Action.hpp"
#include "exception/IllegalMovement.hpp"
#include "exception/IllegalNumberOfPlayer.hpp"

#include <iostream>
#include <cstdlib>
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
  discardPiles->add(pioche->draw());
}



void Uno::testSameRankOrColor(Action a){
   players.ask(a,Movement::M_PIOCHE | Movement::M_ONE,1);
    if(a.isPioche()){
      players.add(pioche->draw());
      players.next();
    }
    else{    
      if(a.sameRank() || a.sameColor()){
	a.apply();
      players.next();
      }
      else
	a.reset();
    }
  }


void Uno::play(){
  std::system("clear");
  cout<<"\nTable : "<<*discardPiles<<endl;
  Action a;
  a.setTo(*discardPiles, CardContainer());

  if(a.isReverse()){
    cout<<"vous passez votre tour.."<<endl;
    players.reverseOrder();
    players.next();
    testSameRankOrColor(a);

  }
  
  //si le sommet de la pile est +2: piocher 2fois
  else if(a.isPlusTwo()){
    players.ask(a,Movement::M_PIOCHE,2);
    players.add(pioche->draw());
    players.ask(a,Movement::M_PIOCHE,3);
    players.add(pioche->draw());
    players.next();
    testSameRankOrColor(a);

  }
  else if(a.isSkip()){
    players.next();
    testSameRankOrColor(a);
  }

  else if(a.isJoker()){
    players.next();
    testSameRankOrColor(a);	
   }

  else if(a.isSuperJoker()){
    players.ask(a,Movement::M_PIOCHE,2);
    players.add(pioche->draw());
    players.ask(a,Movement::M_PIOCHE,3);
    players.add(pioche->draw());

    players.ask(a,Movement::M_PIOCHE,3);
    players.add(pioche->draw());
    players.ask(a,Movement::M_PIOCHE,3);
    players.add(pioche->draw());
    players.next();
    testSameRankOrColor(a);
  }
  else{
    testSameRankOrColor(a);
   
  }
}


