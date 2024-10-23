#pragma once
#include <vector>
#include "../Stats.h"

class Entity : public Stats
{
protected:
    // std::vector<Item> items; /* Item 클래스 만들어 */
    bool is_die;

    void virtual Die();

public:
    Entity();
    void TakeDamage(float);
};