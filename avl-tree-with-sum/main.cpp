#include <iostream>

unsigned long long s = 0;

unsigned long long p = 1000000001;
unsigned long long f(unsigned long long x){
    return (x % p + s % p) % p;
}

struct Node {
    unsigned long long key{0};
    unsigned long long sum{0};
    unsigned long long height{0};
    Node* left{nullptr};
    Node* right{nullptr};
    Node* parent{nullptr};
};

Node* findNodeOrInsertPlace(Node* root, unsigned long long key){
    if (!root){
        return root;
    }

    if (root->key == key){
        return root;
    }

    if (key > root->key){
        return root->right ? findNodeOrInsertPlace(root->right, key) : root;
    }

    return root->left ? findNodeOrInsertPlace(root->left, key) : root;

}

Node* findNode(Node* root, unsigned long long key){
    Node* place = findNodeOrInsertPlace(root, key);
    return (place && place->key == key) ? place : nullptr;

}

Node* addNode(Node* root, unsigned long long key){
    Node* existingOrParent = findNodeOrInsertPlace(root, key);
    if (existingOrParent && existingOrParent->key == key){
        return existingOrParent;
    }

    Node* node = new Node();
    node->key = key;
    node->sum = key;

    if (existingOrParent){
        node->parent = existingOrParent;
        if (key > existingOrParent->key){
            existingOrParent->right = node;
        } else {
            existingOrParent->left = node;
        }
    }

    return node;

}

Node* getMaxEl(Node* node){
    if (!node){
        return nullptr;
    }
    if (!node->right){
        return node;
    }
    return getMaxEl(node->right);
}

Node* getMinEl(Node* node){
    if (!node){
        return nullptr;
    }
    if (!node->left){
        return node;
    }
    return getMinEl(node->left);
}

void setLeftChild(Node* parent, Node* child){

}

void setRightChild(Node* parent, Node* child){

}

void detachChild(Node* parent, Node* child){
    if (child == parent->left){
        parent->left = nullptr;
    } else {
        parent->right = nullptr;
    }
}

void removeNode(Node* root, unsigned long long key){
    Node* existing = findNodeOrInsertPlace(root, key);
    if (!existing || existing->key != key){
        return;
    }

    Node* parent = existing->parent;
    if (!existing->left && !existing->right){
        detachChild(parent, existing);
    } else if (existing->left && existing->right){

        Node* maxEl = getMaxEl(existing->left);
        Node* maxElParent = maxEl->parent;
        detachChild(maxElParent, maxEl);

        setLeftChild(maxEl, existing->left);
        setRightChild(maxEl, existing->right);

    } else {
        if (existing == parent->left){
            setLeftChild(parent, existing->left ? existing->left : existing->right);
        } else {
            setRightChild(parent, existing->left ? existing->left : existing->right);
        }
    }
}

Node* nextEl(Node* node){
    if (node->right){
        return getMinEl(node->right);
    }

    if (node->parent){
        Node* parent = node->parent;
        while (node == parent->left){
            node = parent;
            parent = node->parent;
        }
        return parent;
    }

    return nullptr;

}

void rotateSmall(Node* alpha, Node* beta){
    Node* grandDad = alpha->parent;
    if (beta == alpha->right){

        detachChild(alpha, beta);
        setRightChild(alpha, beta->left);
        setLeftChild(beta, alpha);

        beta->parent = grandDad;

    } else {
        detachChild(alpha, beta);
        setLeftChild(alpha, beta->right);
        setRightChild(beta, alpha);

        beta->parent = grandDad;
    }
}

void rotateBig(Node* alpha, Node* beta, Node* gamma){
    Node* grandDad = alpha->parent;

    if (beta == alpha->right){

        detachChild(beta, gamma);
        detachChild(alpha, beta);

        setRightChild(alpha, gamma->left);
        setLeftChild(beta, gamma->right);
        setLeftChild(gamma, alpha);
        setRightChild(gamma, beta);

        gamma->parent = grandDad;

    } else {

        detachChild(beta, gamma);
        detachChild(alpha, beta);

        setLeftChild(alpha, gamma->right);
        setRightChild(beta, gamma->left);
        setRightChild(gamma, alpha);
        setLeftChild(gamma, beta);

        gamma->parent = grandDad;

    }
}

void rotate(Node* node){

    int delta = node->right->height - node->left->height;

    if (delta > 1){

        Node* beta = node->right;

        if (beta->right->height >= beta->left->height){
            rotateSmall(node, beta);
            return rotate(beta);
        } else {
            Node* gamma = beta->left;
            rotateBig(node, beta, gamma);
            return rotate(gamma);
        }

    } else if (delta < -1){

        Node* beta = node->left;

        if (beta->left->height >= beta->right->height){
            rotateSmall(node, beta);
            return rotate(beta);
        } else {
            Node* gamma = beta->right;
            rotateBig(node, beta, gamma);
            return rotate(gamma);
        }


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
            N = addNode(root, key);
        } else if (command == "-"){
            root = removeNode(root, key);
        } else if (command == "?"){
            Node* found = findNode(root, key);
            result.emplace_back(found ? "Found" : "Not found");
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

    }

    for (auto &el:result){
        std::cout << el << std::endl;
    }

    return 0;
}