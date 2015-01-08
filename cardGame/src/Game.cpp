#include "Game.hpp"

Game::Game(int nbPlayer, int nbPaquet =1, int nbDiscardPiles =1)
  : players(nbPlayer), deck(nbPaquet)
{
  discardPiles = new DiscardPile [nbDiscardPiles];
}

void Game::run(){
  while(!finished)
    play();
}



