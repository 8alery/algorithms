#include <iostream>

class Node {
public:
    int key;
    Node *left;
    Node *right;
    Node(int k, Node *l, Node *r){
        key = k;
        left = l;
        right = r;
    }

    bool canAdd(int k){
        return  k > key ? right == nullptr : left == nullptr;
    }
};

class Tree {
    Node *root;
public:
    void addNode(int key){
        auto node = new Node(key, nullptr, nullptr);
        Node *current = root;

        while (!current->canAdd(key)){
            if (key > current->key){
                current = current->right;
            } else {
                current = current->left;
            }
        }

        if (key > current->key){
            current->right = node;
        } else {
            current->left = node;
        }

    }
};

int main() {
    int n;

    std::cin >> n;
    Tree tree;

    for (int i = 0; i < n; i++){
        tree.addNode(i);
    }

    return 0;
}