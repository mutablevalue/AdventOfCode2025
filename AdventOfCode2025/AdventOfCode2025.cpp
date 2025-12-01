#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>

std::string FileName = "input_day_one.txt";

void WriteToFile(const std::string& Data) {
	std::string FileCopy = FileName;
	FileCopy.erase(0, 5);

	std::string OutputFileName = "output" + FileCopy;
	std::ofstream Output(OutputFileName);
	if (!Output.is_open()) return;
	Output << Data;
}

void Solve(std::vector<std::string>& Object) {
    int Starting = 50;
    int Result = 0;

    for (int entry = 0; entry < Object.size(); entry++) {
        std::string CurrentEntry = Object[entry];
        bool Add = (CurrentEntry[0] == 'R');
        CurrentEntry.erase(0, 1);

        int val = std::stoi(CurrentEntry);
        int Amount = Add ? Starting + val : Starting - val;

        if (Add) {
            if (Amount > 100) {
                Starting = Amount - 100;
            }
            else {
                Starting = Amount;
            }
        }
        else {
            if (Amount < 0) {
                Starting = Amount + 100;
            }
            else {
                Starting = Amount;
            }
        }
        if (Starting == 0) Result++;
    }

    WriteToFile(std::to_string(Result));
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
	Solve(Lines);
	return;
}