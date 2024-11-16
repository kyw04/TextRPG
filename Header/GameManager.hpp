#pragma once

class GameManager
{
privaet:
    Entity* player;
    Inventory* inventory;
    Map* map;

    const Entity monster[][] = // enemty[level][enemy] 
    { 
        { new Zombie(), }, // level == 1
        { } // level == 2
    }

public: 

};