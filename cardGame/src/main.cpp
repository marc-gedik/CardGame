#include <iostream>
#include <string>
#include "main.hpp"
using namespace std;

#include "Bataille.hpp"
#include "IllegalEntry.hpp"

int main(){
  cout << " -- Card Game -- " << endl;

<<<<<<< HEAD
  // Bataille b(2);
  //b.run();
  //  return 0;

  main::testEntry("1, 12, 333");
}


void main::testEntry(string flux){
  
   delimitWith(flux, ",");
   //delimitWith(flux, ",");

  // std::cout << flux << "  merde  "<<std::endl;
}



int* main::delimitWith(string flux, string delimiter){
  int *tab = new int[flux.length()]; //on suppose la taille suffisante
  size_t pos1 = 0;
  size_t pos2 = 0;
  std::string::size_type st;   
  int i =0;
  std::string split;
  while ((pos1 = flux.find(delimiter)) != std::string::npos) {
    split = flux.substr(0, pos1);
    
    tab[i]= stoi(split,&st);
    std::cout << "affiche "<<tab[i] << std::endl;
    throw IllegalEntry("The enntry is illegal");

    pos2=pos1 + delimiter.length();
    flux= flux.substr(pos2);
    i++;
  }
  tab[i+1]= stoi(split,&st);
  return tab;
=======
  Bataille b(2);
  b.run();

  return 0;
>>>>>>> 168b2ccb4172751dccc9b2e162ea8044d70e42aa
}
