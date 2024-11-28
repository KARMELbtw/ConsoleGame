#ifndef MAP_H
#define MAP_H

#include <vector>

#include "../Enums/Difficulty.cpp"

using namespace std;

class Map {
public:
    Map(int height, int width, Difficulty difficulty);

    void generateMap();
    void displayMap();
    void saveMap();

private:
    int height;
    int width;
    Difficulty difficulty;
    vector<vector<char>> map;
};

#endif //MAP_H
