#include <iostream>
#include <vector>
#include <list>
#include <cmath>

class MyHash {
    int p = 1000000007;
    int x = 263;
    unsigned int m;

    std::vector<std::list<std::string>> table;
public:
    explicit MyHash(unsigned int p_m){
        m = p_m;
        table.resize(m);
    }

    int hash(std::string str){
        long long res = 0;
        long long pow = 1;

        for (int i = 0; i < str.length(); i++){
            int code = str[i];
            pow = i ? pow * x : 1;
            long long long_pow = pow % p;
            long long tmp = code * long_pow;
            long long tmp_int = tmp % p;
            res = (res + tmp_int) % p;
            pow = long_pow;
        }
        return (int)(res % m);
    }

    void add(std::string item){
        int index = hash(item);
        auto &list = table[index];
        for (const auto &it : list) {
            if (it == item){
                return;
            }
        }
        list.emplace_back(item);
    }

    void del(std::string item){
        int index = hash(item);
        auto &list = table[index];
        for (auto it = list.cbegin(); it != list.cend(); it++){
            if (*it == item){
              it = list.erase(it);
              break;
            }
        }
    }

    bool find(std::string item){
        int index = hash(item);
        auto &list = table[index];
        for (const auto &it : list) {
            if (it == item){
                return true;
            }
        }
        return false;
    }

    std::string check(int index){
        auto &list = table[index];
        std::string result;
        for (const auto &it : list) {
           result = it + ' ' + result;
        }
        return result;
    }

};

int main() {
    unsigned int n, m;

    std::cin >> m;
    std::cin >> n;

    MyHash hash(m);
    std::vector<std::string> output;

    std::string command, name;
    unsigned int index;
    for (int i = 0; i < n; i++){
        std::cin >> command;
        if (command == "add"){
            std::cin >> name;
            hash.add(name);
        } else if (command == "del"){
            std::cin >> name;
            hash.del(name);
        } else if (command == "find"){
            std::cin >> name;
            output.emplace_back(hash.find(name) ? "yes" : "no");
        } else {
            std::cin >> index;
            output.emplace_back(hash.check(index));
        }
    }

    for (auto el:output){
        std::cout << el << std::endl;
    }

    return 0;
}