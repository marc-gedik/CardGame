#include "Game.hpp"

#include "DeckFactory.hpp"

using namespace std;

void Game::initGame(string deckType, int nbPlayer, int nbPaquet =1, int nbDiscardPiles =1){
  DeckFactory deckFactory;

  players = Players(nbPlayer);
  discardPiles = new DiscardPile [nbDiscardPiles];

  deck = deckFactory.createDeck(deckType, nbPaquet);
  initPlayersHand();
}

void Game::run(){
  while(!isFinished())
    play();
}



