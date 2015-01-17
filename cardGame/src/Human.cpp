#include "Human.hpp"

#include "Movement.hpp"
#include "exception/IllegalEntry.hpp"

void Human::ask(Action& action, int what){
  Movement movement;
  string query;

  cout << "Quelle(s) carte(s) jouer ?" << endl;
  cout << hand << endl;

  cin >> query;

  try{
    movement = Movement(query, what);
    action.setFrom(hand, movement);
  }catch(IllegalEntry e){
    cout << e.what() << endl;
    ask(action, what);
  }
}
