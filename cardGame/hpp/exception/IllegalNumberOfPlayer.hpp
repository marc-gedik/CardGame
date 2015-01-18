#ifndef H_ILLEGAL_OF_PLAYER
#define H_ILLEGAL_OF_PLAYER

#include <iostream>

class IllegalNumberOfPlayer : public std::exception {
public:
  IllegalNumberOfPlayer() {}
  ~IllegalNumberOfPlayer() throw() { }
  virtual const char * what() const throw(){
    return "Nombre de joueur invalide";
  }
};
#endif
