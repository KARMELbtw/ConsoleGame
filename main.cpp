#include <iostream>

#include "Classes/Map.h"
#include "Classes/MapRenderer.h"

using namespace std;

int main() {
    Map *map = new Map(100, 100, Difficulty::EASY);
    MapRenderer *mapRenderer = new MapRenderer(*map, 69, 27);
    map->generateMap();
    mapRenderer->readMap();
    mapRenderer->addMapEdges();
    mapRenderer->renderMap();


    return 0;
}