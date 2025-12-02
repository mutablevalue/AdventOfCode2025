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
                int Len = static_cast<int>(Number.size());

                bool Invalid = false;
                for (int Block = 1; Block <= Len / 2; Block++) {
                    if (Len % Block != 0) continue;
                    bool Good = true;
                    for (int Digit = 0; Digit < Len; Digit++)
                        if (Number[Digit] != Number[Digit % Block]) { Good = false; break; }
                    if (Good) { Invalid = true; break; }
                }

                if (Invalid) Sum += N;
            }
        }
        Final = std::to_string(Sum);
        std::cout << Sum << "\n";
    }
};


