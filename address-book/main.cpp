#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;

    std::vector<std::string> numbers;
    numbers.resize(10000000);
    std::vector<std::string> output;

    std::string command;
    int number;
    std::string name;
    for (int i = 0; i < n; i++){
        std::cin >> command;
        std::cin >> number;
        if (command == "add"){
            std::cin >> name;
            numbers[number] = name;
        } else if (command == "find"){
            output.emplace_back(numbers[number] == "" ? "not found": numbers[number]);
        } else {
            numbers[number] = "";
        }
    }

    for (auto el:output){
        std::cout << el << std::endl;
    }

    return 0;
}