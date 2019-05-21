#include <iostream>
#include <vector>
#include <stack>


struct Node {
    unsigned long long key{0};
    Node* left{nullptr};
    Node* right{nullptr};
    Node* parent{nullptr};
};

unsigned long long s = 0;
unsigned long long p = 1000000001;
unsigned long long f(unsigned long long x){
    return (x % p + s % p) % p;
}

void setLeftChild(Node* parent, Node* child){
    if (!parent){
        return;
    }
    parent->left = child;
    if (child){
        child->parent = parent;
    }
}

void setRightChild(Node* parent, Node* child){
    if (!parent){
        return;
    }
    parent->right = child;
    if (child){
        child->parent = parent;
    }
}

void fixParentOfGrandfather(Node* node, Node* grandFather){
    if (!node){
        return;
    }
    if (node->parent){
        if (grandFather == node->parent->left){
            node->parent->left = node;
        } else {
            node->parent->right = node;
        }
    }
}

// grandFather->left = father, father->left = node
void zigzig(Node* node, Node* father, Node* grandFather) {

    Node* grandGrandFather = grandFather->parent;

    setLeftChild(grandFather, father->right);
    setRightChild(father, grandFather);
    setLeftChild(father, node->right);
    setRightChild(node, father);

    node->parent = grandGrandFather;
    father->parent = node;
    grandFather->parent = father;

    fixParentOfGrandfather(node, grandFather);

}

// node == father->left, father == grandFather->right
void zigzag(Node* node, Node* father, Node* grandFather) {

    Node* grandGrandFather = grandFather->parent;

   setRightChild(grandFather, node->left);
   setLeftChild(father, node->right);
   setLeftChild(node, grandFather);
   setRightChild(node, father);

   node->parent = grandGrandFather;
   father->parent = node;
   grandFather->parent = node;

   fixParentOfGrandfather(node, grandFather);

}

// node == father->right, father == grandFather->right
void zagzag(Node* node, Node* father, Node* grandFather) {

    Node* grandGrandFather = grandFather->parent;

    setRightChild(grandFather, father->left);
    setLeftChild(father, grandFather);
    setRightChild(father, node->left);
    setLeftChild(node, father);

    node->parent = grandGrandFather;
    father->parent = node;
    grandFather->parent = father;

    fixParentOfGrandfather(node, grandFather);
}

// node == father->right, father == grandFather->left
void zagzig(Node* node, Node* father, Node* grandFather) {

    Node* grandGrandFather = grandFather->parent;

    setLeftChild(grandFather, node->right);
    setRightChild(father, node->left);
    setLeftChild(node, father);
    setRightChild(node, grandFather);

    node->parent = grandGrandFather;
    grandFather->parent = node;
    father->parent = node;

    fixParentOfGrandfather(node, grandFather);
}

void splay(Node *node){
    if (!node){
        return;
    }
    if (!node->parent){
        return;
    }

    Node* father = node->parent;
    Node* grandFather = node->parent->parent;

    // Zig or zag
    if (!grandFather){

        // zig
        if (node == father->left){
            setLeftChild(father, node->right);
            setRightChild(node, father);
            node->parent = nullptr;
        } else { // zag
            setRightChild(father, node->left);
            setLeftChild(node, father);
            node->parent = nullptr;
        }

    } else {

        if (node == father->left) {
            if (father == grandFather->left){
                zigzig(node, father, grandFather);
            } else {
                zigzag(node, father, grandFather);
            }

        } else { // node == father->right

            if (father == grandFather->right) {
                zagzag(node, father, grandFather);
            } else {
                zagzig(node, father, grandFather);
            }

        }

        if (node->parent){
            splay(node);
        }

    }




}

Node* findPosibleParent(Node *node, unsigned long long key){
    if (!node){
        return node;
    }

    if (node->key == key){
        return node;
    }

    if (node->key > key && !node->left){
        return node;
    }

    if (node->key < key && !node->right){
        return node;
    }

    return (node->key > key) ? findPosibleParent(node->left, key) : findPosibleParent(node->right, key);

}

Node* addNode(Node *node, unsigned long long key){
    if (!node){
        node = new Node();
        node->key = key;
        return node;
    }

    Node* parent = findPosibleParent(node, key);
    if (parent->key == key){
        // Maybe splay(parent) ?
        splay(parent);
        return parent;
    }

    Node* newNode = new Node();
    newNode->key = key;
    //newNode->sum = key;
    newNode->parent = parent;

    if (key > parent->key){
        parent->right = newNode;
    } else {
        parent->left = newNode;
    }

    splay(newNode);
    return newNode;

}

Node* maxEl(Node *node){
    if (!node){
        return nullptr;
    }
    if (!node->right){
        return node;
    }
    return maxEl(node->right);
}

Node* merge(Node* left, Node* right){
    if (!left){
        return right;
    }
    if (!right){
        return left;
    }
    Node* u = maxEl(left);
    splay(u);
    u->right = right;
    right->parent = u;
    return u;
}

Node* removeNode(Node* root, unsigned long long key){
    if (!root){
        return root;
    }
    Node* node = findPosibleParent(root, key);
    splay(node);

    if (node->key == key){
        if (node->left){
            node->left->parent = nullptr;
        }
        if (node->right){
            node->right->parent = nullptr;
        }
        return merge(node->left, node->right);
    } else {
        return node;
    }
}

Node* findNode(Node *node, unsigned long long key){
    if (!node){
        return node;
    }

    Node* parent = findPosibleParent(node, key);
    splay(parent);

    return parent;

}

// left: < key, right: >= key
void splitLess(Node *root, unsigned long long key, Node **left, Node **right){
    Node* node = findPosibleParent(root, key);
    splay(node);

    if (node->key < key){
        *left = node;
        *right = node->right;
        if (*right){
            (*right)->parent = nullptr;
        }
        node->right = nullptr;

    } else {
        *left = node->left;
        *right = node;
        node->left = nullptr;
        if (*left){
            (*left)->parent = nullptr;
        }
    }
}

// left: <= key, right: > key
void splitGreater(Node *root, unsigned long long key, Node **left, Node **right){
    Node* node = findPosibleParent(root, key);
    splay(node);

    if (node->key <= key){
        *left = node;
        *right = node->right;
        if (*right){
            (*right)->parent = nullptr;
        }
        node->right = nullptr;

    } else {
        *left = node->left;
        *right = node;
        node->left = nullptr;
        if (*left){
            (*left)->parent = nullptr;
        }
    }
}

unsigned long long getTreeSum(Node* node){
    unsigned long long sum = node->key;
    if (node->left){
        unsigned long long sum_left = getTreeSum(node->left);
        sum += sum_left;
    }
    if (node->right){
        unsigned long long sum_right = getTreeSum(node->right);
        sum += sum_right;
    }
    return sum;
}

unsigned long long getSum2(Node* node, unsigned long long left, unsigned long long right, Node** root){
    if (!node){
        return 0;
    }
    Node* lessThanLeft;
    Node* greaterOrEqualThanLeft;

    // lessThanLeft - all nodes < left, greaterThanLeft - all nodes >= left
    splitLess(node, left, &lessThanLeft, &greaterOrEqualThanLeft);

    Node* betweenLeftAndRight;
    Node* greaterThanRight;

    if (!greaterOrEqualThanLeft){
        *root = lessThanLeft;
        return 0;
    }

    splitGreater(greaterOrEqualThanLeft, right, &betweenLeftAndRight, &greaterThanRight);

    if (!betweenLeftAndRight){
        *root = merge(lessThanLeft, greaterOrEqualThanLeft);
        return 0;
    }

    unsigned long long sum = getTreeSum(betweenLeftAndRight);

    // Merge right branch back
    Node* node1 = merge(betweenLeftAndRight, greaterThanRight);
    // Merge left branch back
    Node* node2 = merge(lessThanLeft, node1);

    *root = node2;
    return sum;
}

void getSum(Node* root, unsigned long long left, unsigned long long right, unsigned long long* sum){
    if (!root){
        return;
    }
    if (root->left){
        getSum(root->left, left, right, sum);
    }

    if (root->key >= left && root->key <= right){
        *sum += root->key;
    }

    if (root->right){
        getSum(root->right, left, right, sum);
    }
}

void traverse(Node* root){
    if (!root){
        return;
    }
    if (root->left){
        traverse(root->left);
    }
    std::cout << root->key << ' ';
    if (root->right){
        traverse(root->right);
    }
}

int main() {

    unsigned int n;
    std::cin >> n;

    Node* root = nullptr;

    std::string command;
    std::vector<std::string> result;

    unsigned long long key;
    unsigned long long l, r;
    for (int i = 0; i < n; i++){

        std::cin >> command;
        std::cin >> key;
        key = f(key);

        if (command == "+"){
            root = addNode(root, key);
        } else if (command == "-"){
            root = removeNode(root, key);
        } else if (command == "?"){
            root = findNode(root, key);
            result.emplace_back((root && root->key == key) ? "Found" : "Not found");
            //std::cout << ((root && root->key == key) ? "Found" : "Not found") << std::endl;
        } else if (command == "s"){
            l = key;
            std::cin >> r;
            r = f(r);

            if (root){
                unsigned long long sum = getSum2(root, l, r, &root);
                //unsigned long long sum = 0;
                //getSum(root, l, r, &sum);
                result.emplace_back(std::to_string(sum));
                s = sum;
            } else {
                s = 0;
                result.emplace_back(std::to_string(s));
            }

            //std::cout << std::to_string(sum) << std::endl;
        }

        //traverse(root);
        //std::cout << std::endl;
//        bool isCorrect = check_tree(root);
//        if (!isCorrect){
//            std::cout << "Tree is incorrect";
//        }

    }

    for (auto &el:result){
        std::cout << el << std::endl;
    }

    return 0;
}