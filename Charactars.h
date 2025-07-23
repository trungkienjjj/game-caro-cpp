#pragma once
#include "ConsoleFoundation.h"
#include "Decorate.h"
#include "MenuGame.h"
#include "Charactars.h"
#include "Textfile.h"
const int MAX_CHOICE_SUB = 3;
const int CENTER_X = 5;
const int CENTER_Y = 10;
void InFIle();
void InFIle1(const char* f_name, int x, int y, int color);
void InFIle1N(const char* f_name, int x, int y, int color, int time);
void InFIle3(const char* namefile, int x, int y, int time, int color1, int color2);

void ClearAndSetColor();
void PrintCharacterOptions();
void DisplayStatus1();
void DisplayStatus(int percentage, int loadingBarWidth, int loadingBarHeight, int x, int y, int color, string status);
void XulyDisplayStatus(int hp, int attack, int defense, int atk, int speed, string types, string abilities, string tier, int color);
void DisplayCharacter(int choice);

void Character(int& currentChoice_sub, int& times);
void ScreenVs(int characterX, int characterO);
void XuLyChacracter(int& characterX, int& characterO, int& times, void (*func)(), void (*func1)());
void HienCharacter(int& characterX, int& characterO, const char*& characterXFile, const char*& characterOFile);