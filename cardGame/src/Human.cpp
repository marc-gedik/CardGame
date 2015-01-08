#include "Human.hpp"

#include "Movement.hpp"
#include "exception/IllegalEntry.hpp"

// Todo Demander plusieurs cartes
void Human::ask(Action& action){
  Movement movement;
  string query;

  cout << "Quelle(s) carte(s) jouer ?" << endl;
  cout << hand << endl;

  cin >> query;

  try{
    movement = Movement(query);
  }catch(IllegalEntry e){
    cout << e.what() << endl;
    ask(action);
  }
}
