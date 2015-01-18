#include "GameFactory.hpp"

#include "Bataille.hpp"
#include "Scopa.hpp"

const int GameFactory::nbChoice = 3;
const string GameFactory::choice[] = { "Bataille", "Uno", "Scopa" };

Game* GameFactory::createGame(Movement game, Movement nbPlayer){
  int n = nbPlayer[0];
  switch(game[0]){
  case 1:
    return new Bataille(n);
  case 2:
    return new Uno(n);
  case 2:
    return new Scopa(n);
  default:
    throw;
  }
}

ostream& operator<<(ostream& os, GameFactory& gF){
  for(int i = 0; i < gF.nbChoice; i++)
    os << " " <<(i+1) << ". " << gF.choice[i] << endl;
  return os;
}
