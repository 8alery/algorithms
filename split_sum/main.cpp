#include <iostream>
#include <vector>

int main() {
    int n;
    std::cin >> n;
    if (n == 1){
        std::cout << 1 << std::endl;
        std::cout << 1 << std::endl;
    }
    std::vector<int> parts;
    int current = 0;
    while (n > 0){
        current += 1;
        if ((n - current) > current){
            n -= current;
            parts.push_back(current);
        } else {
            parts.push_back(n);
            break;
        }

    }
    std::cout << parts.size() << std::endl;
    for (auto part:parts) {
        std::cout << part << " ";
    }
    std::cout << std::endl;
    return 0;
}