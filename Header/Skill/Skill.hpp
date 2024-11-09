#pragma once
#include <ostream>

class Skill
{
private:
    std::function<float()> effect;
    std::string name;

public:
    friend std::ostream& operator<<(std::ostream& _out, const Skill& _skill) { std::cout << _skill.name; return _out; }
    void operator=(Skill& _skill) { this->name = _skill.name; this->effect = _skill.effect; }

    Skill(std::string _name,  std::function<float()> _effect) : name(_name), effect(_effect) {}
};