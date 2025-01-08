#include <iostream>
#include <vector>
#include "item.h"
#include "player.h"
#include "items.h"
#include <random>


std::vector<Item> getPredefinedItems(){
    return{
        Item("Club", 10, 0, -2, "weapon"),
        Item("Ninnja Mask", 2, 4, 3, "armor"),
        Item("Short Sword", 5, 0, 0, "weapon"),
        Item("Dagger", 3, -2, 2, "weapon"),
        Item("Archer clothes", 0, 10, 3, "armor"),
        Item("Big Hammer", 20, 0, -7, "weapon"),
        Item("Simple Boots", 0, 3, 2, "armor"),
        Item("Life potion", 0, 0, 0, "consumable"),
        Item("Speed potion", 0, 0, 3, "consumable"),
    };
}

void dropItems (Player& player){
    auto items = getPredefinedItems();
    if (!items.empty())
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