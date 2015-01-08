#include "Melange.hpp"

#include <cstdlib>
#include <ctime>


void fusion(Card** tab, Card** tab1, int size1, Card** tab2, int size2){
  int i, i1, i2;
  for(i = 0, i1 = 0, i2 = 0; i1 < size1;)
    tab[i++] = tab1[i1++], tab[i++] = tab2[i2++];
  for(; i2 < size2;)
    tab[i++] = tab2[i2++];
}

void melangePharaon(Card** tab, int size, int n){
  srand(time(0));
  int decallage = size/4;
  int middle;
  for(int j =0; j < n; j++){
    middle = rand()%decallage + (size/2-decallage/2);
    int size1 = middle;
    Card** tab1 = new Card*[size1];
    int size2 = size-middle;
    Card** tab2 = new Card*[size2];

    for(int i =0; i < size1; i++)
      tab1[i] = tab[i];
    for(int i =0; i < size2; i++)
      tab2[i] = tab[i+size1];

    if(size1 < size2)
      fusion(tab, tab1, size1, tab2, size2);
    else
      fusion(tab, tab2, size2,  tab1, size1);
    delete [] tab1;
    delete [] tab2;
  }
}
