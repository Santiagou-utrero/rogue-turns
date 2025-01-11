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
        createEnemy("Baby Dragon", {100, 20, 10, 10}),
        createEnemy("Slime", {100, 10, 0, 0}),
        createEnemy("Bat", {50, 15, 0, 15}),
        createEnemy("Goblin", {100, 10, 10, 10}),
        createEnemy("Armored Goblin", {200, 20, 20, 0}),
        createEnemy("Great Slime", {300, 30, 40, -10}),
        createEnemy("Berserker", {200, 40, 0, 20}),
    };
};

Enemies randomEnemey (const std::vector<Enemies>& enemies){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, enemies.size() - 1);
    return enemies[dis(gen)];
};