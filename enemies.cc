#include <iostream>
#include <vector>
#include <string>
#include "enemies.h"
#include "stats.h"
#include "xp.h"
#include <random>

Enemies createEnemy(const std::string& name, const Stats& stats){
    Enemies enemies;
    enemies.name = name;
    enemies.stats = stats;
    return enemies;
};

std::vector<Enemies> getPredefinedEnemies(){
    return{
        createEnemy("Baby Dragon", {20, 5, 10, 5}),
        createEnemy("Slime", {30, 5, 0, 0}),
        createEnemy("Bat", {25, 5, 0, 10}),
        createEnemy("Goblin", {100, 10, 0, 0}),
        createEnemy("Armored Goblin", {150, 10, 10, 0}),
        createEnemy("Great Slime", {200, 15, 0, -10}),
        createEnemy("Berserker", {130, 30, 0, 10}),
    };
};

Enemies randomEnemy (const std::vector<Enemies>& enemies){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, enemies.size() - 1);
    return enemies[dis(gen)];
};