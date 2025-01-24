#include <iostream>
#include <string>
#include "turns.h"
#include "actions.h"
#include "player.h"
#include <limits>
#include "xp.h"


void combatStart(Player& player, Enemies& enemy){
    bool onCombat = true;

    if (player.stats.speed >= enemy.stats.speed)
        {
            std::cout << "The speed of: " << player.name << " wins\n";
            attack(player, enemy);
        }else{
            std::cout << "Enemy turn\n";
            enemyAttack(enemy, player);
        }

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

            std::cout << "Your consumable items:\n";
            for (auto i = player.inventory.begin(); i != player.inventory.end(); i++)
            {
                if (i->isConsumable)
                {
                   std::cout << i->name << ", ";
                }
            }

            std::string itemName;
            std::cout << "What item do you want to consume?\n";
            std::cin.ignore();
            std::getline(std::cin, itemName);
            
            consumeItem(player, itemName);


            if (std::cin.fail())
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
            break;
        }
        default:
            std::cout << "invalid option\n";
            continue;
        }


        if (enemy.stats.hp <= 0)
        {
            std::cout << "\n You slayed the enemy\n";
            level_up(player.xp, 200);
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