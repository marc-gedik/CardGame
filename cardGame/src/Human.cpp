#include "Human.hpp"

#include "Movement.hpp"
#include "exception/IllegalEntry.hpp"

void Human::ask(CardAction& action, int what, int request){
  Movement movement;
  string query;
  switch(request){
  case 0 : cout << "Choisir carte(s) " << endl; break;
  case 1 : cout << "Choisir carte(s) ou piocher" << endl; break;
  case 2 : cout << "Piocher 2 fois " << endl;break;
  case 3 : cout << "Piocher encore une fois " << endl;break;
  default: cout << "_" << endl;
  }
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
void Human::ask(Question& question, int=0, int request){
  Movement movement;
  string query;

  question.print();

  cin >> query;

  try{
    movement = Movement(query, Movement::M_ONE);
    question.repondre(movement);
  }catch(IllegalEntry e){
    cout << e.what() << endl;
    ask(question);
  }

}
