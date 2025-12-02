#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>

class Solve {
public:
    std::string Final;

    Solve(std::vector<std::string>& Object) {
        long long Sum = 0;
        for (int I = 0; I < Object.size(); I++) {
            std::string Entry = Object[I];
            size_t Split = Entry.find('-');
            if (Split == std::string::npos) continue;

            long long Left = std::stoll(Entry.substr(0, Split));
            long long Right = std::stoll(Entry.substr(Split + 1));

            for (long long N = Left; N <= Right; N++) {
                std::string Number = std::to_string(N);

                if (Number.size() % 2 != 0) continue;

                int Half = static_cast<int>(Number.size() / 2);
                if (Number.compare(0, Half, Number, Half, Half) == 0) {
                    Sum += N;
                }
            }
        }
        Final = std::to_string(Sum);
        std::cout << Sum << "\n";
    }
};
