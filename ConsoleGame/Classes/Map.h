#ifndef MAP_H
#define MAP_H

#include <vector>
#include <iostream>

#include "Player.h"

using namespace std;

class Map {
public:
    Map(int width, int height, Difficulty difficulty, int renderWidth, int renderHeight);

    Map();
    void generate();
    void generateStructures();
    void removeStructure(int x, int y);

    void addPlayer();
    void prepareToRender();
    void render();
    void processInput(Player& player);
    void moveRenderer(int x, int y);
    void checkForInteract(Player& player);
    void startFight(Player& player);

private:
    int mapWidth;
    int mapHeight;
    Difficulty difficulty;
    vector<vector<char>> map;
    vector<vector<char>> mapToRender;
    int renderWidth{};
    int renderHeight{};
    int rendererPositionX;
    int rendererPositionY;
    int playerPositionX;
    int playerPositionY;
};

#endif
