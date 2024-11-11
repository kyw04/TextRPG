#pragma once
#include <ostream>

class Skill
{
private:
    std::string name;
    std::function<float()> effect;

public:
    friend std::ostream& operator<<(std::ostream& _out, const Skill& _skill) { std::cout << _skill.name; return _out; }

    Skill(const std::string _name = "None",  const std::function<float()> _effect = NULL) : name(_name), effect(_effect) {}
};