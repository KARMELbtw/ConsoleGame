#include "Map.h"
#include "Math.h"
#include "Terminal.h"
#include "Enemy.h"

#define RESET           "\033[0m"
#define RED             "\033[31m"
#define GREEN           "\u001b[32m"
#define BACKGROUNDGREEN  "\u001b[42m"
#define YELLOW          "\u001b[33m"
#define BLUE            "\u001b[34m"

using namespace std;


Map::Map(int width, int height, Difficulty difficulty, int renderWidth, int renderHeight) {
    this->mapHeight = height;
    this->mapWidth = width;
    this->difficulty = difficulty;
    this->renderWidth = renderWidth;
    this->renderHeight = renderHeight;

    rendererPositionX = (int)width / 2 - (int)renderWidth / 2;
    rendererPositionY = (int)height / 2 - (int)renderHeight / 2;
    playerPositionX = (int)renderWidth / 2;
    playerPositionY = (int)renderHeight / 2;
    map = vector<vector<char>>(height, vector<char>(width, 'd'));
    mapToRender = vector<vector<char>>(renderHeight, vector<char>(renderWidth, ' '));
}

void Map::generate() {
    generateStructures();
}

void Map::generateStructures() {
    for (int y = 1; y < mapHeight - 1; ++y) {
        for (int x = 1; x < mapWidth - 1; ++x) {
            if (Math::random(0, 1000) < (int)difficulty) {
                map[y][x] = '^';
            } else {
                map[y][x] = ' ';
            }
        }
    }
}

void Map::removeStructure(int y, int x) {
    map[y][x] = ' ';
}

void Map::addPlayer() {
    mapToRender[playerPositionY][playerPositionX] = 'O';
}

void Map::prepareToRender() {
    for (int y = 0; y < renderHeight; y++) {
        for (int x = 0; x < renderWidth; x++) {
            if (y == 0 || y == renderHeight - 1) {
                mapToRender[y][x] = '#';
            } else if (x == 0 || x == renderWidth - 1) {
                mapToRender[y][x] = '#';
            } else {
                mapToRender[y][x] = map[rendererPositionY + y][rendererPositionX + x];
            }
        }
    }
    addPlayer();
}

void Map::render() {

    prepareToRender();
    for (int y = 0; y < renderHeight; y++) {
        for (int x = 0; x < renderWidth; x++) {
            switch (mapToRender[y][x]) {
                case '^':
                cout << BLUE << "^" << RESET;
                    break;
                case '#':
                cout << BACKGROUNDGREEN << "#" << RESET;
                    break;
                default:
                    cout << mapToRender[y][x];
                    break;
            }
        }
        cout << endl;
    }
}

void Map::moveRenderer(int x, int y) {
    if (rendererPositionX + x > mapWidth - renderWidth || rendererPositionX + x < 0) {
        if (playerPositionX + x > renderWidth-2 || playerPositionX + x < 0) {
            return;
        } else {
            playerPositionX += x;
        }
        return;
    } else {
        if (playerPositionX == (int)renderWidth/2) {
            rendererPositionX += x;
        } else {
            playerPositionX += x;
        }
    }

    if (rendererPositionY + y > mapHeight - renderHeight || rendererPositionY + y < 0) {
        if (playerPositionY + y > renderHeight-2 || playerPositionY + y < 0) {
            return;
        } else {
            playerPositionY += y;
        }
        return;
    } else {
        if (playerPositionY == (int)renderHeight/2) {
            rendererPositionY += y;
        } else {
            playerPositionY += y;
        }
    }
}

void Map::checkForInteract(Player& player) {
    if (map[playerPositionY+rendererPositionY][playerPositionX+rendererPositionX] == '^'){
        startFight(player);
        removeStructure(playerPositionY+rendererPositionY, playerPositionX+rendererPositionX);
    } else if (map[playerPositionY+rendererPositionY-1][playerPositionX+rendererPositionX-1] == '^') {
        startFight(player);
        removeStructure(playerPositionY+rendererPositionY-1, playerPositionX+rendererPositionX-1);
    } else if (map[playerPositionY+rendererPositionY-1][playerPositionX+rendererPositionX] == '^') {
        startFight(player);
        removeStructure(playerPositionY+rendererPositionY-1, playerPositionX+rendererPositionX);
    } else if (map[playerPositionY+rendererPositionY-1][playerPositionX+rendererPositionX+1] == '^') {
        startFight(player);
        removeStructure(playerPositionY+rendererPositionY-1, playerPositionX+rendererPositionX+1);
    } else if (map[playerPositionY+rendererPositionY][playerPositionX+rendererPositionX-1] == '^') {
        startFight(player);
        removeStructure(playerPositionY+rendererPositionY, playerPositionX+rendererPositionX-1);
    } else if (map[playerPositionY+rendererPositionY][playerPositionX+rendererPositionX+1] == '^') {
        startFight(player);
        removeStructure(playerPositionY+rendererPositionY, playerPositionX+rendererPositionX+1);
    } else if (map[playerPositionY+rendererPositionY+1][playerPositionX+rendererPositionX-1] == '^') {
        startFight(player);
        removeStructure(playerPositionY+rendererPositionY+1, playerPositionX+rendererPositionX-1);
    } else if (map[playerPositionY+rendererPositionY+1][playerPositionX+rendererPositionX] == '^') {
        startFight(player);
        removeStructure(playerPositionY+rendererPositionY+1, playerPositionX+rendererPositionX);
    } else if (map[playerPositionY+rendererPositionY+1][playerPositionX+rendererPositionX+1] == '^') {
        startFight(player);
        removeStructure(playerPositionY+rendererPositionY+1, playerPositionX+rendererPositionX+1);
    }
}

void Map::startFight(Player& player) {
    Terminal::clear();
    bool fight = true;

    Enemy enemy = *new Enemy(Math::random(10*(int)difficulty, 15*(int)difficulty), Math::random((int)difficulty, (int)difficulty*2));
    cout << "You are fighting: " << RED << enemy.name << RESET << endl;
    cout << "Enemy HP: " << RED << enemy.hp << RESET << endl;
    cout << "Your HP: " << GREEN << player.hp << RESET << endl;
    cout << "Press 'a' to attack" << endl;
    cout << "Press 'r' to run" << endl;
    while (fight) {
        int ch = getchar();
        string inputString;
        if (ch != ' ') {
            switch (ch) {
                case 'a': case 'A':
                    Terminal::clear();
                    if (player.attack(enemy)) {
                        fight = false;
                        player.hp = 100;
                        cout << "Type anything to continue" << endl;
                        cin >> inputString;
                    }
                    cout << "Enemy HP: " << RED << enemy.hp << RESET << endl;
                    cout << "Your HP: " << GREEN << player.hp << RESET << endl;
                    cout << endl;
                    cout << enemy.name << " attacks" << endl;
                    if (enemy.attack(player, (int)difficulty)) {
                        fight = false;
                        player.alive = false;
                    }

                    cout << "Press 'a' to attack" << endl;
                    cout << "Press 'r' to run away" << endl;
                    break;
                case 'r': case 'R':
                    cout << "You ran away" << endl;
                    fight = false;
                    break;
                default:
                    break;
            }

        }
    }
}

void Map::processInput(Player& player) {
    if (!player.alive) {
        return;
    }
    int ch;
    bool running = true;
    while (running) {
        render();
        ch = getchar();
        switch (ch) {
            case 'w': case 'W':
                moveRenderer(0, -1);
                break;
            case 's': case 'S':
                moveRenderer(0, 1);
                break;
            case 'a': case 'A':
                moveRenderer(-1, 0);
                break;
            case 'd': case 'D':
                moveRenderer(1, 0);
                break;
            case 'x': case 'X':
                running = false;
                break;
            case 'e': case 'E':
                cout << "Interacting" << endl;
                checkForInteract(player);
                break;
            default:
                break;
        }
        Terminal::clear();
    }
}