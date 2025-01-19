#include <iostream>
#include <random>
#include <string>
#include <vector>
#include "map.h"
#include "player.h"
#include "enemies.h"
#include "turns.h"
#include "items.h"
#include "map.h"


const char enemyPixel = 'E';
const char playerPixel = 'P';
const char treasurePixel = 'T';


void generateMap(std::vector<std::vector<char>>& map, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        std::vector<char> row;
        for (int j = 0; j < cols; j++)
        {
            int random = rand () % 100;
            if (random < 45) row.push_back('1');
            else if (random < 70) row.push_back('2');
            else row.push_back('0');
        }

        for (auto& cell : row)
        {
            if (cell == '1')
            {
                cell = enemyPixel;
            } else if (cell == '2')
            {
                cell = treasurePixel;
            } else{
                cell = '.';
            }
            
        }
        
        map.push_back(row);
    }
    for (const auto& row : map)
    {
        for (auto& cell : row)
        {
            std::cout << cell << " ";
        }
        std::cout << "\n";
    }
    
}