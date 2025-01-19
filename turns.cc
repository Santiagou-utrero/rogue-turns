#include <iostream>
#include <string>
#include "turns.h"
#include "actions.h"

void combatStart(Player& player, Enemies& enemy){
    bool onCombat = true;

    while (onCombat)
    {
        std::cout << "Its your turn. What you want to do: \n";
        std::cout << "1- Attack\n";
        std::cout << "2- Defend\n";
        std::cout << "3- Use object\n";

        int choice;
        std::cin >> choice;
        
        switch (choice)
        {
        case 1:
            attack(player, enemy);
            break;
            
        case 2: 
            defense(player);
            break;

        case 3: {
            std::string itemName;
            std::cout << "What item do you want to consume?\n";
            std::cin >> itemName;
            consumeItem(player, itemName);
            break;
        }
        default:
            std::cout << "invalid option\n";
            continue;
        }


        if (enemy.stats.hp <= 0)
        {
            std::cout << "\n You slayed the enemy\n";
            onCombat = false;
            continue;
        }

        std::cout << "Enemy turn\n";
        enemyAttack(enemy, player);

        if (player.stats.hp <= 0)
        {
            std::cout << "\n You have been defeated\n";
            onCombat = false;
        }
    }
}