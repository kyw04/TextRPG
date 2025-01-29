#ifndef _DEFINE_
#define _DEFINE_
#include <string>
#include <istream>
inline char default_input;

#define MAX_LEVEL 100
#define MAX_MAP_SIZE 11

#define MAX_SKILL_COUNT 4

#define INPUT_KEY(_input) { std::string str; getline(std::cin, str); _input = str[0]; }
#define IS_UP_KEY(_input) (_input == 'w' || _input == 'W')
#define IS_DOWN_KEY(_input) (_input == 's' || _input == 'S')
#define IS_LEFT_KEY(_input) (_input == 'a' || _input == 'A')
#define IS_RIGHT_KEY(_input) (_input == 'd' || _input == 'D')
#define IS_CLOSE_KEY(_input) (_input == 'q' || _input == 'Q')
#define IS_INVENTORY_KEY(_input) (_input == 'i' || _input == 'I')

#endif