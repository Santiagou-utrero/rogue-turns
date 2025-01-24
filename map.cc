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
#include <thread>
#include <chrono>

const char enemyPixel = 'E';
const char playerPixel = 'P';
const char treasurePixel = 'T';
const char bossPixel = 'B';


const std::string RESET = "\033[0m";
const std::string GREEN = "\033[32m";
const std::string RED = "\033[31m";
const std::string YELLOW = "\033[33m";
const std::string PURPLE = "\033[35m";

void clearConsole(){
    std::cout << "\033[2J\033[1;1H";
}


void generateMap(std::vector<std::vector<char>>& map, int rows, int cols){
    for (int i = 0; i < rows; i++)
    {
        std::vector<char> row;
        for (int j = 0; j < cols; j++)
        {
            
            int random = rand () % 100;
            if (random < 45) row.push_back('1');
            else if (random < 50) row.push_back('2');
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
            }else{
                cell = '.';
            }
            
        }
        
        map.push_back(row);
    } 

    int playerX = rand() % rows;
    int playerY = rand() % cols;
    map[playerX][playerY] = playerPixel;

    int bossX = rand() % rows;
    int bossY = rand() % cols;
    map[bossX][bossY] = bossPixel;

}

void printMap(std::vector<std::vector<char>>& map){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    clearConsole();
    for (const auto&row : map)
    {
        for (auto& cell : row)
        {

            if (cell == playerPixel)
            {
                std::cout << GREEN << cell << RESET << " ";
            }else if (cell == enemyPixel)
            {
                std::cout << RED << cell << RESET << " ";
            } else if (cell == treasurePixel)
            {
                std::cout << YELLOW << cell << RESET << " ";
            }else if (cell == bossPixel)
            {
                std::cout << PURPLE << cell << PURPLE << " ";
            } 
            else{
                std::cout << cell << " ";
            }

        }
        std::cout << "\n";
    }
    
}

void movePlayer(Player& player,std::vector<std::vector<char>>& map){
    int rows = map.size();
    int cols = map[0].size();
    int playerX = 0, playerY = 0;

    //ubicar al jugador

    for ( int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (map[i][j] == playerPixel)
            {
               playerX = i;
               playerY = j;
               break;
            }
        }
    }
    //move the player

    bool playing = true;
    while (playing)
    {
        std::cout << "Use WASD to move: \n";
        char move;
        std::cin >> move;

        int newX = playerX;
        int newY = playerY;

        switch (move)
        {
        case 'w':
            newX--;
            break;
        case 's':
            newX++;
            break;
        case 'a':
            newY--;
            break;
        case 'd':
            newY++;
            break;
        default:
            std::cout << "invalid move. Use W, A, S, or D. \n";
            continue;
        }

        //checkear si hay tope de mapa

        if (newX < 0 || newX >= rows || newY < 0 || newY >= cols)
        {
            std::cout << "You cant move outside the map!\n";
            continue;
        }
        
        char destination = map[newX][newY];

        //interacciones

        if (destination == enemyPixel)
        {
            std::cout << "you encountered a enemy!\n";
            std::vector<Enemies> predefinedEnemies = getPredefinedEnemies();
            Enemies enemy = randomEnemy(predefinedEnemies);
            combatStart(player, enemy);
            if (enemy.stats.hp <= 0)
            {
                map[newX][newY] = '.';
                dropItems(player);
            }
            if (player.stats.hp <= 0)
                {
                    std::cout << "nice try\n";
                    playing = false;
                }
        }

        else if (destination == bossPixel)
            {
                std::cout << "you encounter a boss!\n";
                std::vector<Enemies> predefinedEnemies = getPredefinedEnemies();
                int bossIndex = rand () % 3;
                Enemies boss = predefinedEnemies[predefinedEnemies.size() - 3 + bossIndex];
                combatStart(player,boss);

                if (boss.stats.hp <= 0)
                {
                    map[newX][newY] = '.';
                    dropItems(player);
                }

                if (player.stats.hp <= 0)
                {
                    std::cout << "nice try\n";
                    playing = false;
                }
                
                
            }

        else if (destination == treasurePixel)
            {
                std::cout << "you encounter a treasure!\n";
                dropItems(player);
                map[newX][newY] = '.';
            }

        else if (destination == '.')
            {
                std::cout << "you moved to an empty space\n";
            }

        else{
            std::cout << "invalid destination\n";
            continue;
        }
    
        //update de la posicion del jugador
        map[playerX][playerY] = '.';
        map[newX][newY] = playerPixel;
        playerX = newX;
        playerY = newY;


        
        printMap(map);
    }
    
}