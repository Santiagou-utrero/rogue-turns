#include  <iostream>
#include "player.h"
#include "items.h"
#include "enemies.h"


void attack(Player& player, Enemies& enemy){
    int damage = player.stats.strenght - enemy.stats.defense;
    damage = (damage > 0) ? damage: 1;
    enemy.stats.hp -= damage;

    std::cout << player.name << "attacked" << enemy.name
              << " for " << damage << " points of damage\n";

    if (enemy.stats.hp <= 0)
    {
        std::cout << "The enemy: " << enemy.name << " | Has been eliminated\n";
    }
}

void defense(Player& player){
    int defenseStance = player.stats.defense / 2;
    player.stats.defense += defenseStance;

    std::cout << player.name << " | Has incresed defense by: "
              << defenseStance << "temporarily.\n";
}

void consumeItem(Player& player, std::string& itemName){
    for (auto it = player.inventory.begin(); it != player.inventory.end(); it++)
    {
        if (it->name == itemName && it->isConsumable)
        {
            player.stats.applyItem(*it);
            player.inventory.erase(it);
            std::cout << player.name << " consumed: " << itemName << " and gained its effects.\n";
            return;
        }
        
    }
    std::cout << "No consumable item named: " << itemName << " found in the inventory\n"; 
}

void enemyAttack(Enemies& enemy, Player& player){
    int enemyDamage = enemy.stats.strenght - player.stats.defense;
    enemyDamage = (enemyDamage > 0) ? enemyDamage : 1;
    player.stats.hp -= enemyDamage;
    
    std::cout << enemy.name << " attaked: " << player.name
              << "for: " << enemyDamage << " points of damage.\n";
              
    if (player.stats.hp <= 0)
    {
        std::cout << "Player: " << player.name << "| has been defeated\n";
    }
    
}