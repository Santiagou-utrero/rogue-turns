#ifndef STATS_H
#define STATS_H
#include "item.h"
struct Stats
{
    int hp;
    int strenght;
    int defense;
    int speed;

    void applyItem(Item& item){
        strenght += item.strenght;
        defense += item.defense;
        speed += item.speed;
    }

    void removeItem(Item& item){
        strenght -= item.strenght;
        defense -= item.defense;
        speed -= item.speed;
    }
};

#endif