#ifndef H_MOVEMENT
#define H_MOVEMENT

#include <iostream>
using namespace std;

class Movement {
private:
  int * cardsPos;
  int nbCards;

  void isInt(string, unsigned int&);
  void match1(string);
  void match2(string, int);
  void match3(string, int);
public:
  Movement() {}
  Movement(string);

  int operator[](int);
  int getSize();
  int getMax();
  int getMin();
};

#endif
