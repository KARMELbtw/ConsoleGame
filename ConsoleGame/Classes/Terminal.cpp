#include <iostream>

#include "Terminal.h"

using namespace std;

void Terminal::clear() {
    for (int i = 0; i < 50; ++i) {
        cout << endl;
    }
}
