#include "Map.h"
#include <iostream>
#include <map>

using namespace std;


Map::Map(int width, int height, Difficulty difficulty) {
    this->width = width;
    this->height = height;
    this->difficulty = difficulty;

    map = vector(width, vector(height, '.'));
}

void Map::generateMap() {

}

void Map::displayMap() {
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++ ) {
            cout << map[y][x];
        }
        cout << endl;
    }
}




