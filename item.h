#ifndef ITEM_H
#define ITEM_H
#include <string>
struct Item
{
    std::string name;
    int strenght;
    int defense;
    int speed;
    std::string type;

    Item(std::string na, int st, int df, int sp, std::string tp)
    : name(na), strenght(st), defense (df), speed(sp), type(tp) {}
};
#endif