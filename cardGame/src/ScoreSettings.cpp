#include "ScoreSettings.hpp"

void ScoreSettings::setScore(int rank, int value){
  score[rank] = value;
}

int ScoreSettings::getScore(int rank){
  return score.at(rank);
}
