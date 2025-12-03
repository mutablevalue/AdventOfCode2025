#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>
#include "day3.cpp"

std::string FileName = "input_day_three_1.txt";

void WriteToFile(const std::string& Data) {
	std::string FileCopy = FileName;
	FileCopy.erase(0, 5);

	std::string OutputFileName = "output" + FileCopy;
	std::ofstream Output(OutputFileName);
	if (!Output.is_open()) return;
	Output << Data;
	Output.close();
}


void main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	std::ifstream File(FileName);
	if (!(File.is_open())) return;
	std::string Current;
	std::vector <std::string> Lines;
	while (getline(File, Current)) {
		Lines.push_back(Current);
	}
	Solve Output = Solve(Lines);
	WriteToFile(Output.Final);
	File.close();
	return;
}