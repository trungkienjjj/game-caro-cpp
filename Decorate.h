#pragma once
#include "ConsoleFoundation.h"
#include <stdio.h>
#include <iostream>
using namespace std; 
#define LEFT 12
#define TOP 0
void KhungGiaoDien();
void DrawBoardAbout(int p1Size, int pSize,float Left, float Top);
void ask_box(int x, int y, int left, int top);
void LOGOTEAMFound(int x, int y, int CL1, int CL2);
void PrintCaroFound2(int CL1, int CL2, int CL3, int CL4);
void LOGOTEAM1();
void LOGOTEAM2();
void Logo(int n);
void Xturn();
void Oturn();
void X_decorate(int x, int y,int CL);
void O_decorate(int x, int y,int CL);
void PrintCaro2();
void PrintCaro3();
void TrangTri(int n);
void Xturn();
void Oturn();
void Carofirst(int x, int y);
void AskName(int i, int color, string a, string b, string& playerX, string& playerO);
void Confirm(int x, int y, int color);
void ConfirmAnimation(int x, int y,  int repeat, int times);
int poketball1(int color);