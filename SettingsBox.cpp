#include "SettingsBox.h"


int AskContinue() {
    //system("color F0");

    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    char s[30] = " ";
    int check = 1;
    int x = 0 + 66, y = TOP + 21;
    //system("color F0");
    DrawBoardAbout(6, 6, 60, 15);
    GotoXY(0 + 65, TOP + 20);
    printf("Nhan 'y/n' de ");
    GotoXY(0 + 65, TOP + 21);
    printf("tiep tuc/dung:");
    Textcolor(Red);
    GotoXY(0 + 66, TOP + 22); cout << "Y:CONTINUE";
    Textcolor(15);
    GotoXY(0 + 66, TOP + 23); cout << "N:EXIT";
    while (check) {
        if (_kbhit()) {
            switch (_getch()) {
            case's':
                if (y > TOP + 22) {
                    y--;
                    GotoXY(x, y);
                }
                if (y == TOP + 22) {
                    Textcolor(Red);
                    GotoXY(0 + 66, TOP + 22); cout << "Y:CONTINUE";
                    Textcolor(7);
                    GotoXY(0 + 66, TOP + 23); cout << "N:EXIT";
                }
                if (y == TOP + 23) {
                    Textcolor(7);
                    GotoXY(0 + 66, TOP + 22); cout << "Y:CONTINUE";
                    Textcolor(Red);
                    GotoXY(0 + 66, TOP + 23); cout << "N:EXIT";

                }
                break;
            case 'w':
                if (y < TOP + 23) {
                    y++;
                    GotoXY(x, y);
                }
                if (y == TOP + 22) {
                    Textcolor(Red);
                    GotoXY(0 + 66, TOP + 22); cout << "Y:CONTINUE";
                    Textcolor(7);
                    GotoXY(0 + 66, TOP + 23); cout << "N:EXIT";
                }
                if (y == TOP + 23) {
                    Textcolor(7);
                    GotoXY(0 + 66, TOP + 22); cout << "Y:CONTINUE";
                    Textcolor(Red);
                    GotoXY(0 + 66, TOP + 23); cout << "N:EXIT";

                }
                break;
            case 13:
                playSound(2);
                if (y == TOP + 22) {
                    system("cls");
                    ScreenStartGame(99);

                }
                if (y == TOP + 23) {
                    system("cls");
                    ContinueGame();

                }
            }

        }
    }


    return toupper(_getch());
}


int AskContinueFound(void (*func1)(), void (*func2)(), void(*func3)()) {
    playSound(15);
    //system("color F0");
    AnTroChuot();
    /*GotoXY(0 + 85, TOP + i + 22);
    DrawBoardAbout(5, 50, 50);
    printf("Nhan 'y/n' de tiep tuc/dung: ");
    return toupper(_getch());*/
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    char s[30] = " ";
    int check = 1;
    int i = - 8 ; 
    int x = 0 + 66, y = TOP + i + 21;
   // DrawBoardAbout(6, 6, 60, 15);
    int a = 8;
    GotoXY(0 + 65, TOP + i + 20);
    Textcolor(203); //203 là xanh nền đỏ 
    GotoXY(0 + 69 - a, TOP + i + 19); cout << "                       ";
    GotoXY(0 + 69 - a, TOP + i + 20); cout << "                       ";
    GotoXY(0 + 65, TOP + i + 20);
    Textcolor(189);
    printf("==BOX SETTING==");
    
    //GotoXY(0 + 65, TOP + i + 21);
    //printf("tiep tuc/dung:");
    Textcolor(203); //203 là xanh nền đỏ 
    GotoXY(0 + 69 - a, TOP + i + 21); cout << "                       ";
    GotoXY(0 + 69 - a, TOP + i + 22); cout << "        CONTINUE       ";
    Textcolor(192);//192 là đen nền đỏ : 
    GotoXY(0 + 69 - a, TOP + i + 23); cout << "        EXIT           ";
    GotoXY(0 + 69 - a, TOP + i + 24); cout << "        SAVE           ";
    GotoXY(0 + 69 - a, TOP + i + 25); cout << "        LOAD           ";
    GotoXY(0 + 69 - a, TOP + i + 26); cout << "                       ";
    
    while (check) {
        if (_kbhit()) {
            
            switch (_getch()) {
            case'w':
                playSound(1);
                if (y > TOP + i + 22) {
                    y--;
                    GotoXY(x, y);
                }
                if (y == TOP + i + 22) {
                    Textcolor(203);
                    GotoXY(0 + 69, TOP + i + 22); cout << "CONTINUE";
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 23); cout << "EXIT";
                    GotoXY(0 + 69, TOP + i + 24); cout << "SAVE";
                    GotoXY(0 + 69, TOP + i + 25); cout << "LOAD";
                }
                if (y == TOP + i + 23) {
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 22); cout << "CONTINUE";
                    Textcolor(203);
                    GotoXY(0 + 69, TOP + i + 23); cout << "EXIT";
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 24); cout << "SAVE";
                    GotoXY(0 + 69, TOP + i + 25); cout << "LOAD";

                }
                if (y == TOP + i + 24) {
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 22); cout << "CONTINUE";
                    GotoXY(0 + 69, TOP + i + 23); cout << "EXIT";
                    Textcolor(203);
                    GotoXY(0 + 69, TOP + i + 24); cout << "SAVE";
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 25); cout << "LOAD";

                }
                if (y == TOP + i + 25) {
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 22); cout << "CONTINUE";
                    GotoXY(0 + 69, TOP + i + 23); cout << "EXIT";
                    GotoXY(0 + 69, TOP + i + 24); cout << "SAVE";
                    Textcolor(203);
                    GotoXY(0 + 69, TOP + i + 25); cout << "LOAD";

                }
                break;
            case 's':
                playSound(1);
                if (y < TOP + i + 25) {
                    y++;
                    GotoXY(x, y);
                }
                if (y == TOP + i + 22) {
                    Textcolor(203);
                    GotoXY(0 + 69, TOP + i + 22); cout << "CONTINUE";
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 23); cout << "EXIT";
                    GotoXY(0 + 69, TOP + i + 24); cout << "SAVE";
                    GotoXY(0 + 69, TOP + i + 25); cout << "LOAD";
                }
                if (y == TOP + i + 23) {
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 22); cout << "CONTINUE";
                    Textcolor(203);
                    GotoXY(0 + 69, TOP + i + 23); cout << "EXIT";
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 24); cout << "SAVE";
                    GotoXY(0 + 69, TOP + i + 25); cout << "LOAD";

                }
                if (y == TOP + i + 24) {
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 22); cout << "CONTINUE";
                    GotoXY(0 + 69, TOP + i + 23); cout << "EXIT";
                    Textcolor(203);
                    GotoXY(0 + 69, TOP + i + 24); cout << "SAVE";
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 25); cout << "LOAD";

                }
                if (y == TOP + i + 25) {
                    Textcolor(192);
                    GotoXY(0 + 69, TOP + i + 22); cout << "CONTINUE";
                    GotoXY(0 + 69, TOP + i + 23); cout << "EXIT";

                    GotoXY(0 + 69, TOP + i + 24); cout << "SAVE";
                    Textcolor(203);
                    GotoXY(0 + 69, TOP + i + 25); cout << "LOAD";

                }
                break;
            case 13:
                playSound(2);
                if (y == TOP + i + 22) {
                    system("cls");
                    //PlayerVsBOT();
                   // ContinueGameBot();
                    func1();
                }
                if (y == TOP + i + 23) {
                    system("cls");

                    ScreenStartGame(99);

                }
                if (y == TOP + i + 24) {
                    func2();
                    //system("cls");
                }
                if (y == TOP + i + 25) {
                    func3();
                }
            }

        }
    }


    return toupper(_getch());
}
void AskcontinuePlayer() {
    AskContinueFound(ContinueGame, SaveGame_ESC, XuLySubMenuLoadGame);
}
void AskcontinueBot() {
    AskContinueFound(ContinueGameBot,SaveGame_ESC_BOT, XuLySubMenuLoadGame);
}