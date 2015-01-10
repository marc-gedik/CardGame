#include "GameFactory.hpp"

const int GameFactory::nbChoice = 1;
const string GameFactory::choice[] = { "Bataille" };

Game* GameFactory::createGame(Movement move){
  if(move.getSize() == 1)
    switch(move[0])
    case 1:
      return new Bataille(2);
  throw;
}

ostream& operator<<(ostream& os, GameFactory& gF){
  for(int i = 0; i < gF.nbChoice; i++)
    os << " " <<(i+1) << ". " << gF.choice[i] << endl;
  return os;
}
