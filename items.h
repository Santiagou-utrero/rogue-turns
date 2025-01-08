#ifndef ITEMS_H
#define ITEMS_H

#include <vector>
#include "item.h"

std::vector<Item> getPredefinedItems();
void dropItems (Player& player);

#endif // ITEMS_H