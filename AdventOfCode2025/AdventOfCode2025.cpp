#include "day11.cpp"
#include <format>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::string FileName = "input_day_eleven_1.txt";

void WriteToFile(const std::string &Data) {
  std::string FileCopy = FileName;
  FileCopy.erase(0, 5);
  std::string OutputFileName = "output" + FileCopy;
  std::ofstream Output("./output/" + OutputFileName);
  if (!Output.is_open())
    return;
  Output << Data;
  Output.close();
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::ifstream File("./input/" + FileName);
  if (!(File.is_open()))
    return -1;
  std::string Current;
  std::vector<std::string> Lines;
  while (getline(File, Current)) {
    Lines.push_back(Current);
  }
  Solve Output = Solve(Lines);
  WriteToFile(Output.Final);
  std::cout << Output.Final << "\n";
  File.close();
  return 0;
}
