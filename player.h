#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>
#include "xp.h"
#include "stats.h"
#include <vector>
#include "item.h"

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

    void addItem(const Item& item){
        inventory.push_back(item);
        stats.applyItem(item);
        std::cout << "Item added to inventory. Stats upgraded\n";
    }

    void removeItem(const std::string& itemName){
        for (auto it = inventory.begin(); it != inventory.end(); it++)
        {
            if (it->name == itemName)
            {
                stats.removeItem(*it);
                inventory.erase(it);
                std::cout << "item deleted, stats updated\n";
                return;
            }
            std::cout << "item not found in the inventory\n";
        }
    }
};

#endif