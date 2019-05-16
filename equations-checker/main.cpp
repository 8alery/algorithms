#include <iostream>
#include <vector>

class MySet {
    std::vector<int> nodes;
    std::vector<int> ranks;

public:
    MySet(int size){
        nodes.resize(size);
        ranks.resize(size);
    }
    void make_set(int index){
        nodes[index] = index;
        ranks[index] = 0;
    }

    int find(int i){
        if (nodes[i] != i){
            nodes[i] = find(nodes[i]);
        }
        return nodes[i];
    }

    void merge(int i, int j){
        int i_id = find(i);
        int j_id = find(j);
        if (i_id != j_id){

            if (ranks[i_id] > ranks[j_id]){
                nodes[j_id] = i_id;
            } else {
                nodes[i_id] = j_id;
                if (ranks[i_id] == ranks[j_id]){
                    ranks[j_id] += 1;
                }
            }

        }
    }


};

int main() {
    unsigned int variables_count;
    unsigned int equals_count;
    unsigned int non_equals_count;

    std::cin >> variables_count;
    std::cin >> equals_count;
    std::cin >> non_equals_count;

    MySet *myset = new MySet(variables_count);

    for (int i = 0; i < variables_count; i++){
        myset->make_set(i);
    }

    int first, second;
    for (int i = 0; i < equals_count; i++){
        std::cin >> first;
        std::cin >> second;

        myset->merge(first - 1, second - 1);

    }

    int correct = 1;

    for (int i = 0; i < non_equals_count; i++){
        std::cin >> first;
        std::cin >> second;

        int f_id = myset->find(first-1);
        int s_id = myset->find(second-1);

        if (f_id == s_id){
            correct = 0;
            break;
        }

    }

    std::cout << correct;

    return 0;
}