#include <iostream>
#include <vector>

class Node {
public:
    int key;
    Node *left;
    Node *right;
};

Node *find(Node *node, int key){
    if (!node || node->key == key){
        return node;
    }

    if (key > node->key){
        return node->right ? find(node->right, key) : node;
    }

    return node->left ? find(node->left, key) : node;

}

void traverse_in_order(Node *node){
    if (node->left){
        traverse_in_order(node->left);
    }
    std::cout << node->key << ' ';
    if (node->right){
        traverse_in_order(node->right);
    }
}
void traverse_pre_order(Node *node){
    std::cout << node->key << ' ';
    if (node->left){
        traverse_pre_order(node->left);
    }
    if (node->right){
        traverse_pre_order(node->right);
    }
}
void traverse_post_order(Node *node){
    if (node->left){
        traverse_post_order(node->left);
    }
    if (node->right){
        traverse_post_order(node->right);
    }
    std::cout << node->key << ' ';
}

int main() {
    unsigned int n;

    std::cin >> n;

    std::vector<int> keys;
    keys.resize(n);
    std::vector<int> left_childs;
    left_childs.resize(n);
    std::vector<int>right_childs;
    right_childs.resize(n);

    std::vector<Node*> nodes;
    nodes.resize(n);

    for (int i = 0; i < n; i++){
        std::cin >> keys[i];
        std::cin >> left_childs[i];
        std::cin >> right_childs[i];

        Node *node = new Node();
        node->key = keys[i];
        nodes[i] = node;
    }




    for (int i = 0; i < n; i++){

        Node *current = nodes[i];

        if (left_childs[i] != -1){
            Node *left = nodes[left_childs[i]];
            current->left = left;
        }

        if (right_childs[i] != -1){
            Node *right = nodes[right_childs[i]];
            current->right = right;
        }

    }

    Node *root = nodes[0];
    traverse_in_order(root);
    std::cout << std::endl;
    traverse_pre_order(root);
    std::cout << std::endl;
    traverse_post_order(root);
    std::cout << std::endl;

    return 0;
}