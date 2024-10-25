#pragma once
#include <vector>
#include "../Stats.h"

class Entity
{
protected:
    // std::vector<Item> items; /* Item 클래스 만들어 */
    bool is_die;

    void virtual Die();

public:
    Stats *stats;

    Entity();
    void TakeDamage(float);
    bool IsDie();
};