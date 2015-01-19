#ifndef H_ILLEGAL_OF_PLAYER
#define H_ILLEGAL_OF_PLAYER

#include <iostream>
#include <sstream>

class IllegalNumberOfPlayer : public std::exception {
private:
  std::string msg;
public:
  IllegalNumberOfPlayer() { msg = "Nombre de joueur invalide"; }
  IllegalNumberOfPlayer(string s) {
    msg = "Nombre de joueur invalide: " + s;
  }

  ~IllegalNumberOfPlayer() throw() { }
  virtual const char * what() const throw(){
    return msg.c_str();
  }
};
#endif
