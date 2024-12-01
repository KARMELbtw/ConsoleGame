#include <iostream>

#include "Classes/Map.h"

#define RESET           "\033[0m"
#define RED             "\033[31m"
#define GREEN           "\u001b[32m"
#define BACKGROUNDGREEN  "\u001b[42m"
#define YELLOW          "\u001b[33m"
#define ORANGE          "\u001b[38;5;208m"
#define BLUE            "\u001b[34m"

using namespace std;

int main() {
    srand(time(0));

    cout << "Welcome to the game!" << endl;
    cout << "Please specify the difficulty you want to play at:" << endl;
    cout << BLUE << "(1)Trivial" << RESET << endl;
    cout << GREEN << "(2)Easy" << RESET << endl;
    cout << YELLOW << "(3)Medium" << RESET << endl;
    cout << ORANGE << "(4)Hard" << RESET << endl;
    cout << RED << "(5)Suicide" << RESET<< endl;
    cout << "You chose: ";
    int choice = 0;
    string inputString;

    input:
    while (!(cin >> choice)) {
        cin.clear();
        cin.ignore();
    }
    if (choice < 0 || choice > 6) {
        goto input;
    }

    Difficulty difficulty;

    switch (choice) {
        case 1:
            difficulty = Difficulty::TRIVIAL;
            cout << "You chose " << BLUE << "Trivial" << RESET << endl;
            break;
        case 2:
            difficulty = Difficulty::EASY;
            cout << "You chose " << GREEN << "Easy" << RESET << endl;
            break;
        case 3:
            difficulty = Difficulty::MEDIUM;
            cout << "You chose " << YELLOW << "Medium" << RESET << endl;
            break;
        case 4:
            difficulty = Difficulty::HARD;
            cout << "You chose " << ORANGE << "Hard" << RESET << endl;
            break;
        case 5:
            difficulty = Difficulty::SUICIDE;
            cout << "You chose " << RED << "Suicide" << RESET<< endl;
            break;
        default:
            difficulty = Difficulty::EASY;
            break;
    }

    cout << "Please specify your name:" << endl;
    while (!(cin >> inputString)) {
        cin.clear();
        cin.ignore();
    }
    Map map = *new Map(300, 300 , difficulty, 100, 40);
    Player player = *new Player(100, inputString, 10);

    cout << "Welcome " << inputString << endl;
    cout << "Move by typing a for left, w for up, d for right, s for down" << endl;
    cout << "Once you are close to the enemy(" << BLUE << "^" << RESET << ") type e to start fighting"<< endl;
    cout << "To stop playing type x" << endl;
    cout << "Type anything to continue" << endl;
    cin >> inputString;

    map.generate();
    map.processInput(player);

    return 0;
}