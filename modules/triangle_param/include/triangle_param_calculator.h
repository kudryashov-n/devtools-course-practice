// Copyright 2020 Kudryashov Nikita

#ifndef MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_CALCULATOR_H_
#define MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_CALCULATOR_H_

#include <string>
#include <vector>
#include "../include/triangle_param.h"

class TriangleParamCalculator {
 private:
    // Return triangle, created from user string data.
    Triangle parseTriangleData(int argc, const char** argv);

    // Return array of user's requests.
    std::vector<std::string> parseRequests(int argc, const char** argv);
 public:
    std::string calculate(int argc, const char** argv);
    std::string help();
};

#endif  // MODULES_TRIANGLE_PARAM_INCLUDE_TRIANGLE_PARAM_CALCULATOR_H_