#include <iostream>
#include <conio.h>
#include <windows.h>
#include <vector>
#include "ConsoleFoundation.h"
#include "SettingsBox.h"
#include "Charactars.h"
using namespace std;

#define SIZE 14
#define LEFT 14
#define TOP 0

void gotoxy(int x, int y);
void StartBoard();
bool isDraw();
void DrawBoardBOT();
void printBoard();

bool checkWin(int x, int y, char player,bool ok);
int Danh_gia_nuoc_di(int x, int y);

void Next_Move(bool level);
void play_PvC(bool level);
void PlayerVsBOT();
void COMPUTERWIN();
void YOUWIN();
void DRAW();
int Danh_gia_nuoc_di_ez(int x, int y);

void PlayerVsBOTEASY();
void LoadGameBot(string taptin);
void ContinueGameBot();
void Name_file_bot(const char* s, string& taptin);
void SaveGame_ESC_BOT();
void AskNameBot();