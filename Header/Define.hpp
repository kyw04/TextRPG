#ifndef _DEFINE_
#define _DEFINE_
#include <string>
#include <istream>

#ifdef __linux__
    #include <termio.h>

    inline int INPUT_KEY()
    {
        int ch = 0;
        struct termios buff, old;
        tcgetattr(0,&old);

        buff = old;
        buff.c_lflag &= ~(tcflag_t)(ICANON|ECHO); // 캐논 모드(Enter로 입력 받기) 및 에코(화면에 입력 값 표시) 비활성화
        buff.c_cc[VMIN] = 1; // 최소 1 바이트 입력 대기(글자 수)
        buff.c_cc[VTIME] = 200; // 입력 대기 시간 설정

        tcsetattr(0, TCSAFLUSH, &buff);
        ch = getchar();
        tcsetattr(0, TCSAFLUSH, &old);

        return ch;
    }
#endif
#ifdef _WIN32
    #include <cstdio>
    inline int INPUT_KEY()
    {
        return getch();
    }
#endif

inline char default_input;

#define MAX_LEVEL 100
#define MAX_MAP_SIZE 55

#define MAX_SKILL_COUNT 4

// #define INPUT_KEY(_input) { std::string str; getline(std::cin, str); _input = str[0]; }
#define IS_UP_KEY(_input) (_input == 'w' || _input == 'W')
#define IS_DOWN_KEY(_input) (_input == 's' || _input == 'S')
#define IS_LEFT_KEY(_input) (_input == 'a' || _input == 'A')
#define IS_RIGHT_KEY(_input) (_input == 'd' || _input == 'D')
#define IS_CLOSE_KEY(_input) (_input == 'q' || _input == 'Q')
#define IS_INVENTORY_KEY(_input) (_input == 'i' || _input == 'I')
#define IS_ENTER_KEY(_input) (_input == 10)

#endif