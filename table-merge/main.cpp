#include <iostream>
#include <vector>

class MySet {
    std::vector<int> nodes;
    std::vector<int> row_valus;

    int max_rows;
public:
    std::vector<int> sizes_log;
    MySet(int size){
        nodes.resize(size);
        row_valus.resize(size);
    }
    void make_set(int index, int rows){
        nodes[index] = index;
        row_valus[index] = rows;
        if (rows > max_rows){
            max_rows = rows;
        }
    }

    int find(int i){
        if (nodes[i] != i){
            nodes[i] = find(nodes[i]);
        }
        return nodes[i];
    }

    void merge(int destination, int source){
        int dest_id = find(destination);
        int source_id = find(source);
        if (dest_id != source_id){
            nodes[source_id] = dest_id;
            row_valus[dest_id] += row_valus[source_id];
            if (row_valus[dest_id] > max_rows){
                max_rows = row_valus[dest_id];
            }
        }
        sizes_log.emplace_back(max_rows);
    }


};

int main() {
    unsigned int tables_count;
    std::cin >> tables_count;

    int instructions_count;
    std::cin >> instructions_count;

    MySet *myset = new MySet(tables_count);

    int rows;
    for (int i = 0; i < tables_count; i++){
        std::cin >> rows;
        myset->make_set(i, rows);
    }

    int destination;
    int source;

    std::vector<int> sizes;
    sizes.resize(instructions_count);

    for (int i = 0; i < instructions_count; i++){
        std::cin >> destination;
        std::cin >> source;

        myset->merge(destination - 1, source - 1);

    }

    for (auto size:myset->sizes_log){
        std::cout << size << std::endl;
    }



    return 0;
}