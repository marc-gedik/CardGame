#include "Uno.hpp"

#include "Action.hpp"
#include "exception/IllegalMovement.hpp"
#include "exception/IllegalNumberOfPlayer.hpp"

#include "UnoCard.hpp"

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

void Uno::theWinnerIs(){
  for(int i = 0; i < players.getNbPlayers(); i++)
    if(players.emptyHand(i))
      cout << "The winner is " << i << endl;
}

void Uno::printHeader(){
  cout << "------------- Uno --------------" << endl;
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
  colorOfPile = (discardPiles->look()).getSuit();
}

bool Uno::isWhat(int n){
  return discardPiles->look().getRank() == n;
}

bool Uno::isPlusTwo   (){ return isWhat(uno::PlusTwo);    }
bool Uno::isReverse   (){ return isWhat(uno::Reverse);    }
bool Uno::isSkip      (){ return isWhat(uno::Skip); 	  }
bool Uno::isJoker     (){ return isWhat(uno::Joker);      }
bool Uno::isSuperJoker(){ return isWhat(uno::SuperJoker); }

void Uno::testSameRankOrColor(){
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

void Uno::play(){
  //  std::system("clear");
  printHeader();
  cout<<"\nTable : "<<*discardPiles<<endl;

  if(isReverse()){
    players.reverseOrder();
    players.next();
  }
  else if(isPlusTwo()){
    cout << "Vous piocher 2 fois" << endl;
    players.add(pioche->draw());
    players.add(pioche->draw());
    players.next();
  }
  else if(isSkip()){
    players.next();
  }
  else if(isSuperJoker()){
    cout << "Vous piocher 4 fois" << endl;
    players.add(pioche->draw());
    players.add(pioche->draw());
    players.add(pioche->draw());
    players.add(pioche->draw());
    players.next();
  }
  testSameRankOrColor();
}
