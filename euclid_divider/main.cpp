#include <cassert>
#include <cstdint>
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

template <class Int>
long long int factorial(Int x){
    long long int fact = 1;
    while (x > 1){
        fact *= x;
        x-= 1;
    }
    return fact;
}

void addValue(vector<long long int> *values, const char *label, int64_t value){
    values->push_back(value);
    std::cout << label << ": " << value << std::endl;
}

int main(void) {
    std::int64_t n = 100000;
    //std::cin >> n;
//    std::cout << gcd(a, b) << std::endl;
    long long int fact = factorial(n);
    std::vector<long long int> values;

    //std::cout << "log2(n): " << log2(n) << std::endl;
    //std::cout << "log2(n) ^ 2: " << pow(log2(n),2) << std::endl;
    //std::cout << "sqrt(n): " << pow(log2(n),2) << std::endl;
    //std::cout << "log2(n!): " << log2(fact) << std::endl;
    //std::cout << "3^log2(n): " << pow(3, log2(n)) << std::endl;
    addValue(&values, "sqrt(log(4, n))", sqrt(log(n)/log(4)));
    addValue(&values, "log2(log2(n))", log2(log2(n)));
    addValue(&values, "log3(n)", log(n)/log(3));
    addValue(&values, "sqrt(n)", sqrt(n));
    addValue(&values, "(log2(n))^2", pow(log2(n), 2));
    addValue(&values, "n/log5(n)", n*log(5)/log(n));
    addValue(&values, "log2(n!)", log2(fact));
    addValue(&values, "3^log2(n)", pow(3, log2(n)));
    addValue(&values, "n^2", pow(n, 2));
    addValue(&values, "7^log2(n)", pow(7, log2(n)));
    addValue(&values, "(log2(n))^log2(n)", pow(log2(n), log2(n)));
    addValue(&values, "n^log2(n)", pow(n, log2(n)));
    addValue(&values, "n^sqrt(n)", pow(n, sqrt(n)));
    addValue(&values, "2^n", pow(2, n));
    addValue(&values, "4^n", pow(4, n));
    addValue(&values, "2^3n", pow(2, 3*n));
    addValue(&values, "n!", fact);
    addValue(&values, "2^2^n", pow(2, pow(2, n)));


//    int64_t val1 = pow(4, n);
//    values.push_back(val1);loga
//    std::cout << "4^n: " << val1 << std::endl;
//    int64_t val2 = pow(2,3*n);
//    values.push_back(val2);
//    std::cout << "2^3n: " << val2 << std::endl;
//    values.push_back(fact);
//    std::cout << "n!: " << fact << std::endl;
//    int64_t val4 = pow(n, sqrt(n));
//    values.push_back(val4);
//    std::cout << "n^sqrt(n): " << val4 << std::endl;
//    int64_t val5 = pow(n, log2(n));
//    values.push_back(val5);
//    std::cout << "n^log2(n): " << val5 << std::endl;

    //std::cout << "2^2^n: " << pow(2,pow(2,n)) << std::endl;
    sort (values.begin(), values.end());

    std::cout << "myvector contains:";
    for (std::vector<long long int>::iterator it=values.begin(); it!=values.end(); ++it)
        std::cout << ' ' << *it;
    std::cout << '\n';

    return 0;
}