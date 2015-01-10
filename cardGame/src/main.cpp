#include <iostream>
using namespace std;

#include "main.hpp"

#include "GameFactory.hpp"

#include "Deck.hpp"
#include "DeckFactory.hpp"

int main(){
  GameFactory gameFactory;

  cout << "\x1b[2J\x1b[1;1H";
  cout << "---------------" << endl;
  cout << "-- Card Game --" << endl;
  cout << "---------------" << endl;

  cout << gameFactory << endl;

  DeckFactory dF;

  Deck d = dF.createDeck("Fr", 1);
  cout << d.deal() << endl;

  string query;

  cout << "Choice : ";
  cin >> query;
  Movement m(query);
  gameFactory.createGame(m);
  return 0;
}
