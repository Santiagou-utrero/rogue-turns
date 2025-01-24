#ifndef XP_H
#define XP_H
struct xp_logic
{
    int xp = 0;
    int xpToLevelUp;
    int level = 1;
};

void show_message(int level);
void level_up (xp_logic& xpData, int xpGain);

#endif