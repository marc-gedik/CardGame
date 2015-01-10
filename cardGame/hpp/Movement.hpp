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
  static const int M_ONE = 1, M_INTERVAL = 2, M_LIST = 4;
  Movement() {}
  Movement(string, int = ((M_ONE | M_INTERVAL) | M_LIST));

  int operator[](int);
  int getSize();
  int getMax();
  int getMin();
};

#endif
