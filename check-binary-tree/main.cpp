#include <iostream>
#include <vector>
<<<<<<< HEAD

struct Node {
    int key{0};
    Node *left{nullptr};
    Node *right{nullptr};
};

bool correct(Node &root){
=======
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
>>>>>>> 58b5ed2558a83df7a2e2768cd2768bf1456162fd

}

int main() {
<<<<<<< HEAD

    unsigned int n;
    std::cin >> n;

    std::vector<Node> nodes(n);

=======
    int n;
    std::cin >> n;
    std::vector<Node> nodes(n);
>>>>>>> 58b5ed2558a83df7a2e2768cd2768bf1456162fd
    for (auto& n: nodes) {
        int leftIdx, rightIdx;
        std::cin >> n.key >> leftIdx >> rightIdx;
        if (leftIdx != -1)
            n.left = &nodes[leftIdx];
        if (rightIdx != -1)
            n.right = &nodes[rightIdx];
    }

<<<<<<< HEAD
    bool is_correct = nodes.size() ? correct(nodes.front()) : true;

    std::cout << (is_correct ? "CORRECT" : "INCORRECT");
=======
    bool isCorrect = nodes.empty() ? true : traverse_tree(nodes.front());
    std::cout << (isCorrect ? "CORRECT": "INCORRECT");

>>>>>>> 58b5ed2558a83df7a2e2768cd2768bf1456162fd

    return 0;
}