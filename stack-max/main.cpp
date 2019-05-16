#include <iostream>
#include <stack>
#include <vector>
#include <string>

int main() {
    int operations_count;

    std::cin >> operations_count;
    std::string operation_name;
    int insertNumber;

    std::stack<int> elements;
    std::stack<int> maximums;

    for (int i = 0; i < operations_count; i++){
        std::cin >> operation_name;
        if (operation_name == "push"){
            std::cin >> insertNumber;

            elements.push(insertNumber);

            if (maximums.empty()){
                maximums.push(insertNumber);
            } else {
                int maximum = std::max(insertNumber, maximums.top());
                maximums.push(maximum);
            }

        } else if (operation_name == "pop") {
            elements.pop();
            maximums.pop();
        } else if (operation_name == "max"){
            std::cout << maximums.top() << std::endl;
        }
    }

    return 0;
}