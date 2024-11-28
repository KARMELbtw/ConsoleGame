#include "Map.h"
#include <map>

using namespace std;


Map::Map(int width, int height, Difficulty difficulty) {
    this->width = width;
    this->height = height;
    this->difficulty = difficulty;

    map = vector<vector<string>>(width, vector<string>(height, "X"));
}

Map::Map() {}

void Map::generateMap() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            map[x][y] = "X";
        }
    }
}

const vector<vector<string>> &Map::getMap() const {
    return map;
}




