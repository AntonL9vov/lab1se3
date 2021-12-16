#pragma once
#include <string>
#include <limits>
#include <iostream>
#include <exception>
#include <ctime>
#include <chrono>

#include "menu.h"

int main() {

    srand(time(NULL));
    menu();
    return 0;
}