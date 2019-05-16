#include <cassert>
#include <cstdint>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Item final {
    int weight;
    int value;
    double weightedValue;
};
struct {
    bool operator()(Item a, Item b) const
    {
        return a.weightedValue > b.weightedValue;
    }
} ItemLess;
double get_max_knapsack_value(int capacity, std::vector <Item> items) {
    double value = 0.0;
    std::sort(items.begin(), items.end(), ItemLess);
    for (auto &item:items) {
        if (item.weight <= capacity){
            value += item.value;
            capacity -= item.weight;
        } else {
            value += item.value * (static_cast <double>(capacity) / item.weight);
            break;
        }
    }

    return value;
}

int main(void) {
    int number_of_items;
    int knapsack_capacity;
    std::cin >> number_of_items >> knapsack_capacity;
    std::vector <Item> items(number_of_items);
    for (int i = 0; i < number_of_items; i++) {
        std::cin >> items[i].value >> items[i].weight;
        items[i].weightedValue = static_cast <double>(items[i].value) / items[i].weight;
    }
//    int knapsack_capacity = 50;
//    std::vector <Item> items { Item{ .weight = 60, .value = 200}, Item{ .weight = 50, .value = 100}, Item{ .weight = 30, .value = 90} };
//    for (auto &item:items) {
//        item.weightedValue = static_cast <double>(item.value) / item.weight;
//    }

    double max_knapsack_value = get_max_knapsack_value(knapsack_capacity, std::move(items));

    std::cout.precision(10);
    std::cout << std::fixed << std::setprecision(3) << max_knapsack_value << std::endl;
    return 0;
}