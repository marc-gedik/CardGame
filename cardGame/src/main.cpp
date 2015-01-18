#include <iostream>
using namespace std;

#include "main.hpp"

#include "GameFactory.hpp"

#include "Deck.hpp"
#include "DeckFactory.hpp"
#include "CardFactory.hpp"
int main(){

  cout << "\x1b[2J\x1b[1;1H";
  cout << "---------------" << endl;
  cout << "-- Card Game --" << endl;
  cout << "---------------" << endl;
  
  /*
  string query;

  cout << "Choice : ";
  cin >> query;
  Movement m1(query, Movement::M_ONE);

  cout << "Number of player : ";
  cin >> query;
  Movement m2(query, Movement::M_ONE);
  */

  cout << "gameFactory" << endl;
  GameFactory gameFactory;
  
  Movement m1("2",  Movement::M_ONE);
  Movement m2("2", Movement::M_ONE);
  gameFactory.createGame(m1, m2);


  return 0;
}
