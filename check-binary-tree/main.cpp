#include <iostream>
#include <vector>
#include <stack>

struct Node {
    int key{0};
    Node* left{nullptr};
    Node* right{nullptr};
};

bool traverse_tree(Node &node){
    std::stack<Node*> stack;

    Node *current = &node;

    bool correct = true;
    int previous = INT32_MIN;

    while (current != nullptr || !stack.empty()){
        if (!stack.empty()){
            current = stack.top();
            stack.pop();

            if (current->left && current->key == current->left->key){
                correct = false;
                break;
            }

            if (current->key < previous){
                correct = false;
                break;
            }
            previous = current->key;

            if (current->right) {
                current = current->right;
            } else {
                current = nullptr;
            }
        }
        while (current!=nullptr){
            stack.push(current);
            current=current->left;
        }
    }

    return correct;

}

int main() {
    int n;
    std::cin >> n;
    std::vector<Node> nodes(n);
    for (auto& n: nodes) {
        int leftIdx, rightIdx;
        std::cin >> n.key >> leftIdx >> rightIdx;
        if (leftIdx != -1)
            n.left = &nodes[leftIdx];
        if (rightIdx != -1)
            n.right = &nodes[rightIdx];
    }

    bool isCorrect = nodes.empty() ? true : traverse_tree(nodes.front());
    std::cout << (isCorrect ? "CORRECT": "INCORRECT");


    return 0;
}