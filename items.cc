#include <iostream>
#include <vector>
#include "item.h"
#include "player.h"
#include "items.h"
#include <random>


std::vector<Item> getPredefinedItems(){
    return{
        Item("Club", 10, 0, -2, "weapon", false),
        Item("Ninja Mask", 2, 4, 3, "armor", false),
        Item("Short Sword", 5, 0, 0, "weapon", false),
        Item("Dagger", 3, -2, 2, "weapon", false),
        Item("Archer clothes", 0, 10, 3, "armor", false),
        Item("Big Hammer", 20, 0, -7, "weapon", false),
        Item("Simple Boots", 0, 3, 2, "armor", false),
        Item("Life potion", 20, 0, 0, "consumable", true),
        Item("Speed potion", 0, 0, 3, "consumable", true),
    };
}

void dropItems (Player& player){
    auto items = getPredefinedItems();

        //numero random para hacer un 50/50 de que te toque item o no
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, 1);
        int random = dis(gen);

    if (!items.empty() && random == 1)
    {
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(0, items.size() -1);

        int randomIndex = dis(gen);
        Item droppedItem = items[randomIndex];

        player.addItem(droppedItem);
        std::cout << "Random item dropped: " << droppedItem.name << "\n";
    } else{
        std::cout << "no items available for drop\n";
    }
}