#include <cstdlib>
#include <ctime>

#include "Math.h"

int Math::random(int min, int max) {
    return rand() % (max - min + 1) + min;
}