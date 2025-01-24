#ifndef MAPS_H
#define MAPS_H
#include <vector>
#include "player.h"



void generateMap(std::vector<std::vector<char>>& map, int rows, int cols);
void movePlayer(Player& player,std::vector<std::vector<char>>& map);
void printMap(std::vector<std::vector<char>>& map);

#endif