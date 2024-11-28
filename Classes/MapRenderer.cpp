#include "MapRenderer.h"

using namespace std;

MapRenderer::MapRenderer(Map map, int width, int height) {
    this->wholeMap = map;
    this->height = width;
    this->width = height;

    mapToRender = vector<vector<string>>(height, vector<string>(width, " "));
}

void MapRenderer::readMap() {
    for (int y = 1; y < width-1; y++) {
        for (int x = 1; x < height-1; x++) {
            mapToRender[y][x] = wholeMap.getMap()[y][x];
        }
    }
}

void MapRenderer::addMapEdges() {
    for (int y = 0; y < width; y++) {
        for (int x = 0; x < height; x++) {
            if (y == 0 || y == width - 1) {
                mapToRender[y][x] = "#";
            } else if (x == 0 || x == height - 1) {
                mapToRender[y][x] = "#";
            } else {
                mapToRender[y][x] = "X";
            }
        }
    }
}

void MapRenderer::renderMap() {
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            cout << mapToRender[x][y];
        }
        cout << endl;
    }
}

