#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
  std::vector<std::string> setsOfLetters{};
  std::vector<int> availableSegmentNums = {2,3,4,7}; // Corresponds to segments for 1,7,4,8
  std::ifstream inputFile("sevenSegmentSearchInput.txt");
  std::string delimiter{"|"};

  std::string line{};
  while (std::getline(inputFile, line)) {
    std::size_t delimiterPos = line.find(delimiter);
    std::string result = line.substr(delimiterPos + 2);
    setsOfLetters.emplace_back(result);
  }

  int sum{0};

  for (std::string set : setsOfLetters) {
    int numOfSegs{0};
    for (int i{0}; i < set.length(); ++i) {
      if (set[i] == ' ') {
        if (std::any_of(availableSegmentNums.cbegin(), availableSegmentNums.cend(),
                        [numOfSegs](int i){return i == numOfSegs;})) {
            ++sum;
        }
        numOfSegs = 0;
      }
      else {
        ++numOfSegs;
      }
    }
    if (std::any_of(availableSegmentNums.cbegin(), availableSegmentNums.cend(),
                    [numOfSegs](int i){return i == numOfSegs;})) {
        ++sum;
    }
  }
  std::cout << sum << std::endl;
}
