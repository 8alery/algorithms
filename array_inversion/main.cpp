#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <queue>
#include <limits>

void printVector(std::vector<int> array){
    for (auto v:array){
        std::cout << v << " ";
    }
    std::cout << std::endl;
}

int next_power_of_two(int v){
    v--;
    v |= v >> 1;
    v |= v >> 2;
    v |= v >> 4;
    v |= v >> 8;
    v |= v >> 16;
    return v++;
}

long merge_sort_iterative(std::vector<int> array){

    long inversions = 0;

    int sizeModified = next_power_of_two(array.size());

    std::queue<std::vector<int>> queue;
    for (auto value:array){
        queue.push(std::vector<int>{ value });
    }
    for (int i = array.size(); i <= sizeModified; i++){
        queue.push(std::vector<int>{ std::numeric_limits<int>::max() });
    }
    while (queue.size() > 1){
        auto first = queue.front();
        queue.pop();
        auto second = queue.front();
        queue.pop();

        std::cout << "first: ";
        printVector(first);
        std::cout << "second: ";
        printVector(second);

        int i = 0, j = 0, totalSize = first.size() + second.size();
        std::vector<int> sorted;
        int current;
        long currentInversions = 0;
        while (i < first.size() && j < second.size()){
            if (first[i] <= second[j]){
                current = first[i++];
            } else {
                current = second[j++];
                currentInversions += (first.size() - i);
            }
            sorted.push_back(current);

        }

        while (i < first.size()) {
            sorted.push_back(first[i++]);
        }

        while (j < second.size()) {
            sorted.push_back(second[j++]);
        }
        queue.push(sorted);
        std::cout << "inversions: " << currentInversions << std::endl;
        std::cout << "sorted: ";
        printVector(sorted);
        inversions += currentInversions;
    }
    std::cout << "inversions: " << inversions << std::endl;
    std::cout << "sorted: ";
    printVector(queue.front());
    return inversions;

}


int main() {

//    std::vector<int> array = {7, 6, 5, 4, 3, 2, 1 };
//    int n = array.size();
      int n;
      std::cin >> n;
      std::vector<int> array;
      for (int i = 0; i < n; i++){
            int element = 0; //dis(gen);
            std::cin >> element;
            array.push_back(element);
      }
      long inversionsCount = merge_sort_iterative(array);
      std::cout << inversionsCount << std::endl;
      return 0;
//        int n = 100000;
//        std::vector<int> array;
//        std::random_device rd;  //Will be used to obtain a seed for the random number engine
//        std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
//    std::uniform_int_distribution<> dis(1, 1000000000);
//          for (int i = 0; i < n; i++){
//            int element = dis(gen);
//            array.push_back(element);
//      }
//      long inversionsCount = merge_sort_iterative(array);
//      std::cout << inversionsCount << std::endl;
//      return 0;


}