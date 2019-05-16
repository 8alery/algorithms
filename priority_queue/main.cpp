#include <iostream>
#include <vector>
#include <utility>
#include <limits>

class PriorityQueue {
    std::vector<int> array;
    void sift_up(int index){
        if (index == 0){
            return;
        }
        int parentIndex = (index - 1) / 2;
        if (array[index] > array[parentIndex]){
            std::swap(array[index], array[parentIndex]);
            sift_up(parentIndex);
        }

    }
    void sift_down(int index){
        int leftIndex = 2*index + 1;
        int rightIndex = 2*index + 2;
        int left = (leftIndex < array.size()) ? array[leftIndex] : std::numeric_limits<int>::infinity();
        int right = (rightIndex < array.size()) ? array[rightIndex] : std::numeric_limits<int>::infinity();
        if (array[index] < left || array[index] < right){
            if (left > right){
                std::swap(array[leftIndex], array[index]);
                sift_down(leftIndex);
            } else {
                std::swap(array[rightIndex], array[index]);
                sift_down(rightIndex);
            }
        }
    }
    public:
    void insert(int value){
        array.push_back(value);
        sift_up(array.size() - 1);
    }
    int extract_max(){
        if (array.size() > 1){
            std::swap(array[array.size() -1], array[0]);
        }
        auto last = array.back();
        array.pop_back();
        sift_down(0);
        return last;
    }
};

int main() {
    int operations_count;
    std::cin >> operations_count;
    std::string operation_name;
    int insertNumber;
    PriorityQueue *queue = new PriorityQueue();
    std::vector<int> result;
    for (int i = 0; i < operations_count; i++){
        std::cin >> operation_name;
        if (operation_name == "Insert"){
            std::cin >> insertNumber;
            queue->insert(insertNumber);
        } else {
            result.push_back(queue->extract_max());
        }
    }
    for (auto removed:result){
        std::cout << removed << std::endl;
    }
    return 0;
}