#include "Movement.hpp"

#include "exception/IllegalEntry.hpp"

#include <iostream>
#include <string>
#include <cstdlib>
#include <algorithm>

using namespace std;

int Movement::getMax(){
  int maxPos = cardsPos[0];
  for(int i = 1; i < nbCards; i++)
    maxPos = max(maxPos, cardsPos[i]);
  return maxPos;
}

int Movement::getMin(){
  int minPos = cardsPos[0];
  for(int i = 1; i < nbCards; i++)
    minPos = min(minPos, cardsPos[i]);
  return minPos;
}

int Movement::operator[](int pos){
  return cardsPos[pos];
}

int Movement::getSize(){
  return nbCards;
}

bool Movement::isWhat(int what){
  return (type & what) == what;
}

bool Movement::isOne()	   { return isWhat(M_ONE);     }
bool Movement::isList()	   { return isWhat(M_LIST);    }
bool Movement::isInterval(){ return isWhat(M_INTERVAL);}
bool Movement::isPioche()  { return isWhat(M_PIOCHE);  }

void Movement::isInt(string s, unsigned int &i){
  unsigned int j = i;
  for(; i < s.length(); i++)
    if(s[i] < '0' || s[i] > '9')
      break;
  if(i==j)
    throw IllegalEntry();
}

void Movement::match1(string s){
  type = M_ONE;
  nbCards = 1;
  cardsPos = new int[nbCards];
  cardsPos[0] = atoi(s.c_str());
}

void Movement::match2(string s, int lim){
  type = M_INTERVAL;
  string sG = s.substr(0, lim);
  string sD = s.substr(lim+2);

  int x = atoi(sG.c_str());
  int y = atoi(sD.c_str());

  if(x > y){
    int tmp = x;
    x = y;
    y = tmp;
  }

  nbCards = y-x + 1;
  cardsPos = new int[nbCards];

  for(int i = 0; x <= y; x++, i++)
    cardsPos[i] = x;
}

void Movement::match3(string s, int n){
  type = M_LIST;
  nbCards = n;
  cardsPos = new int[nbCards];

  unsigned int i = 0, j = 0;
  isInt(s, i);
  cardsPos[0] = atoi(s.substr(j, i).c_str());
  for(int k = 1; k < n; k++){
    i++;
    j = i;
    isInt(s, i);
    cardsPos[k] = atoi(s.substr(j, i).c_str());
  }
}

void Movement::match4(){
  type = M_PIOCHE;
}

Movement::Movement(string s, int match){
  unsigned int i = 0;
  int n = 0;

  if((match & M_ONE) == M_ONE){
    try{
      i = 0;
      isInt(s, i);
      if(s.length() == i){
	match1(s);
	return;
      }
    }
    catch(IllegalEntry e) {}
  }

  if((match & M_INTERVAL) == M_INTERVAL){
    try{
      i = 0;
      isInt(s, i);
      if(i+2 < s.length()
	 && s[i] == '.' && s[i+1] == '.'){
	n = i;
	i += 2;
	isInt(s, i);
      }
    }catch(IllegalEntry e) {}

    if(s.length() == i){
      match2(s, n);
      return;
    }
    else
      throw IllegalEntry();
  }

  if((match & M_LIST) == M_LIST) {
    bool flag = true;
    try{
      i = 0;
      isInt(s, i);
      s.erase(remove(s.begin(), s.end(), ' '), s.end());

      while(i < s.length()){
	if(s[i++] != ',')
	  flag = false;
	isInt(s, i);
	n++;
      }
    }catch(IllegalEntry e) {}

    if(flag && s.length() == i){
      match3(s, n+1);
      return;
    }
    else
      throw IllegalEntry();
  }

  if((match & M_PIOCHE) == M_PIOCHE){
    if(s.compare("pioche") == 0){
      match4();
      return;
    }
  }
  throw IllegalEntry();

}
