#include <iostream>
#include "./Header/Stats.h"

int main()
{
    Stats stats;
    stats.ShowStats();
    stats.SetExperience(100);
    stats.ShowStats();
    stats.SetExperience(100);
    stats.ShowStats();
    
    return 0;
}