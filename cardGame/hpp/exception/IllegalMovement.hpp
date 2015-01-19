#ifndef H_ILLEGAL_MOVEMENT
#define H_ILLEGAL_MOVEMENT

#include <iostream>

using namespace std;

class IllegalMovement : public exception {
private:
  string msg;
public:
  IllegalMovement(){
    msg = "Illegal Movement";
  }

  IllegalMovement(string s){
    msg = "Illegal Movement : " + s;
  }

  ~IllegalMovement() throw() { }

  virtual const char * what() const throw(){
    return msg.c_str();
  }

};


#endif
