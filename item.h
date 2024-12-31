#ifndef ITEM_H
#define ITEM_H
#include <string>
struct Item
{
    std::string name;
    int strenght;
    int defense;
    int speed;

    Item(std::string na, int st, int df, int sp)
    : name(na), strenght(st), defense (df), speed(sp) {}
};
#endif