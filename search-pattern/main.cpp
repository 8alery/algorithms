#include <iostream>
#include <vector>
#include <stack>

int p = 1000000007;
int x = 263;
long long x_times_max = 0;

long get_hash(std::string &str, int from, int length){

    long long tmpX = 1;
    long long tmpSum = 0;

    for (int i = 0; i < length; i++){
        if (i != 0){
            tmpX = (tmpX * x) % p;
        }
        int code = str[from + i];

        long long tmpMult = (code * tmpX) % p;

        tmpSum = (tmpSum + tmpMult) % p;
    }

    x_times_max = tmpX;

    return (long)tmpSum;

}

long get_hash_from_previous(std::string &str, int from, int length, int previousHash){
    int removedCode = str[from + length];
    int addedCode = str[from];
    long long tmp = (previousHash - removedCode*x_times_max%p) * x % p + addedCode;
    return (tmp + p) % p;
}

int main() {

    std::string pattern;
    std::cin >> pattern;

    unsigned int m = pattern.length();
    long patternHash = get_hash(pattern, 0, m);

    std::string str;
    std::cin >> str;

    unsigned int n = str.length();
    std::vector<long> hashValues;

    for (int i = n - m; i >= 0; i--){
        long substrHash = (i == n - m) ? get_hash(str, i, m) : get_hash_from_previous(str, i, m, hashValues.back());
        hashValues.emplace_back(substrHash);
    }

    for (int i = 0; i <= n - m; i++){
        long hash = hashValues.back();
        hashValues.pop_back();
        if (hash == patternHash){
            bool match = true;
            for (int k = 0; k < m; k++){
                if (str[i + k] != pattern[k]){
                    match = false;
                    break;
                }
            }
            if (match){
                std::cout << i << ' ';
            }
        }
    }

    return 0;
}