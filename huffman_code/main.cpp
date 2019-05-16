#include <iostream>
#include <string>
#include <unordered_map>
#include <queue>
#include <memory>

struct Letter final {
    int frequency;
    std::string code;
};
struct Node {
    char value;
    bool leaf;
    Node* left;
    Node* right;
};
using my_pair_t = std::pair<Node *,int>;
using my_container_t = std::vector<my_pair_t>;

void fillCodes(std::unordered_map<char,Letter>* characters, std::string path, Node *node){
    if (node->leaf){
        (*characters)[node->value].code = path;
        return;
    }

    if (node->left){
        fillCodes(characters, path + "0", node->left);
    }

    if (node->right){
        fillCodes(characters, path + "1", node->right);
    }

}

int main() {
    std::string input;
    std::cin >> input;
    std::unordered_map<char,Letter> characters;
    for(auto character:input){
        auto search = characters.find(character);
        if(search != characters.end()) {
            search->second.frequency += 1;
        }
        else {
            characters[character] = Letter { .frequency = 1 };
        }
    }

    auto my_comp =
            [](const my_pair_t& e1, const my_pair_t& e2)
            { return e1.second > e2.second; };
    std::priority_queue<my_pair_t,
            my_container_t,
            decltype(my_comp)> queue(my_comp);

    for(auto iter = characters.begin(); iter != characters.end(); ++iter){
        auto character = iter->first; // pointer to Node
        auto frequency = iter->second.frequency;
        Node *node = new Node();
        node->value = character;
        node->leaf = true;
        queue.push(std::make_pair(node, frequency));
    }

    while (queue.size() > 1){

        auto min1 = queue.top();
        queue.pop();
        auto min2 = queue.top();
        queue.pop();
        int weight = min1.second + min2.second;
        Node *parent = new Node();
        parent->leaf = false;
        parent->left = min1.first;
        parent->right = min2.first;
        //parent->value = min1.first->value + min2.first->value;
        queue.push(std::make_pair(parent, weight));

    }

    Node *root = queue.top().first;
    if (root->left || root->right){
        fillCodes(&characters, "", root);
    } else {
        fillCodes(&characters, "0", root);
    }


    std::string result = "";
    for(auto character:input){
        result += characters[character].code;
    }

    std::cout << characters.size() << " " << result.length() << std::endl;
    for(auto iter = characters.begin(); iter != characters.end(); ++iter){
        auto character = iter->first; // pointer to Node
        auto code = iter->second.code;
        std::cout << character << ": " << code << std::endl;
    }

    std::cout << result;

    return 0;
}