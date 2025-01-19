#include <iostream>
#include "player.h"
#include "items.h"
#include "actions.h"
#include "enemies.h"
#include "item.h"
#include "xp.h"
#include "stats.h"
#include <string>
#include <vector>
#include "map.h"
#include "turns.h"

std::vector<std::vector<char>> map;
int x = 10, y = 10;

int main() {
    //test if the map works
    generateMap(map, x, y);
}