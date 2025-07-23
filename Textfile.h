#include <fstream>
#include <thread>
#include <chrono>
#include<conio.h>
#include"PlayervsPlayer.h"
#include "Loadingbar.h"
#include "Sound.h"


// Hàm để thay đổi màu sắc theo chu kỳ
std::string getDynamicColor(int frameIndex);
// Hàm để tạo hiệu ứng đi lên và xuống
std::string applyVerticalMotion(const std::string& frame, int frameIndex, float n);
//hàm để tạo hiệu ứng cho textfile
void Textdecorate(std::string filename, float vertical, int times, int sleep);
void  DrawBoardAbout(int pSize, float Left, float Top);
void In_Tep(const char* FileName,int Color);
//Ve khung giao dien 
void KhungGiaoDien();
void CARO1();
void Carofirst(int x,int y);
void LoadGameAnimation();
void WINX();
void LoadHumansBar();
void LoadBotBar();
void PVPBAR();
void PVCBAR();
void LoadHumans();
void LoadBot();
