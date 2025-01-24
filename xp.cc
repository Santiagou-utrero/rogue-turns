#include <iostream>
#include <fstream>
#include <string>
#include "xp.h"
#include "player.h"

void show_message(int level){
    std::cout <<"\ncongrats, you level up to level: " << level << "\n";

}

void level_up (xp_logic& xpData, int xpGain){
    xpData.xp += xpGain;

    if (xpData.xp >= xpData.xpToLevelUp)
    {
        xpData.xp -= xpData.xpToLevelUp;
        xpData.level++;
        xpData.xpToLevelUp += (xpData.xpToLevelUp / 2);

        show_message(xpData.level);
    }
    std::cout << "New xp to level up: " << xpData.xpToLevelUp << " | actual level: " << xpData.level << std::endl;
}