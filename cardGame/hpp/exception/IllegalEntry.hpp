#ifndef H_ILLEGAL_ENTRY
#define H_ILLEGAL_ENTRY

#include <iostream>

class IllegalEntry : public std::exception {
public:
  IllegalEntry() {}
  ~IllegalEntry() throw() { }
  virtual const char * what() const throw(){
    return "Entry : \n\tint\n\tint..int\n\tint, int, [...] int";
  }
};

#endif
