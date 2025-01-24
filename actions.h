#ifndef ACTIONS_H
#define ACTIONS_H

#include  <iostream>
#include "player.h"
#include "items.h"
#include "enemies.h"


void attack(Player& player, Enemies& enemy);
void defense(Player& player);
bool consumeItem(Player& player, std::string& itemName);
void enemyAttack(Enemies& enemy, Player& player);


#endif