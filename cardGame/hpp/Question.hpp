#ifndef H_QUESTION
#define H_QUESTION

#include "Movement.hpp"
#include <iostream>

using namespace std;

class Question : public Action {
  Movement reponse;
  string question;

public:
  Question(string s) : question(s) {}

  void repondre(Movement movement){
    reponse = movement;
  }

  int getReponse(){
    return reponse[0];
  }

  void print(){ cout << question << endl; }
};

#endif
