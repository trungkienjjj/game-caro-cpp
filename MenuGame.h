#pragma once
#include "ConsoleFoundation.h"
#include "PlayervsPlayer.h"
#include <vector>
#include <mmsystem.h>
#include "PlayervsPlayer.h"
#include "Loadingbar.h"
#include "Textfile.h"
#include "PLAYERVSBOT.h"
#include "Sound.h"
#include "Decorate.h"
using namespace std;


// Hàm để hiển thị menu chính
void showMenu(int& currentChoice);
// Hàm để hiển thị menu con
void submenu(int& currentChoice_sub, string SubmenuName, string choice1, string choice2, string choice3);
//Hàm Xử lý các lựa chọn của player
void XuLySubMenuFound(string SubmenuName, string choice1, string choice2, string choice3, void (*func1)(), void (*func2)(), void (*func3)(int), void(*Loadgame)());
// Xử lý các tương tác lựu chọn của người chơi với menu chính
void ScreenStartGame(int n);
//Hàm vô dụng 
void Nothing();
//Xứ lý Sub Menu cho chế độ chơi 
void XuLySubMenu();
//Xử lý lựa chọn cho chế độ load 
void XuLySubMenuLoadGame();
// Giao diện/chức năng  khi load game : 
void XuLyLoadGame(int i);
// Xulyloadgame cho người vs người
void XuLyLoadGamePlayer();
// Giao diện loadgame cho người với máy 
void XuLyLoadGameBot();
// List lưu file đã lưu để in ra màn hình list để lưu load file 
void in_currFile();

// Giới thiệu tác giả Nhóm 1 23TNT1
void About();
// Hướng dẫn người chơi cách chơi game caro : 
void Help();