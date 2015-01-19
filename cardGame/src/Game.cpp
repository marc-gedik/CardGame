#include "Game.hpp"

#include "DeckFactory.hpp"

using namespace std;

void Game::initGame(string deckType, int nbPlayer, int nbPaquet, int nbDiscardPiles, bool ia){
  DeckFactory deckFactory;

  checkNumberOfPlayers(nbPlayer);
  players = Players(nbPlayer, ia);
  discardPiles = new DiscardPile [nbDiscardPiles];
  deck = deckFactory.createDeck(deckType, nbPaquet);
  initPlayersHand();
}

void Game::run(){
  while(!isFinished())
    play();
}



