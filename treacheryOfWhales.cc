#include <iostream>
#include <fstream>
#include <vector>
#include <limits>

int main() {
  std::vector<int> numbers{};
  std::ifstream ifs("treacheryOfWhalesInput.txt");

  std::string tmp{};
  while (std::getline(ifs, tmp, ',')) {
    int num = std::stoi(tmp);
    numbers.emplace_back(num);
  }

  int lowestSum = std::numeric_limits<int>::max();
 
  for (int base : numbers) {
    int sum{0};
    for (int num : numbers) {
      sum += (base > num) ? base - num : num - base;
    }
    if (sum < lowestSum)
      lowestSum = sum;
  }
  std::cout << lowestSum << std::endl;

}
