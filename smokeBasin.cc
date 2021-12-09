#include <iostream>
#include <string>
#include <fstream>
#include <vector>

int main() {
  std::vector<std::string> heightRows{};
  std::ifstream inputFile("smokeBasinInput.txt");

  std::string row{};
  while (inputFile >> row) 
    heightRows.emplace_back(row);

  long unsigned int rowLength{heightRows.size()};
  long unsigned int columnLength{heightRows[0].length()};
  std::vector<std::vector<int>> heightMap(rowLength);

  for (int i{0}; i < rowLength; ++i) {
    for (int j{0}; j < columnLength; ++j) {
      char c = heightRows[i][j];
      std::string str(1,c);
      int height = std::stoi(str);
      heightMap[i].emplace_back(height);
    }
  }

  int sum {0};
  
  for (int mapRow{0}; mapRow < rowLength; ++mapRow) {
    for (int mapColumn{0}; mapColumn < columnLength; ++mapColumn) {
      int height = heightMap[mapRow][mapColumn];
      bool isLowPoint{true};
      
      if (mapRow > 0) {
        if (height >= heightMap[mapRow-1][mapColumn])
          isLowPoint = false;
      }

      if (mapRow < rowLength - 1) {
        if (height >= heightMap[mapRow+1][mapColumn])
          isLowPoint = false;
      }

      if (mapColumn > 0) {
        if (height >= heightMap[mapRow][mapColumn-1])
          isLowPoint = false;
      }
      
      if (mapColumn < columnLength - 1) {
        if (height >= heightMap[mapRow][mapColumn+1])
          isLowPoint = false;
      }

      if (isLowPoint)
        sum += height + 1;
    }
  }
  std::cout << sum << std::endl;
}
