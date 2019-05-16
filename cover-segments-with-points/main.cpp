#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

using Segment = std::pair<int, int>;

struct {
    bool operator()(Segment a, Segment b) const
    {
        return a.second < b.second;
    }
} segmentLess;

std::vector <int> get_covering_set(std::vector <Segment> segments) {
  std::vector <int> result;
  std::sort(segments.begin(), segments.end(), segmentLess);
  int i = 0, current_point;
  while (i < segments.size()) {
      current_point = segments[i].second;
      result.push_back(current_point);
      i++;
      while (segments[i].first <= current_point && i < segments.size()){
          i++;
      }
  }
  return result;
}

int main(void) {

  int segments_count;
  std::cin >> segments_count;
  std::vector <Segment> segments(segments_count);
  for (auto &s:segments) {
    std::cin >> s.first >> s.second;
  }
  auto points = get_covering_set(std::move(segments));
  std::cout << points.size() << std::endl;
  for (auto point:points) {
    std::cout << point << " ";
  }
  std::cout << std::endl;
}