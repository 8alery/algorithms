#include <iostream>
#include <vector>

std::vector<std::pair<int, int>> actions;

int parent_index(int i){
    return (i - 1)/2;
}

int left_child_index(int i){
    return  2*i + 1;
}

int right_child_index(int i){
    return 2*i + 2;
}

void sift_down(std::vector<int>& items, int index){
    int min_index = index;
    int cl = left_child_index(index);
    int cr = right_child_index(index);

    if (cl < items.size() && items[cl] < items[min_index]){
        min_index = cl;
    }
    if (cr < items.size() && items[cr] < items[min_index]){
        min_index = cr;
    }

    if (min_index != index){
        std::swap(items[index], items[min_index]);
        actions.emplace_back(std::make_pair(index, min_index));
        sift_down(items, min_index);
    }
}

int main() {
    unsigned int length;

    std::cin >> length;
    std::vector<int> elements;
    elements.resize(length);

    for (int i = 0; i < length; i++){
        std::cin >> elements[i];
    }

    for (int i = length/2 - 1; i >= 0; i--){
        sift_down(elements, i);
    }

    std::cout << actions.size() << std::endl;

    for (auto item:actions){
        std::cout << item.first << ' ' << item.second << std::endl;
    }

    return 0;
}