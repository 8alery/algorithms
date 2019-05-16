#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <array>

int min (int a, int b, int c){
    if (a <= b && a <= c){
        return a;
    }
    if (b <= a && b <= c){
        return b;
    }
    return c;
}

int diff(const char a, const char b){
    return a == b ? 0 : 1;
}

int get_levenshtein_distance(const std::string &str1, const std::string &str2) {
  // TODO optimize this function
  size_t size1 = str1.size() + 1;
  size_t size2 = str2.size() + 1;
  if (str1.empty() || str2.empty()) {
    return size1 + size2 - 2;
  }

  auto costs = new int*[size1 + 1];

  for(int i = 0; i < size1; i++){
      costs[i] = new int[size2];
      costs[i][0] = i;
  }

  for(int j = 0; j < size2; j++){
      costs[0][j] = j;
  }

  for( int i = 1; i < size1; i++){
      for (int j = 1; j < size2; j++){
          int c = diff(str1[i-1], str2[j-1]);
          costs[i][j] = min(
                  costs[i-1][j] + 1,
                  costs[i][j-1] + 1,
                  costs[i-1][j-1] + c
          );
      }
  }

  int distance = costs[size1-1][size2-1];

  for( int i = 0; i < size1; i++){
      delete [] costs[i];
//      for (int j = 0; j < size2; j++){
//          std::cout << costs[i][j] << " ";
//      }
//      std::cout << std::endl;
  }
  delete [] costs;

  return distance;

}

int main(void) {
  std::string str1;
  std::string str2;

  std::cin >> str1 >> str2;

  std::cout << get_levenshtein_distance(str1, str2) << std::endl;
}