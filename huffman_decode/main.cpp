#include <iostream>
#include <unordered_map>
#include <stdio.h>

int main() {
    int letters_count, code_length;
    std::cin >> letters_count >> code_length;
    std::unordered_map<std::string,char> letters_map;
    std::string character;
    std::string code;
    for (int i = 0; i < letters_count; i++){
        std::cin >> character >> code;
        letters_map[code] = character[0];
    }
    std::string codedString;
    std::cin >> codedString;
    int i = 0;
    std::string current = "";
    std::string decodedString = "";
    while (i < codedString.length()){
        current += codedString[i];
        auto found = letters_map.find(current);
        if (found != letters_map.end()){
            decodedString += found->second;
            current = "";
        }
        i++;
    }
    std::cout << decodedString;

    return 0;
}