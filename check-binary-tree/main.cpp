#include <iostream>
#include <vector>

struct Node {
    int key{0};
    Node *left{nullptr};
    Node *right{nullptr};
};

bool correct(Node &root){

}

int main() {

    unsigned int n;
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

    bool is_correct = nodes.size() ? correct(nodes.front()) : true;

    std::cout << (is_correct ? "CORRECT" : "INCORRECT");

    return 0;
}