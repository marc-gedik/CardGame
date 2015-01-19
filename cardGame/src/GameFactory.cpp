#include "GameFactory.hpp"

#include "Bataille.hpp"
#include "Uno.hpp"
#include "Scopa.hpp"
#include "Briscola.hpp"
#include "HuitAmericain.hpp"

const int GameFactory::nbChoice = 5;
const string GameFactory::choice[] = { "Bataille", "Uno", "Scopa", "Briscola", "8 Americain" };

Game* GameFactory::createGame(Movement game, Movement nbPlayer, Movement IA){
  int n = nbPlayer[0];
  bool ia = IA[0] == 1;
  switch(game[0]){
  case 1:
    return new Bataille(n, ia);
  case 2:
    return new Uno(n, ia);
  case 3:
    return new Scopa(n, ia);
  case 4:
    return new Briscola(n, ia);
  case 5:
    return new HuitAmericain(n, ia);
  default:
    throw;
  }
}

ostream& operator<<(ostream& os, GameFactory& gF){
  for(int i = 0; i < gF.nbChoice; i++)
    os << " " <<(i+1) << ". " << gF.choice[i] << endl;
  return os;
}
