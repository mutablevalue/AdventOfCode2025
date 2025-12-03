#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <format>


class Solve {
public:
	std::string Final;

	Solve(std::vector<std::string>& Object) {
		int sum = 0;
		for (int i = 0; i < Object.size(); i++) {
			std::string& Bank = Object[i];
			int ABest = -1;
			int BBest = -1;
			int Combined = -1;
			int BestRightDigit = -1;
			for (int j = static_cast<int>(Bank.size()) - 1; j >= 0; --j) {
				int Voltage = Bank[j] - '0';
				if (BestRightDigit != -1) {
					int Possible = Voltage * 10 + BestRightDigit;

					if (Possible > Combined) {
						Combined = Possible;
						ABest = Voltage;
						BBest = BestRightDigit;
					}
				}

				if (Voltage > BestRightDigit) {
					BestRightDigit = Voltage;
				}
				std::cout << Combined << "\n";
			}
			sum += Combined;
		}
		std::cout << sum << "\n";
		Final = std::to_string(sum);
	}
};