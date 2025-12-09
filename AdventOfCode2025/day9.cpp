#include <cmath>
#include <cstdlib>
#include <ios>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

class Solve {
public:
  // std::string Final = "";
  //
  // Solve(std::vector<std::string> &Object) {
  //   long long MaxArea = 0;
  //   std::vector<long long> x_values;
  //   std::vector<long long> y_values;
  //
  //   for (std::size_t i = 0; i < Object.size(); ++i) {
  //     const std::string &CurrentString = Object[i];
  //     auto FoundSplit = CurrentString.find(',');
  //     if (FoundSplit == std::string::npos)
  //       continue;
  //
  //     x_values.push_back(std::stoll(CurrentString.substr(0, FoundSplit)));
  //     y_values.push_back(std::stoll(CurrentString.substr(FoundSplit + 1)));
  //   }
  //
  //   const int PointCount = static_cast<int>(x_values.size());
  //   for (int AIndex = 0; AIndex < PointCount; ++AIndex) {
  //     for (int BIndex = AIndex + 1; BIndex < PointCount; ++BIndex) {
  //       long long Width = std::llabs(x_values[AIndex] - x_values[BIndex]) +
  //       1; long long Height = std::llabs(y_values[AIndex] - y_values[BIndex])
  //       + 1;
  //
  //       long long CurrentArea = Width * Height;
  //       if (CurrentArea > MaxArea) {
  //         MaxArea = CurrentArea;
  //       }
  //     }
  //   }
  //
  //   Final = std::to_string(MaxArea);
  // }
};
