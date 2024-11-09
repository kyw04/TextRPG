#ifndef _DEFINE_
#define _DEFINE_
#include <string>
#include <istream>

#define INPUT_KEY(_input) { std::string str; getline(std::cin, str); _input = str[0]; }
#define IF_UP_KEY(_input) (_input == 'w' || _input == 'W')
#define IF_DOWN_KEY(_input) (_input == 's' || _input == 'S')
#define IF_CLOSE_KEY(_input) (_input == 'q' || _input == 'Q')
#define IF_INVENTORY_KEY(_input) (_input == 'i' || _input == 'I')

#endif