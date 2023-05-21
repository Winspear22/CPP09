#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>

bool is_sorted(const std::vector<int>& numbers) {
    for (size_t i = 1; i < numbers.size(); ++i) {
        if (numbers[i] < numbers[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    std::ifstream file("your_output_file.txt");
    std::string line;
    std::vector<int> numbers;

    while (std::getline(file, line)) {
        if (line.substr(0, 6) == "After:") {
            std::istringstream iss(line.substr(7));
            int number;
            while (iss >> number) {
                numbers.push_back(number);
            }
            break;
        }
    }

    if (is_sorted(numbers)) {
        std::cout << "The numbers are correctly sorted.\n";
    } else {
        std::cout << "The numbers are not correctly sorted.\n";
    }

    return 0;
}
