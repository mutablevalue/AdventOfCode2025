#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>


class Solve {
public:

    // Part 1
    //std::string Final;
    //Solve(std::vector<std::string>& Object) {
    //    int Starting = 50;
    //    int Result = 0;

    //    for (int entry = 0; entry < Object.size(); entry++) {
    //        std::string CurrentEntry = Object[entry];
    //        bool Add = (CurrentEntry[0] == 'R');
    //        CurrentEntry.erase(0, 1);
    //        int val = std::stoi(CurrentEntry);
    //        val %= 100;
    //        int Amount = Add ? Starting + val : Starting - val;
    //        if (Add) {
    //            if (Amount >= 100) {
    //                Starting = Amount - 100;
    //            }
    //            else {
    //                Starting = Amount;
    //            }
    //        }
    //        else {
    //            if (Amount < 0) {
    //                Starting = Amount + 100;
    //            }
    //            else {
    //                Starting = Amount;
    //            }
    //        }
    //        std::cout << Starting << "\n";
    //        if (Starting == 0) Result++;
    //    }

    //    std::cout << "\n" << Result;
    //    Final = std::to_string(Result);
    //}

    // Part 2
    std::string Final;
    Solve(std::vector<std::string>& Object) {
        int Starting = 50;
        long long Result = 0;

        for (int entry = 0; entry < Object.size(); entry++) {
            std::string CurrentEntry = Object[entry];
            bool Add = (CurrentEntry[0] == 'R');
            CurrentEntry.erase(0, 1);
            long long Val = std::stoll(CurrentEntry);
            long long Step = Add ? 1 : -1;
            std::cout << CurrentEntry << "\n";
            for (long long i = 0; i < Val; i++)
            {
                Starting += Step;

                if (Starting == 100) Starting = 0;
                else if (Starting == -1) Starting = 99;

                if (Starting == 0) Result++;
            }
        }

        std::cout << "\n" << Result;
        Final = std::to_string(Result);
    }
};