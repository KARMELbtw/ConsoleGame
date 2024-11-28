#ifndef UNTITLED1_MAPRENDERER_H
#define UNTITLED1_MAPRENDERER_H


#include "Map.h"

class MapRenderer {

public:
    MapRenderer(Map map, int width, int heigth);
    void readMap();
    void addMapEdges();
    void renderMap();
private:

    Map wholeMap;
    vector<vector<string>> mapToRender;
    int height{};
    int width{};
    struct position {
        int x;
        int y;
    };
};


#endif
