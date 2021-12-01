#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <numeric>

int main() {
  std::vector<int> numbers{};
  std::ifstream inputFile("SonarSweepInput.txt");

  int num{};
  while (inputFile >> num) {
    numbers.emplace_back(num);
  }

  std::adjacent_difference(numbers.begin(),numbers.end(), numbers.begin());

  int sum{0};

  std::for_each(numbers.cbegin()+1, numbers.cend(), [&sum](auto i){
                                                    if (i > 0)
                                                      sum++;
                                                  });
  
  std::cout << sum << std::endl;
}
