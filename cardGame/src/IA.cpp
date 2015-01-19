#include "IA.hpp"

#include "Movement.hpp"
#include "exception/IllegalEntry.hpp"

void IA::ask(CardAction& action, int what, int request){
  Movement movement;
  string query;
  switch(request){
  case 0 :
    cout << "Choisir carte(s) " << endl;
    query = "0";
    break;
  case 1 :
    cout << "Choisir carte(s) ou piocher" << endl;
    if(cpt++ < hand.getSize())
      query = "0";
    else{
      cpt = 0;
      query = "pioche";
    }
    break;
  case 2 :
    cout << "Piocher 2 fois " << endl;
    query = "pioche";
    break;
  case 3 :
    cout << "Piocher encore une fois " << endl;
    query = "pioche";
    break;
  default:
    cout << "_" << endl;
  }
  cout << hand << endl;


  try{
    movement = Movement(query, what);
    action.setFrom(hand, movement);
  }catch(IllegalEntry e){
    cout << e.what() << endl;
    ask(action, what);
  }
}

void IA::ask(Question& question, int=0, int request){
  Movement movement;
  string query;

  question.print();

  query = "0";

  try{
    movement = Movement(query, Movement::M_ONE);
    question.repondre(movement);
  }catch(IllegalEntry e){
    cout << e.what() << endl;
    ask(question);
  }
}
