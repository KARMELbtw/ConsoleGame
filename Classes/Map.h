#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>

#include "../Enums/Difficulty.cpp"

using namespace std;

class Map {
public:
    Map(int height, int width, Difficulty difficulty);

    Map();

    void generateMap();
    void createMapEdges();
    void saveMap();

    [[nodiscard]] const vector<vector<string>> &getMap() const;

private:
    int height;
    int width;
    Difficulty difficulty;
    vector<vector<string>> map;
};

#endif //MAP_H
