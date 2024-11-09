#include <iostream>
#include "./Header/Stats.hpp"
#include "./Header/Entity/Entity.hpp"
#include "./Header/Entity/Warrior.hpp"
#include "./Header/Entity/Zombie.hpp"
#include "./Header/Item/Item.hpp"
#include "./Header/Item/WoodSword.hpp"
#include "./Header/Inventory.hpp"
#include "./Header/Define.hpp"
#include "./Header/Skill/Skill.hpp"

int main()
{
    char input;
    Warrior* warrior = new Warrior();

    int count = 0;
    while (!warrior->IsDie())
    {
        INPUT_KEY(input);

        if (IF_CLOSE_KEY(input))
        {
            std::string str = "";
            for (int i = 0; i < count; i++)
                str += "I";
            Skill skill = {str, []()->float{ return 0.0f; }};

            warrior->AddSkill(skill);
        }
    }
    
    return 0;
}