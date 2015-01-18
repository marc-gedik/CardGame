#include "Game.hpp"

#include "DeckFactory.hpp"

using namespace std;

void Game::initGame(string deckType, int nbPlayer, int nbPaquet =1, int nbDiscardPiles =1){
  DeckFactory deckFactory;

  checkNumberOfPlayers(nbPlayer);
  players = Players(nbPlayer);
  discardPiles = new DiscardPile [nbDiscardPiles];
  deck = deckFactory.createDeck(deckType, nbPaquet);
  cout<< "deck cree"<<endl;
  initPlayersHand();
  cout<< "mains des joueurs creee"<<endl;
    
}

void Game::run(){
  while(!isFinished())
    play();
}



