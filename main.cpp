#include <iostream>

#include "Classes/Map.h"

using namespace std;

int main() {
    Map *test = new Map(50, 50, Difficulty::EASY);
    test->displayMap();

    return 0;
}

