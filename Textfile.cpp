#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <thread>
#include <chrono>
#include <vector>
#include <cmath>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include"Textfile.h"
#include "PlayervsPlayer.h"
#include "Charactars.h"
using namespace std;


// Hàm để tạo hiệu ứng đi lên và xuống
std::string applyVerticalMotion(const std::string& frame, int frameIndex, float n) {
    int motion = static_cast<int>((std::sin(frameIndex / n) + 1) * int(n)); // Tạo hiệu ứng di chuyển mượt mà
    return std::string(motion, '\n') + frame;
}

const std::vector<int> COLORS = {
 
 Blue	,    
 Green	,   
 Red      ,	
 Violet   
};

void Textdecorate(std::string filename, float vertical, int times, int sleep) {
    std::string line;
    std::ifstream file(filename);
    std::vector<std::string> frames;
    int frameIndex = 0;

    if (file.is_open()) {
        while (getline(file, line)) {
            if (line == "###") {
                frames.push_back("");
                continue;
            }
            if (!frames.empty()) {
                frames.back() += line + "\n";
            }
        }
        file.close();
    }
    else {
        std::cout << "Can not open file!" << std::endl;
        return;
    }

    while (times) {
        system("color F0");
        times--;
        system("cls");
        std::string frame = frames[frameIndex % frames.size()];
        frame = applyVerticalMotion(frame, frameIndex, vertical); // Áp dụng hiệu ứng di chuyển
        int color = COLORS[frameIndex % COLORS.size()]; // Lấy màu sắc hiện tại

        Textcolor(color); // Sử dụng hàm Textcolor để đặt màu chữ
        std::cout << frame;
        Textcolor(Black); 

        std::this_thread::sleep_for(std::chrono::milliseconds(sleep));
        frameIndex++;
    }
}

void In_Tep(const char* FileName,int Color) {
    FILE* file;

    if (fopen_s(&file, FileName, "r") != 0) {
        cout << "Khong the mo tep" << endl;
        return;
    }
    char buffer[1000];
    char line[1000];
    int i = 0;
    while (fgets(line, sizeof(line), file)) {
        if (strstr(line, "^")) {
            
                Textcolor(Red);
                cout << line;

        }
        else if (strstr(line, ".")) {
            Textcolor(Green);
            cout << line; 
        }
        else if (strstr(line, "*")) {
            Textcolor(Blue);
            cout << line;
        }
        else {
            Textcolor(Black);
            cout << line;
        }
    }

    fclose(file);
}
void DRAW() {
    playSound(5);
    Textdecorate("DRAW.txt", 3.0, 10, 175);
}
void COMPUTERWIN() {
    playSound(4);
    Textdecorate("BOTWIN.txt", 3.0, 10, 175);
}
void YOUWIN() {
    playSound(4);
    Textdecorate("YOUWIN.txt", 3.0, 10, 175);
}
void CARO1() {
    Textdecorate("CARO.txt", 2.0, 6, 175);
    system("cls");
}

void WINO() {
    playSound(4);
    Textdecorate("OWIN.txt", 5.0, 7, 250);

}
void WINX() {
    playSound(4);
    Textdecorate("XWIN.txt", 5.0, 7, 250);

}
void PrintCaro()
{
    CARO1();

}
void LoadHumansBar() {
    playSound(11);
    Textdecorate("LOADHUMANSBAR.txt", 0.5, 5, 200);
}

void LoadBotBar() {
    playSound(11);
    Textdecorate("LOADBOTBAR.txt",0.5,5,200);
}
void PVPBAR() {
    playSound(11);
    Textdecorate("PlayerVsPlayer.txt", 0.5, 3, 300);
}
void PVCBAR() {
    playSound(11);
    Textdecorate("PVSC.txt", 0.5, 3, 300);
}
void LoadHumans() {
    playSound(12);
    InFIle1N("LOADBOT.txt", 14, 43, Red, 0);
}

void LoadBot() {
   // In_Tep("LOADHUMANS.txt", Blue);
    playSound(12);
    InFIle1N("LOADHUMANS.txt", 14,43, Red, 0);
}

