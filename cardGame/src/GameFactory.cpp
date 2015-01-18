#include "GameFactory.hpp"

const int GameFactory::nbChoice = 1;
const string GameFactory::choice[] = { "Bataille" };

Game* GameFactory::createGame(Movement game, Movement nbPlayer){
  switch(game[0]){
  case 1:
    return new Bataille(nbPlayer[0]);
  case 2:
    return new Uno(nbPlayer[0]);
  default:
    throw;
  }
}

ostream& operator<<(ostream& os, GameFactory& gF){
  for(int i = 0; i < gF.nbChoice; i++)
    os << " " <<(i+1) << ". " << gF.choice[i] << endl;
  return os;
}
