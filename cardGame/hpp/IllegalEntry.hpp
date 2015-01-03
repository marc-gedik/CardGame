#ifndef H_ILLEGAL_ENTRY
#define H_ILLEGAL_ENTRY

#include <exception>
#include <iostream>

class IllegalEntry : public exception {
private:
  std::string msg;
public:
  IllegalEntry(){
    msg = "Illegal Movement";
  }

  IllegalEntry(const std::string s){
    msg = "Illegal Entry : " + s;
  }

  ~IllegalEntry() throw() { }

  virtual const char * what() const throw(){
    return msg.c_str();
  }

};


#endif
