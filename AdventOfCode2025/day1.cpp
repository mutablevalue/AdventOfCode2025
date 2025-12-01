#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>

std::string Solve(std::vector<std::string>& Object) {
    int Starting = 50;
    int Result = 0;

    for (int entry = 0; entry < Object.size(); entry++) {
        std::string CurrentEntry = Object[entry];
        bool Add = (CurrentEntry[0] == 'R');
        CurrentEntry.erase(0, 1);
        int val = std::stoi(CurrentEntry);
        val %= 100;
        int Amount = Add ? Starting + val : Starting - val;
        if (Add) {
            if (Amount >= 100) {
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
        std::cout << Starting << "\n";
        if (Starting == 0) Result++;
    }

    std::cout << "\n" << Result;
    return std::to_string(Result);
}