#include <iostream>
#include <string>
#include <regex>

#include "main.hpp"
using namespace std;

#include "Bataille.hpp"
#include "IllegalEntry.hpp"

int main(){
  cout << " -- Card Game -- " << endl;

	    // Bataille b(2);
	    //b.run();
	    //  return 0;

	    main::testEntry("11, 5, 3");
}


void main::testEntry(string flux){

  regex e1 ("^([1-9]{1}|^1[0-3]{1})[.][.]([1-9]{1}|1[0-3]{1})$");
  regex e2 ("^(([1-9]{1}|1[0-3]{1})[,][ ])+([1-9]{1}|1[0-3]{1})$");
  int *tab = new int[512];

  if (std::regex_match (flux,e1)){
    tab= main::delimitWith(flux,"..");
    cout<< tab[0] <<"--"<<tab[1];
  }
  else if(std::regex_match (flux,e2)){
   tab= main::delimitWith(flux,", ");

  }
  else
  std::cout << "Invalid entry "<<endl;

}



int *  main::delimitWith(string flux, string delimiter){
  int *tab = new int[512];
  int i=0;
  char *input= (char*)flux.c_str();
  char *delimit = (char*)delimiter.c_str();
  char *token = strtok(input,delimit);
  string::size_type st;   
  
  while (token != NULL) {
    std::cout << token << '\n';
    tab[i]= stoi(token,&st);
    token = strtok(NULL, delimit);
    i++;
  }
  tab[i]=-1;
  return tab;
}



