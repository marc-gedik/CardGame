#include <iostream>
#include <string>
#include <cstring>
#include <regex>

#include "main.hpp"
using namespace std;

#include "Bataille.hpp"
#include "IllegalEntry.hpp"



void isInt(string s, int &i){
  int j = i;
  for(; i < s.length(); i++)
    if(s[i] < '0' || s[i] > '9')
      break;
  if(i==j)
    cout << "throw ()" << endl;
}

int * match1(string s){
  int * t = new int[2];
  t[0] = atoi(s.c_str());
  t[1] = -1;
}

int * match2(string s, int lim){
  string sG = s.substr(0, lim);
  string sD = s.substr(lim+2);

  int x = atoi(sG.c_str());
  int y = atoi(sD.c_str());

  if(x > y)
    cout << "throw()";
  int n = y-x + 1;
  int * t = new int[n+1];

  t[n] = -1;
  for(int i = 0; x <= y; x++, i++)
    t[i] = x;
}

int * match3(string s, int n){
  int * t = new int[n+1];
  t[n] = -1;
  int i = 0, j = 0;
  isInt(s, i);
  t[0] = atoi(s.substr(j, i).c_str());
  for(int k = 1; k < n; k++){
    i++;
    j = i;
    isInt(s, i);
    t[k] = atoi(s.substr(j, i).c_str());
  }
}

int * testEntry(string s){
  int n = 0;
  int i = 0;
  isInt(s, i);
  if(s.length() == i)
    return match1(s);

  else if(i+2 < s.length()
	  && s[i] == '.' && s[i+1] == '.'){
    n = i;
    i += 2;
    isInt(s, i);
    if(s.length() == i)
      return match2(s, n);
  }

  else {
    bool flag = true;

    remove(s.begin(), s.end(), ' ');
    int k = 0;
    for(; k < s.length() && s[k] != ' '; k++);
    s.resize(k);

    do{
      if(s[i++] != ',')
	flag = false;
      isInt(s, i);
      n++;
    } while(i < s.length());
    if(flag && s.length() == i)
      match3(s, n+1);
  }
}


int main(){
  cout << " -- Card Game -- " << endl;

  // Bataille b(2);
  //b.run();

  testEntry("1,5,   5 , 58 ,  9 ");

  return 0;
}
