#include <iostream>
#include <vector>
#include <queue>

struct ProcessorInfo {
    int number;
    long time;
    ProcessorInfo(int n, long t):number(n), time(t){

    }
};

int main() {

    unsigned int processors_count;
    unsigned int tasks_count;

    std::cin >> processors_count;
    std::cin >> tasks_count;

    std::vector<int> tasks;
    tasks.resize(tasks_count);

    for (int i = 0; i < tasks_count; i++){
        std::cin >> tasks[i];
    }

    auto Compare = [](ProcessorInfo &a, ProcessorInfo &b) {
        if (a.time == b.time){
            return a.number < b.number;
        }
        return a.time > b.time;
    };
    std::priority_queue<ProcessorInfo, std::vector<ProcessorInfo>, decltype(Compare)> processors(Compare);
    for (int i = 0; i < processors_count; i++){
        ProcessorInfo proc(i, 0);
        processors.emplace(proc);
    }

    for (auto task_time:tasks){
        ProcessorInfo proc = processors.top();
        std::cout << proc.number << ' ' << proc.time << std::endl;
        processors.pop();
        proc.time += task_time;
        processors.emplace(proc);
    }




    return 0;
}