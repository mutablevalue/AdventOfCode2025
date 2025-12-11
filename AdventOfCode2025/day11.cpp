#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

class Solve {
public:
  std::string Final;

private:
  std::vector<std::string> Lines;
  std::unordered_map<std::string, std::vector<std::string>> Graph;
  std::unordered_map<std::string, std::unordered_map<int, long long>> Memo;
  std::unordered_set<std::string> Visiting;

public:
  Solve(std::vector<std::string> &Object) : Lines(Object) {
    BuildGraph();
    long long paths = Dfs("svr", 0);
    Final = std::to_string(paths);
  }

private:
  void BuildGraph() {
    for (const auto &line : Lines) {
      if (line.empty())
        continue;
      std::size_t colon = line.find(':');
      if (colon == std::string::npos)
        continue;

      std::string from = line.substr(0, colon);
      Trim(from);

      std::string rest = line.substr(colon + 1);
      std::istringstream iss(rest);
      std::string to;

      auto &vec = Graph[from];
      while (iss >> to) {
        vec.push_back(to);
      }
    }
  }

  std::string Trim(std::string &Str) {
    while (!Str.empty() && std::isspace(Str.front()))
      Str.erase(Str.begin());
    while (!Str.empty() && std::isspace(Str.back()))
      Str.pop_back();
    return Str;
  }

  long long Dfs(const std::string &node, int mask) {
    int newMask = mask;
    if (node == "dac")
      newMask |= 1;
    if (node == "fft")
      newMask |= 2;

    if (node == "out")
      return newMask == 3 ? 1 : 0;

    auto itNode = Memo.find(node);
    if (itNode != Memo.end()) {
      auto itMask = itNode->second.find(newMask);
      if (itMask != itNode->second.end())
        return itMask->second;
    }

    Visiting.insert(node);

    long long sum = 0;
    auto it = Graph.find(node);
    if (it != Graph.end()) {
      for (const auto &next : it->second) {
        sum += Dfs(next, newMask);
      }
    }

    Visiting.erase(node);

    Memo[node][newMask] = sum;
    return sum;
  }
};
