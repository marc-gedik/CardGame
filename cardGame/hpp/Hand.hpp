#include <list>
using namespace std;

class Hand {

private:
  list<int> myHand ;

  
public:

  Hand();
  void addCard(int c);
  void addCards(int c[], int size);
  void removeCard(int position);
  void printHand();
};

