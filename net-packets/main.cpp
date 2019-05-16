#include <iostream>
#include <queue>

struct WorkItem {
    int start_time;
    int duration;
    WorkItem(int s, double d) : start_time(s), duration(d) { }
};

int main() {
    int buffer_size;
    int packets_count;

    std::cin >> buffer_size;
    std::cin >> packets_count;

    int arrival;
    int duration;

    std::queue<WorkItem> processing_queue;

    int current_time = 0;

    for (int i = 0; i < packets_count; i++){
        std::cin >> arrival;
        std::cin >> duration;

        current_time = arrival;

        while (!processing_queue.empty() && (processing_queue.front().start_time + processing_queue.front().duration) <= current_time){
            processing_queue.pop();
        }

        if (processing_queue.size() < buffer_size){

            if (!processing_queue.empty()){
                WorkItem last = processing_queue.back();
                WorkItem item(last.start_time + last.duration, duration);
                processing_queue.push(item);
                std::cout << item.start_time << std::endl;
            } else {
                WorkItem item(current_time, duration);
                processing_queue.push(item);
                std::cout << item.start_time << std::endl;
            }
        } else {
            std::cout << -1 << std::endl;
        }

    }

    return 0;
}