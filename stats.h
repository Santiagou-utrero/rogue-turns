#ifndef STATS_H
#define STATS_H
#include "item.h"
struct Stats
{
    int hp;
    int strenght;
    int defense;
    int speed;

    void applyItem(const Item& item){
        if (item.strenght != 0) strenght += item.strenght;
        if (item.defense != 0) defense += item.defense;
        if (item.speed != 0) speed += item.speed;

    }

    void removeItem(const Item& item){
        if (item.strenght != 0) strenght -= item.strenght;
        if (item.defense != 0) defense -= item.defense;
        if (item.speed != 0) speed -= item.speed;
    }
};

#endif