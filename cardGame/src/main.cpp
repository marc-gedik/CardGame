#include <iostream>
using namespace std;

#include "main.hpp"

#include "GameFactory.hpp"

#include "Deck.hpp"
#include "DeckFactory.hpp"
#include "CardFactory.hpp"
int main(){
  GameFactory gameFactory;

  cout << "\x1b[2J\x1b[1;1H";
  cout << "---------------" << endl;
  cout << "-- Card Game --" << endl;
  cout << "---------------" << endl;
  /*
  cout << gameFactory << endl;

  string query;

  cout << "Choice : ";
  cin >> query;
  Movement m1(query, Movement::M_ONE);

  cout << "Number of player : ";
  cin >> query;
  Movement m2(query, Movement::M_ONE);

  gameFactory.createGame(m1, m2)->run();
  */
 cout << "---------------" << endl;
  cout << "-- test UNO CARD --" << endl;
  cout << "---------------" << endl;

  //DeckFactory d;
  //d.createDeck("uno", 108);
  
  CardFactory c;
  c.createCards("uno");

  
  return 0;
}
