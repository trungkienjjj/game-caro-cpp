#pragma once

//#include <mmsystem.h>
#include "Textfile.h"
#include "MenuGame.h"
#include "ConsoleFoundation.h"
#include<string.h>
#include "SettingsBox.h"
#include "Charactars.h"
#define RESET_COLOR "\x1b[0m"
using namespace std;
void SaveGame_ESC();
bool checkFile_pvc(string taptin);
void LoadGame(string taptin);

//void XuLyLoadGame();



void On_Of_sound();
// Hàm nhóm view
void FixConsoleWindow();
void setConsoleWindow(int w, int h);
void GotoXY(int x, int y);
// Hằng số
void ResetData();
// Hàm khởi tạo dữ liệu mặc định ban đầu cho ma trận bàn cờ
void ResetData();
// Hàm nhóm view
void DrawBoard();
void Xturn();
void Oturn();
// Hàm nhóm Control
void StartGame(int* dX, int* dY);
void GabageCollect();
void ExitGame();
//Hàm nhóm Model
bool checkWin_pvp(int x, int y, int player, bool ok);
bool isDraw();
int TestBoard();
int CheckBoard(int pX, int pY);
//Hàm di chuyển :
void MoveRight();
void MoveLeft();
void MoveDown();
void MoveUp();
//
void in_nuoc_di();
int ProcessFinish(int pWhoWin, int &countX, int &countO);
void get_locate(int pX, int pY);
//
void play_PvP();
void PlayervsPlayer();
void WINO();
void DRAW();
int AskContinue();
void SaveGame_ESC();
void LoadGame(string taptin);
void ContinueGame();
void AskNamePlayer();
void RedrawBoard();
