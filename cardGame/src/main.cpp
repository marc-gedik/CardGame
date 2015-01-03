#include <iostream>
using namespace std;

#include "Bataille.hpp"

int main(){
  cout << " -- Card Game -- " << endl;

  Bataille b(2);
  b.run();

  return 0;
}
