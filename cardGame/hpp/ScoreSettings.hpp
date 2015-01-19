#ifndef H_SCORE_SETTINGS
#define H_SCORE_SETTINGS

#include <iostream>
#include <map>

class ScoreSettings {
private:
  std::map<int, int> score;

public:
  int  getScore(int);
  void setScore(int, int);

};

#endif
