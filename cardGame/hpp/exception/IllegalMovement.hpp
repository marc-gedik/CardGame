#ifndef H_ILLEGAL_MOVEMENT
#define H_ILLEGAL_MOVEMENT

#include <iostream>

class IllegalMovement : public std::exception {
private:
  std::string msg;
public:
  IllegalMovement(){
    msg = "Illegal Movement";
  }

  IllegalMovement(const std::string s){
    msg = "Illegal Movement : " + s;
  }

  ~IllegalMovement() throw() { }

  virtual const char * what() const throw(){
    return msg.c_str();
  }

};


#endif
