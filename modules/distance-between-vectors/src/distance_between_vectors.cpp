// Copyright 2020 Vladislav Golubev

#include <vector>
#include <cmath>
#include "../include/distance_between_vectors.h"

Metrics::Metrics() : fst(std::vector<float>(1)),
                     sec(std::vector<float>(1)) {}

Metrics::Metrics(const std::vector<float>& _fst,
                 const std::vector<float>& _sec) {
  if (_fst.size() != _sec.size()) {
    throw "vectors of different dimensions";
  }
  fst = _fst;
  sec = _sec;
}

std::vector<float> Metrics::getFirst() {
  return fst;
}

std::vector<float> Metrics::getSecond() {
  return sec;
}

void Metrics::setFirst(const std::vector<float>& _fst) {
  if (fst.size() != _fst.size()) {
    throw "vectors of different dimensions";
  }
  fst = _fst;
}

void Metrics::setSecond(const std::vector<float>& _sec) {
  if (sec.size() != _sec.size()) {
    throw "vectors of different dimensions";
  }
  sec = _sec;
}

double Metrics::getL1() {
  double res = 0;
  for (std::size_t i = 0; i < fst.size(); ++i) {
    res += std::abs(fst[i] - sec[i]);
  }
  return res;
}

double Metrics::getL2() {
  double res = 0;
  for (std::size_t i = 0; i < fst.size(); ++i) {
    res += (fst[i] - sec[i]) * (fst[i] - sec[i]);
  }
  return std::sqrt(res);
}
