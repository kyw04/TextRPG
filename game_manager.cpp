#include "./Header/GameManager.hpp"

GameManager::GameManager()
{
    std::cout << "<<입력으로 게임 시작>>";
    char input;
    INPUT_KEY(input);

    player = SelectPlayer();
}

Entity* GameManager::SelectPlayer()
{
    std::vector<Entity*> players = { new Warrior(), new Archer(), new Wizard() };
    char input = 'N';
    int index = 0;
    for (auto iter = players.begin(); iter != players.end(); iter++)
    {
        if (iter - players.begin() == index)
            std::cout << "<<" << (*iter)->name << ">>\n";
        else
            std::cout << (*iter)->name << '\n';
    }

    std::vector<Entity*>::iterator iter;
    while (input)
    {
        INPUT_KEY(input);
        if (IF_UP_KEY(input)) { index--; }
        if (IF_DOWN_KEY(input)) { index++; }
        if (index < 0) { index = (int)players.size() - 1; }
        index %= (int)players.size();
        for (iter = players.begin(); iter != players.end(); iter++)
        {
            if (iter - players.begin() == index)
                std::cout << "<<" << (*iter)->name << ">>\n";
            else
                std::cout << (*iter)->name << '\n';
        }
    }

    return *iter;
}