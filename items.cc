#include <iostream>
#include <vector>
#include "item.h"


std::vector<Item> getPredefinedItems(){
    return{
        Item("Garrote", 10, 0, -2),
        Item("Mascara de ninja", 2, 4, 3),
        Item("Espada corta", 5, 0, 0),
        Item("Daga", 3, -2, 2),
        Item("Chaleco de arquero", 0, 10, 3),
        Item("Mazo", 20, 0, -7),
        Item("Botas simples", 0, 3, 2),
    };
}