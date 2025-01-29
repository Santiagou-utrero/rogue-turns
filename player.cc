#include <iostream>
#include <string>
#include <vector>
#include "player.h"

Player createPlayer (const std::string &name, const Stats& stats){
    Player player;
    player.name = name;
    player.stats = stats;
    player.xp = {0, 200, 1};
    return player;
}

Player chooseCharacter(){
    Player warrior = createPlayer("Warrior", {100, 15, 10, 0});
    Player thief = createPlayer("Thief", {70, 20, 0, 5});
    Player archer = createPlayer("Archer", {80, 10, 5, 2});
    Player mage = createPlayer("Mage", {60, 25, 0, 0});
    Player uriel = createPlayer("Uriel", {90, 10, 0, 5});
    Player manu = createPlayer("Manu", {140, 5, 30, 0});

    std::cout << "Choose your adventurer: \n";
    std::cout << "1.Warrior: Good HP, DMG, DF but no SPD\n"
              << "2.Thief: Less HP, good DMG and SPD\n"
              << "3.Archer: Less HP, good DMG and good SPD\n"
              << "4.Mage: Less HP, good DMG and no SPD\n"
              << "5.Uriel: Less HP, bad DMG, bad DF but very high SPD\n"
              << "6.Manu: very high HP, high defense, bad DMG and SPD\n";

    int option;
    std::cin >> option;

    switch (option)
    {
    case 1:
        return warrior;
        break;
    case 2:
        return thief;
        break;
    case 3:
        return archer;
        break;
    case 4:
        return mage;
        break;
    case 5:
        return uriel;
        break;
    case 6:
        return manu;
        break;
    default:
        std::cout << "invalid option, choosing warrior as default";
        return warrior;
        break;
    }
}