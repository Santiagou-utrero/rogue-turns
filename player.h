#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "xp.h"
#include "stats.h"
#include <vector>

struct Player
{
    std::string name;
    Stats stats;
    xp_logic xp;
    std::vector<Item> inventory;


    void showInfo() const {
        std::cout << "Name: " << name << "\n";
        std::cout << "Level: " << xp.level << " | Xp: " << xp.xp << " / " << xp.xpToLevelUp << "\n";
        std::cout << "HP: " << stats.hp
                  << " | Strenght: " << stats.strenght
                  << " | Defense: " << stats.strenght
                  << " | Speed: " << stats.strenght << '\n';
        std::cout << "Inventory:\n";
        for (const auto& Item : inventory)
        {
            std::cout << "- " << Item.name << "\n";
        }
        
    }
};

#endif