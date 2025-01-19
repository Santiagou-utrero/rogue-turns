#include <string>
#include <iostream>
#include "xp.h"
#include "stats.h"
#include <vector>
#include "item.h"
#include "player.h"

#ifndef ENEMIES_H
#define ENEMIES_H

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
 
 std::vector<Enemies> getPredefinedEnemies();
 Enemies createEnemy(const std::string& name, const Stats& stats);
 Enemies randomEnemy (const std::vector<Enemies>& enemies);
 
 #endif