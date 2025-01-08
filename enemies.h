#include <string>
#include <iostream>
#include "xp.h"
#include "stats.h"
#include <vector>
#include "item.h"
#include "player.h"

struct Enemies
{
    std::string name;
    Stats stats;
    std::vector<Item> dropInventory; 

    void showEnemyInfo() const {
        std::cout << "Enemy name: " << name << "\n";
        std::cout << "Hp" << stats.hp
                  << "| Strenght" << stats.strenght
                  << "| Defense" << stats.defense
                  << "| Speed" << stats.speed << "\n";
    }
};
 