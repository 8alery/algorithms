#include <iostream>
#include <vector>
#include <stack>

struct Node {
    unsigned long long key{0};
    Node* left{nullptr};
    Node* right{nullptr};
    Node* parent{nullptr};
};

class SplayTree {
    void print(Node* node, int level){
        if (node->left){
            print(node->left, level + 1);
        }

        int i = 0;
        while (i < level){
            std::cout << " ";
        }
        std::cout << node->key;

        if (node->right){
            print(node->right, level + 1);
        }

    }
    void set_parent(Node* child, Node* parent){
        if (child){
            child->parent = parent;
        }
    }

    void keep_parent(Node* v){
        set_parent(v->left, v);
        set_parent(v->right, v);
    }


    void rotate(Node* parent, Node* child){
        auto gparent = parent->parent;
        if (gparent){
            if (gparent->left == parent) {
                gparent->left = child;
            } else{
                gparent->right = child;
            }
        }

        if (parent->left == child){
            parent->left = child->right;
            child->right = parent;
        } else {
            parent->right = child->left;
            child->left = parent;
        }

        keep_parent(child);
        keep_parent(parent);
        child->parent = gparent;
    }

    Node* splay(Node* v){
        if (!v->parent){
            return v;
        }

        auto parent = v->parent;
        auto gparent = parent->parent;

        if (!gparent){
            rotate(parent, v);
            return v;
        }
        bool zigzig = ((gparent->left == parent) && (parent->left == v)) || ((gparent->right == parent) && (parent->right == v));
        if (zigzig){
            rotate(gparent, parent);
            rotate(parent, v);
        } else {
            rotate(parent, v);
            rotate(gparent, v);
        }
        return splay(v);

    }

    Node* find_node(Node* v, unsigned long long key){
        if (!v){
            return nullptr;
        }

        if (v->key == key){
            return splay(v);
        }

        if (key < v->key && v->left){
            return find_node(v->left, key);
        }

        if (key > v->key && v->right){
            return find_node(v->right, key);
        }

        return splay(v);


    }

    std::pair<Node*,Node*> splitLess(Node* node, unsigned long long key){
        if (!node){
            return std::make_pair(nullptr, nullptr);
        }

        node = find_node(node, key);
        if (node->key >= key){
            set_parent(node->left, nullptr);
            Node* v1 = node->left;
            node->left = nullptr;
            return std::make_pair(v1, node);
        }


        Node* v2 = node->right;
        set_parent(v2, nullptr);
        node->right = nullptr;
        return std::make_pair(node, v2);

    }

    std::pair<Node*,Node*> splitGreater(Node* node, unsigned long long key){
        if (!node){
            return std::make_pair(nullptr, nullptr);
        }

        node = find_node(node, key);
        if (node->key <= key){
            set_parent(node->right, nullptr);
            Node* v2 = node->right;
            node->right = nullptr;
            return std::make_pair(node, v2);
        }


        Node* v1 = node->left;
        set_parent(v1, nullptr);
        node->left = nullptr;
        return std::make_pair(v1, node);

    }


public:
    Node* root{nullptr};

    void insert(unsigned long long key){

    }

    void remove(unsigned long long key){

    }

    Node* find(unsigned long long key){
        Node* node = find_node(root, key);
        root = node;
        return (node->key == key ? node: nullptr);
    }

    void visualize(){
        print(root, 0);
    }
};

struct Command {
    std::string name;
    unsigned long long key;
    unsigned long long anotherKey;
};

unsigned long long s = 0;
unsigned long long p = 1000000001;
unsigned long long f(unsigned long long x){
    return (x % p + s % p) % p;
}

int main() {

    unsigned int n;
    std::cin >> n;

    SplayTree tree;

    std::string command;
    std::vector<Command> commands(n);

    for (auto &command:commands){
        std::cin >> command.name >> command.key;
        if (command.name === "s"){
            std::cin >> command.anotherKey;
        }
    }

    for (auto &command:commands){

        unsigned long long key = f(command.key);
        if (command.name == "+"){
            tree.insert(key);
        } else if (command.name == "-"){
            tree.remove(key);
        } else if (command.name == "?"){
            auto found = tree.find(key);
            std::cout << (found ? "Found" : "Not found") << std::endl;
        }

        tree.visualize();
        std::cout << std::endl;

    }

    return 0;
}