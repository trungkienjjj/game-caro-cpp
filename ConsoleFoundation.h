#pragma once
#include <Windows.h>
void setConsoleWindow(int w, int h);
void FixConsoleWindow();
void GotoXY(int x, int y);
void AnTroChuot();
void HienTroChuot();
void Textcolor(int color);
//dinh nghia cac mau co ban : 
#define Black			240
#define Blue		    241
#define Green		    242
#define Red      		244
#define Violet          245
#define Yellow          246
#define SuperBlue       249
#define FullBlue		17
#define BlueYellow		30
#define FullGreen		34
#define FullAzure       51
#define FullRed         68
#define YellowRed       100
#define FullYellow		102
#define Grey		    135
#define GreyBlue	    121
#define MintPink		189
#define defaultColor    7 

#define ColorCode_Back			0
#define ColorCode_DarkBlue		1
#define ColorCode_DarkGreen		2
#define ColorCode_DarkCyan		3
#define ColorCode_DarkRed		4
#define ColorCode_DarkPink		5
#define ColorCode_DarkYellow	6
#define ColorCode_DarkWhite		7
#define ColorCode_Grey			8
#define ColorCode_Blue			9
#define ColorCode_Green			10
#define ColorCode_Cyan			11
#define ColorCode_Red			12
#define ColorCode_Pink			13
#define ColorCode_Yellow		14
#define ColorCode_White			15

#define default_ColorCode		7

