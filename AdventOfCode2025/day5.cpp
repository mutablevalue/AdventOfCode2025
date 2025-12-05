#include <algorithm>
#include <cstdint>
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

class Solve {
public:
  // std::string Final;
  // Solve(std::vector<std::string> &Object) {
  //   std::vector<std::string> LeftRanges;
  //   std::vector<std::string> RightRanges;
  //   std::vector<std::string> Lookup;
  //   long long sum = 0;
  //
  //   std::size_t split = 0;
  //   while (split < Object.size() && !Object[split].empty()) {
  //     ++split;
  //   }
  //
  //   for (std::size_t i = 0; i < split; ++i) {
  //     std::string CurrentString = Object[i];
  //     auto FoundRange = CurrentString.find('-');
  //     if (FoundRange != std::string::npos) {
  //       LeftRanges.push_back(CurrentString.substr(0, FoundRange));
  //       RightRanges.push_back(CurrentString.substr(FoundRange + 1));
  //     }
  //   }
  //   if (split + 1 < Object.size()) {
  //     Lookup.assign(Object.begin() + split + 1, Object.end());
  //   }
  //
  //   for (std::size_t LookupIndex = 0; LookupIndex < Lookup.size();
  //        ++LookupIndex) {
  //     if (Lookup[LookupIndex].empty())
  //       continue;
  //     long long CurrentLookup = std::stoll(Lookup[LookupIndex]);
  //     for (std::size_t CurrentRange = 0; CurrentRange < LeftRanges.size() &&
  //                                        CurrentRange < RightRanges.size();
  //          ++CurrentRange) {
  //
  //       long long RangeBegin = std::stoll(LeftRanges[CurrentRange]);
  //       long long RangeEnd = std::stoll(RightRanges[CurrentRange]);
  //
  //       if (CurrentLookup >= RangeBegin && CurrentLookup <= RangeEnd) {
  //         sum++;
  //         break;
  //       }
  //     }
  //   }
  //
  //   Final = std::to_string(sum);
  // }
  std::string Final;
  struct Intervals {
    long long Left;
    long long Right;
  };
  Solve(std::vector<std::string> &Object) {
    std::vector<Intervals> Ranges;
    long long sum = 0;
    for (int i = 0; i < (int)Object.size(); i++) {
      std::string Current = Object[i];
      auto FoundRange = Current.find('-');
      if (FoundRange == std::string::npos)
        continue;
      long long SplitLeft = std::stoll(Current.substr(0, FoundRange));
      long long SplitRight = std::stoll(Current.substr(FoundRange + 1));

      Ranges.push_back({SplitLeft, SplitRight});
    }

    std::sort(Ranges.begin(), Ranges.end(),
              [](const Intervals &a, const Intervals &b) {
                if (a.Left == b.Left)
                  return a.Right < b.Right;
                return a.Left < b.Left;
              });

    long long CurrentLeft = Ranges[0].Left;
    long long CurrentRight = Ranges[0].Right;

    for (int j = 1; j < Ranges.size(); j++) {
      long long LeftIndex = Ranges[j].Left;
      long long RightIndex = Ranges[j].Right;

      if (LeftIndex > CurrentRight + 1) {
        sum += (CurrentRight - CurrentLeft + 1);
        CurrentLeft = LeftIndex;
        CurrentRight = RightIndex;
      }
      {
        if (RightIndex > CurrentRight)
          CurrentRight = RightIndex;
      }
    }

    sum += (CurrentRight - CurrentLeft + 1);
    Final = std::to_string(sum);
  }
};
