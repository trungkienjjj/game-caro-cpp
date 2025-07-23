
#include "PlayervsPlayer.h"
#include"Loadingbar.h"
#include"PLAYERVSBOT.h"
#include "Textfile.h"
#include "MenuGame.h"
#include "Charactars.h"

using namespace std;

void Quay() {
    int k = 15;
    for (int i = 0; i < k; i++) {
        Sleep(1000);
        cout << i;
    }
    system("cls");

}
int main() {
 Quay();
#define faster() ios_base :: sync_with_stdio(0);
 cin.tie(NULL); cout.tie(NULL);
  system("color F0");
   SetConsoleCP(437);
    SetConsoleOutputCP(437);    
    setConsoleWindow(1920, 1080);
  FixConsoleWindow();
    int n = 100;
 InFIle3("CAROBAR.txt", 5, 50,70,Red,Blue);
 NewLoadingBar();
  ScreenStartGame(n);
    return 0;
}



