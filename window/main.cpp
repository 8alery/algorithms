#include <iostream>
#include <vector>
#include <stack>

class MyQueue {
    std::stack<int> push_items;
    std::stack<int> pop_items;
    std::stack<int> pop_items_max;

    int pushMax;

public:
    void push(int el){
        push_items.push(el);
        pushMax = std::max(pushMax, el);
    }
    int pop(){
        if (pop_items.empty()){
            while (!push_items.empty()){
                int item = push_items.top();
                push_items.pop();
                pop_items.push(item);

                int maxPop = pop_items_max.empty() ? -1 : pop_items_max.top();
                pop_items_max.push(std::max(maxPop, item));
            }
            pushMax = 0;
        }
        int item = pop_items.top();
        pop_items.pop();
        pop_items_max.pop();
        return item;
    }
    long size(){
        return push_items.size() + pop_items.size();
    }
    int max(){
        return std::max(pushMax, pop_items_max.empty() ? -1: pop_items_max.top());
    }
};

int main() {

    int length;

    std::cin >> length;

    int el;
    std::vector<int> items;
    for (int i = 0; i < length; i++){
        std::cin >> el;
        items.emplace_back(el);
    }

    int windowSize;
    std::cin >> windowSize;

    std::stack<int> insertStack;

    std::stack<int> popStack;
    std::stack<int> popStackMax;


    std::vector<int> result;

    MyQueue *myQueue = new MyQueue();

    for (auto item:items){
        myQueue->push(item);
        if (myQueue->size() == windowSize){
            result.push_back(myQueue->max());
            myQueue->pop();
        }
    }

    for (auto item:result){
        std::cout << item << ' ';
    }

    return 0;
}