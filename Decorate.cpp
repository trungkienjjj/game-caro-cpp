#include "Decorate.h"
#include "Sound.h"
#include "ConsoleFoundation.h"
#include "Textfile.h"
#include <algorithm> // Include for std::replace

// Color definitions
#define Red       244
#define White     15
#define defaultColor 7

void DrawHorizontalLine(int x, int y, int length, char character) {
    system("Color F6");
    for (int i = 0; i <= length; i++) {
        GotoXY(x + LEFT + i, y);
        cout << character;
    }
}

void DrawVerticalLine(int x, int y, int length, char character) {
    system("Color F6");
    for (int i = 0; i <= length; i++) {
        GotoXY(x + LEFT, y + i);
        cout << character;
    }
}

void DrawText(int x, int y, const string& text, int color) {
    Textcolor(color);
    GotoXY(x + LEFT, y);
    cout << text;
}

void KhungGiaoDien() {
    system("Color F6");

    Textcolor(245);
    DrawVerticalLine(60, 0, 28, char(186)); // Vẽ cột bên trái
    DrawHorizontalLine(61, 1, 58, char(205)); // Vẽ hàng trên cùng
    DrawVerticalLine(120, 0, 28, char(186)); // Vẽ cột bên phải

    DrawText(87, 1, " TI SO ", 246);
    DrawText(70, 3, "PLAYER X                         PLAYER O", 240);
    DrawText(65, 4, "Name                             Name", 245);

    DrawVerticalLine(90, 2, 8, char(186)); // Vẽ cột phân chia giữa 2 người chơi
    DrawHorizontalLine(61, 10, 58, char(205)); // Vẽ hàng giữa
  
    DrawText(86, 10, " LUOT DI ", 246);

    DrawHorizontalLine(61, 20, 58, char(205)); // Vẽ hàng giữa dưới cùng
  //DrawHorizontalLine(LEFT, 29, 120, char(205)); // Vẽ hàng dưới cùng
    DrawHorizontalLine(LEFT-13,29, 120, char(205)); // Vẽ hàng dưới cùng

    DrawText(85, 20, " HUONG DAN ", 246);
    DrawText(74, 23, "W : " + string(1, char(30)) + "    S : " + string(1, char(31)) +
        "    D : " + string(1, char(16)) + "    A : " + string(1, char(17)), 241);

    DrawText(74, 25, "Enter : Chon vi tri danh X hoac O", 240);
    DrawText(74, 27, "ESC : Nhan de thoat", 240);
}
void DrawBoardAbout(int p1Size, int pSize, float Left, float Top) {
    //system("color 70");

    GotoXY(Left, Top);
    printf_s("%c", 218);
    printf_s("%c%c%c", 196, 196, 196);
    GotoXY(Left + 4 * p1Size, Top);
    printf_s("%c", 191);
    for (int i = 1; i < p1Size; i++) {

        GotoXY(Left + 4 * i, Top);
        printf_s("%c%c%c%c", 196, 196, 196, 196);
    }
    GotoXY(Left + 4 * p1Size, Top);
    printf_s("%c", 191);
    printf_s("\n");
    for (int j = 1; j < 2 * pSize; j++) {
        GotoXY(Left, Top + j);
        printf_s("%c", 179);


    }
    GotoXY(Left, Top + 2 * pSize);
    printf_s("%c", 192);
    printf_s("%c%c%c", 196, 196, 196);
    GotoXY(Left + 4 * p1Size, Top + 2 * pSize);
    printf_s("%c", 217);

    for (int i = 1; i < p1Size; i++) {

        GotoXY(Left + 4 * i, Top + 2 * pSize);
        printf_s("%c%c%c%c", 196, 196, 196, 196);
    }
    for (int j = 1; j < 2 * pSize; j++) {
        GotoXY(Left + 4 * p1Size, Top + j);
        printf_s("%c", 179);

    }
    GotoXY(Left, Top + 2 * pSize);
    cout << (char)192;
    for (int i = 1; i < pSize; i++) {

        GotoXY(Left + 4 * i, Top + 2 * pSize);
        printf_s("%c%c%c%c", 196, 196, 196, 196);
    }
    GotoXY(Left + 4 * p1Size, Top + 2 * pSize);
    cout << (char)217;
    //  system("color F0");
}





void LOGOTEAMFound(int x,int y , int CL1,int CL2) {
    Textcolor(CL1);
    GotoXY(x, y); cout << "  _______________    __  ___   ___ ";
    Textcolor(CL2);
    GotoXY(x, y+1); cout << " /_  __/ ____/   |  /  |/  /  <  /  ";
    Textcolor(CL1);
    GotoXY(x, y+2); cout << "  / / / __/ / /| | / /|_/ /   / /   ";
    Textcolor(CL2);
    GotoXY(x, y+3); cout << " / / / /___/ ___ |/ /  / /   / /    ";
    Textcolor(CL1);
    GotoXY(x, y+4); cout << "/_/ /_____/_/  |_/_/  /_/   /_/    ";
    Textcolor(CL2);
    GotoXY(x, y + 4); cout << "  ";
    GotoXY(x, y + 4); cout << "  ";
    GotoXY(x, y + 4); cout << "";
}
void LOGOTEAM1() {
    LOGOTEAMFound(60, 1, Red, Blue);
}
void LOGOTEAM2() {
    LOGOTEAMFound(60, 1, Blue, Red);
}
void Logo(int n)
{
    int check = 0;
    while (check < n)
    {
        LOGOTEAM1();
        Sleep(100);
        LOGOTEAM2();
        Sleep(100);
        check++;
    }
}


void X_decorate(int x, int y,int CL)
{
    Textcolor(CL);
    GotoXY(x, y)  ;  cout << "xxx         xxx " << endl;
    GotoXY(x, y+1);  cout << "  xxx     xxx   " << endl;
    GotoXY(x, y+2);  cout << "    xxx xxx     " << endl;
    GotoXY(x, y+3);  cout << "      xxx       " << endl;
    GotoXY(x, y+4);  cout << "    xxx xxx     " << endl;
    GotoXY(x, y+5);  cout << "  xxx     xxx   " << endl;
    GotoXY(x, y+6);  cout << "xxx         xxx " << endl;
    GotoXY(x, y+7);  cout << endl;
    GotoXY(x, y+8);  cout << endl;
    Textcolor(Black);
}

void O_decorate(int x, int y,int CL)
{
    Textcolor(CL);
    GotoXY(x, y);   cout << "   000000000    " << endl;
    GotoXY(x, y+1); cout << " 000       000  " << endl;
    GotoXY(x, y+2); cout << "000         000 " << endl;
    GotoXY(x, y+3); cout << "000         000 " << endl;
    GotoXY(x, y+4); cout << "000         000 " << endl;
    GotoXY(x, y+5); cout << " 000       000  " << endl;
    GotoXY(x, y+6); cout << "   000000000    " << endl;
    GotoXY(x, y + 7);  cout << endl;
    GotoXY(x, y + 8);  cout << endl;
    Textcolor(Black);
}

void Oturn()
{
    O_decorate(70+LEFT, 12,Blue);
    X_decorate(100 + LEFT, 12, Black);
}
void Xturn()
{
    X_decorate(100+LEFT, 12,Red);
    O_decorate(70 + LEFT, 12, Black);
}



void PrintCaroFound(int CL1, int CL2 , int CL3 ,int CL4)
{
    int x = 45, y = 0;
    
    Textcolor(CL1);
    GotoXY(x, y);				   cout << "ooooooooooooo";
    GotoXY(x - 3, y + 1);			cout << "oooooooooooooooo";
    GotoXY(x - 5, y + 2);    cout << "oooooooooooooooooo";
    GotoXY(x - 6, y + 3);   cout << "ooooooooooooooooooo";
    GotoXY(x - 7, y + 4);  cout << "ooooooo";
    GotoXY(x - 8, y + 5); cout << "ooooooo";
    GotoXY(x - 8, y + 6); cout << "ooooooo";
    GotoXY(x - 8, y + 7); cout << "ooooooo";
    GotoXY(x - 8, y + 8); cout << "ooooooo";
    GotoXY(x - 8, y + 9); cout << "ooooooo";
    GotoXY(x - 8, y + 10); cout << "ooooooo";
    GotoXY(x - 7, y + 11); cout << "ooooooo";
    GotoXY(x - 6, y + 12);  cout << "ooooooooooooooooooo";
    GotoXY(x - 5, y + 13);   cout << "oooooooooooooooooo";
    GotoXY(x - 3, y + 14);		cout << "oooooooooooooooo";
    GotoXY(x, y + 15);			   cout << "ooooooooooooo";
    Textcolor(CL2);
    GotoXY(x - 4 + 22, y + 4);				    cout << "ooooooooooo";
    GotoXY(x - 4 + 22 - 2, y + 5);		      cout << "ooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 6);		     cout << "ooooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 7);			 cout << "ooooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 8);			 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 9);			 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 10);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 11);		 cout << "ooooooooooooooooo";
    GotoXY(x - 4 + 22 - 3, y + 12);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 13);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 14);		 cout << "oooooo     oooooo";
    GotoXY(x - 4 + 22 - 3, y + 15);		 cout << "oooooo     oooooo";
    Textcolor(CL3);
    GotoXY(x + 33, y + 4);			cout << "ooooo   ooooooooo";
    GotoXY(x + 33, y + 5);			cout << "oooooooooooooooooo";
    GotoXY(x + 33, y + 6);			cout << "ooooooooooooooooooo";
    GotoXY(x + 33, y + 7);			cout << "oooooooooooooooooooo";
    GotoXY(x + 1 + 33, y + 8);			 cout << "ooooooo     ooooooo";
    GotoXY(x + 1 + 33, y + 9);			 cout << "ooooooo     ooooooo";
    GotoXY(x + 1 + 33, y + 10);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 11);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 12);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 13);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 14);		 cout << "ooooooo";
    GotoXY(x + 1 + 33, y + 15);		 cout << "ooooooo";
    Textcolor(CL4);
    GotoXY(x + 57, y + 4);					cout << "ooooooooooo";
    GotoXY(x + 57 - 2, y + 5);			  cout << "ooooooooooooooo";
    GotoXY(x + 57 - 3, y + 6);			 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 3, y + 7);			 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 3, y + 8);			 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 9);			 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 10);		 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 11);		 cout << "oooooo     oooooo";
    GotoXY(x + 57 - 3, y + 12);		 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 3, y + 13);		 cout << "ooooooooooooooooo";
    GotoXY(x + 57 - 2, y + 14);		  cout << "ooooooooooooooo";
    GotoXY(x + 57, y + 15);				cout << "ooooooooooo";
    Textcolor(defaultColor);

}

void PrintCaroFound2(int CL1, int CL2, int CL3, int CL4)
{
    int x =0, y = 0;

    Textcolor(CL1);
    GotoXY(x, y);				   cout << "ooooooooooooo";
    GotoXY(x , y + 1);			cout << "oooooooooooooooo";
    GotoXY(x, y + 2);    cout << "oooooooooooooooooo";
    GotoXY(x, y + 3);   cout << "ooooooooooooooooooo";
    GotoXY(x, y + 4);  cout << "ooooooo";
    GotoXY(x , y + 5); cout << "ooooooo";
    GotoXY(x , y + 6); cout << "ooooooo";
    GotoXY(x , y + 7); cout << "ooooooo";
    GotoXY(x , y + 8); cout << "ooooooo";
    GotoXY(x, y + 9); cout << "ooooooo";
    GotoXY(x , y + 10); cout << "ooooooo";
    GotoXY(x , y + 11); cout << "ooooooo";
    GotoXY(x , y + 12);  cout << "ooooooooooooooooooo";
    GotoXY(x, y + 13);   cout << "oooooooooooooooooo";
    GotoXY(x , y + 14);		cout << "oooooooooooooooo";
    GotoXY(x, y + 15);			   cout << "ooooooooooooo";
    Textcolor(CL2);
    GotoXY(x  , y + 17);				    cout << "ooooooooooo";
    GotoXY(x , y + 18);		      cout << "ooooooooooooooo";
    GotoXY(x , y + 19);		     cout << "ooooooooooooooooo";
    GotoXY(x , y + 20);			 cout << "ooooooooooooooooo";
    GotoXY(x , y + 21);			 cout << "oooooo     oooooo";
    GotoXY(x , y + 22);			 cout << "oooooo     oooooo";
    GotoXY(x, y + 23);		 cout << "oooooo     oooooo";
    GotoXY(x , y + 24);		 cout << "ooooooooooooooooo";
    GotoXY(x , y + 25);		 cout << "oooooo     oooooo";
    GotoXY(x, y + 26);		 cout << "oooooo     oooooo";
    GotoXY(x , y + 27);		 cout << "oooooo     oooooo";
    GotoXY(x , y + 28);		 cout << "oooooo     oooooo";
    Textcolor(CL3);
    GotoXY(x , y + 30);			cout << "ooooo   ooooooooo";
    GotoXY(x , y + 31);			cout << "oooooooooooooooooo";
    GotoXY(x , y + 32);			cout << "ooooooooooooooooooo";
    GotoXY(x , y + 33);			cout << "oooooooooooooooooooo";
    GotoXY(x , y + 34);			 cout << "ooooooo     ooooooo";
    GotoXY(x , y + 35);			 cout << "ooooooo     ooooooo";
    GotoXY(x , y + 36);		 cout << "ooooooo";
    GotoXY(x , y + 37);		 cout << "ooooooo";
    GotoXY(x, y + 38);		 cout << "ooooooo";
    GotoXY(x , y + 39);		 cout << "ooooooo";
    GotoXY(x , y + 40);		 cout << "ooooooo";
    GotoXY(x , y + 41);		 cout << "ooooooo";
    Textcolor(CL4);
    GotoXY(x , y + 43);					cout << "ooooooooooo";
    GotoXY(x , y + 44);			  cout << "ooooooooooooooo";
    GotoXY(x, y + 45);			 cout << "ooooooooooooooooo";
    GotoXY(x, y + 46);			 cout << "ooooooooooooooooo";
    GotoXY(x , y + 47);			 cout << "oooooo     oooooo";
    GotoXY(x , y + 48);			 cout << "oooooo     oooooo";
    GotoXY(x , y + 49);		 cout << "oooooo     oooooo";
    GotoXY(x , y + 50);		 cout << "oooooo     oooooo";
    GotoXY(x , y + 51);		 cout << "ooooooooooooooooo";
    GotoXY(x, y + 52);		 cout << "ooooooooooooooooo";
    GotoXY(x , y + 53);		  cout << "ooooooooooooooo";
    GotoXY(x , y + 54);				cout << "ooooooooooo";
    Textcolor(defaultColor);

}
void PrintCaro2()
{
    PrintCaroFound(Red, Green, Blue, Violet);
}
void PrintCaro3() {
     PrintCaroFound(FullRed, FullGreen, FullBlue, FullAzure);
}
void TrangTri(int n)
{ // in caro trang tri phan dau 
    X_decorate(5, 1,Red);
    Sleep(n);
    O_decorate(5, 10, Blue);
    Sleep(n);
    X_decorate(5, 19, Red);
    //in caro trang tri phan cuoi 
    X_decorate(135, 1, Red);
    Sleep(n);
    O_decorate(135, 10, Blue);
    Sleep(n);
    X_decorate(135, 19, Red);
    //in caro trang tri phan giua
    Sleep(500);
    //giua trai 
     X_decorate(1, 28, Red);
    //giua phai
    O_decorate(140, 28, Blue);
    Sleep(n);
    //giua trai 
    O_decorate(20, 28, Blue);
    //giua phai 
    X_decorate(120, 28, Red);
    Sleep(n);
    //giua trai
    X_decorate(40, 28, Red);
    //giua phai 
    O_decorate(100, 28, Blue);
    Sleep(n);
    //giua trai 
    O_decorate(60, 28, Blue);
    //giua phai 
    X_decorate(80, 28, Red);
    Sleep(n);
    Carofirst(60, 14);
}
void CarofirstFound(int x, int y,int CL1,int CL2) {

    Textcolor(CL1);
    GotoXY(x, y); cout << "  _|_|_|    _|_|    _|_|_|      _|_|  " << endl;
    Sleep(200);
    Textcolor(CL2);
    GotoXY(x, y + 2); cout << " _|        _|    _|  _|    _|  _|    _|       " << endl;
    Sleep(200);
    Textcolor(CL1);
    GotoXY(x, y + 3); cout << " _|        _|_|_|_|  _|_|_|    _|    _|  " << endl;
    Sleep(200);
    Textcolor(CL2);
    GotoXY(x, y + 4); cout << " _|        _|    _|  _|    _|  _|    _|  " << endl;
    Sleep(200);
    Textcolor(CL1);
    GotoXY(x, y + 5); cout << "  _|_|_|  _|    _|  _|    _|    _|_|     " << endl;
}
void Carofirst(int x, int y) {
    CarofirstFound(x, y, Red, Blue);
}

void ask_box(int x, int y, int left, int top) {
    DrawBoardAbout(x, y + 1, left - 1, top - 1);
    for (int i = 0; i < 2 * x; i++) {
        GotoXY(left + 2 * i, top);
        cout << "*";
    }
    for (int i = 0; i < 2 * y; i++) {
        GotoXY(left, top + i);
        cout << "*";
    }
    for (int i = 0; i < 2 * x; i++) {
        GotoXY(left + 2 * i, top + 2 * y);
        cout << "*";
    }
    for (int i = 0; i < 2 * y; i++) {
        GotoXY(left + 2 * (2 * x - 1), top + i);
        cout << "*";
    }
}
void AskName(int i, int color, string a, string b, string &playerX, string &playerO){
    int X = 15;
    int Y = 3;
    int left = 45;
    int top = 5;
    Textcolor(color);
    ask_box(X, Y, left, top);
    Textcolor(Black);
   
    GotoXY(left + 10, top + 1);
    Textcolor(color + 3);
    cout << "------------------------------------" << endl;
    GotoXY(left +11, top + 2);
    Textcolor(color + 1);
    cout << "Please Enter The Name of "<< a << ":" << endl;
    GotoXY(left +10, top + 3);
    Textcolor(color + 3);
    cout << "------------------------------------" << endl;
    GotoXY(left + 10, top + 5);
    Textcolor(color + 3);
    cout << "------------------------------------" << endl;
    poketball1(252);
    InFIle3("XAsk.txt", 5, 1, 1,Red,Blue);
    InFIle3("XAsk.txt", 140, 1, 1,Yellow,Violet);
    InFIle3("XAsk.txt", 5, 23, 1,Green,243);
    InFIle3("XAsk.txt", 140, 23, 1,243,245);
    Textcolor(color + 1);
    GotoXY(left +23, top + 4);
    getline(cin, playerX);
    //cin >> playerX;
    cin.ignore();

    system("cls");
    ask_box(X, Y, left, top);
    Textcolor(Black);
    GotoXY(left + 10, top + 1);
    Textcolor(color + 4);
    cout << "------------------------------------" << endl;
    GotoXY(left + 11, top + 2);
    Textcolor(color + 2);
    cout << "Please Enter The Name of " << b << ":" << endl;
    GotoXY(left + 10, top + 3);
    Textcolor(color + 4);
    cout << "------------------------------------" << endl;
    GotoXY(left + 10, top + 5);
    Textcolor(color + 4);
    cout << "------------------------------------" << endl;
    poketball1(Blue);
    InFIle3("OAsk.txt", 5, 1, 1,Red,Blue);
    InFIle3("OAsk.txt", 138, 1, 1, Yellow, Violet);
    InFIle3("OAsk.txt", 5, 18, 1, Green, 243);
    InFIle3("OAsk.txt", 138, 18, 1, 243, 245);
    Textcolor(color + 1);
    GotoXY(left + 23, top + 4);
    getline(cin, playerO);
    cin.ignore();
  //Sleep(100);
 // system("cls");
}
void Confirm(int x, int y, int color) {
    Textcolor(color);
       GotoXY(x, y); cout << "  _____                                                                         _____  ";
   GotoXY(x, y + 1); cout << " ( ___ )-----------------------------------------------------------------------( ___ ) ";
   GotoXY(x, y + 2); cout << "  |   |                                                                         |   |  ";
   GotoXY(x, y + 3); cout << "  |   |   /$$$$$$   /$$$$$$  /$$   /$$ /$$$$$$$$ /$$$$$$ /$$$$$$$  /$$      /$$ |   |  ";
   GotoXY(x, y + 4); cout << "  |   |  /$$__  $$ /$$__  $$| $$$ | $$| $$_____/|_  $$_/| $$__  $$| $$$    /$$$ |   |  ";
   GotoXY(x, y + 5); cout << "  |   | | $$  `__/| $$  ` $$| $$$$| $$| $$        | $$  | $$  ` $$| $$$$  /$$$$ |   |  ";
   GotoXY(x, y + 6); cout << "  |   | | $$      | $$  | $$| $$ $$ $$| $$$$$     | $$  | $$$$$$$/| $$ $$/$$ $$ |   |  ";
   GotoXY(x, y + 7); cout << "  |   | | $$      | $$  | $$| $$  $$$$| $$__/     | $$  | $$__  $$| $$  $$$| $$ |   |  ";
   GotoXY(x, y + 8); cout << "  |   | | $$    $$| $$  | $$| $$`  $$$| $$        | $$  | $$  ` $$| $$`  $ | $$ |   |  ";
   GotoXY(x, y + 9); cout << "  |   | |  $$$$$$/|  $$$$$$/| $$ `  $$| $$       /$$$$$$| $$  | $$| $$ `/  | $$ |   |  ";
  GotoXY(x, y + 10); cout << "  |   |  `______/  `______/ |__/  `__/|__/      |______/|__/  |__/|__/     |__/ |   |  ";
  GotoXY(x, y + 11); cout << "  |___|                                                                         |___|  ";
  GotoXY(x, y + 12); cout << " (_____)-----------------------------------------------------------------------(_____) ";
  GotoXY(x, y + 13); cout << "                                                                                       ";
  Textcolor(Black);
    
}
void ConfirmAnimation(int x, int y,int repeat,int times) {
    playSound(10);
    int colors[] = { 249,250,251,252,253 }; // các màu chữ nền xanh :
     int n = sizeof(colors) / sizeof(colors[0]);
     while (repeat > 0) {
         repeat--;
         for (int i = 0; i < n; i++) {
             Confirm(x, y, colors[i]);
             Sleep(times);

         }
     }
    
}


int poketball1(int color) {
    // Original ASCII art string split into sections
    std::string topSection =
        "\n"
        "\n"
        "                                                                                             \n"
        "                                                                 .###############.\n"
        "                                                            .....-###############-.....\n"
        "                                                           .######+-------------+######-\n"
        "                                                         .+++++++++...-----------++++++++++.\n";
    std::string middleSection =
        "                                                         .###---------------------------###.\n"
        "                                                         .###--.---  -------------------###.\n"
        "                                                       ..-##+--.-  --+++++++++++--------+##-..\n"
        "                                                      -###-----  ---+#########+-----------###-\n"
        "                                                      -###--------+###         +##+--------###-\n"
        "                                                      -###--------+###         +##+--------###-\n";
    std::string bottomSection =
        "                                                      -###############         +##############-\n"
        "                                                      -###############         +##############-\n"
        "                                                      -##+        .###         +##.        +##-\n"
        "                                                      -##+            #########.           +##-\n"
        "                                                      .##+            +########            -##-\n"
        "                                                        .##+                            +##.\n"
        "                                                        .##+                            +##.\n"
        "                                                        .##+                            +##.\n"
        "                                                           .#####+                +#####-\n"
        "                                                           .#####+.              .+#####.\n"
        "                                                                  .###############.\n"
        "                                                                  ...............\n";

    // Replace #, -, and + with \xDB
    std::replace(topSection.begin(), topSection.end(), '#', '\xDB');
    std::replace(topSection.begin(), topSection.end(), '-', '\xDB');
    std::replace(topSection.begin(), topSection.end(), '+', '\xDB');
    std::replace(topSection.begin(), topSection.end(), '.', '\xDB');
    std::replace(middleSection.begin(), middleSection.end(), '#', '\xDB');
    std::replace(middleSection.begin(), middleSection.end(), '-', '\xDB');
    std::replace(middleSection.begin(), middleSection.end(), '+', '\xDB');
    std::replace(middleSection.begin(), middleSection.end(), '.', '\xDB');

    std::replace(bottomSection.begin(), bottomSection.end(), '#', '\xDB');
    std::replace(bottomSection.begin(), bottomSection.end(), '-', '\xDB');
    std::replace(bottomSection.begin(), bottomSection.end(), '+', '\xDB');
    std::replace(bottomSection.begin(), bottomSection.end(), '.', '\xDB');
    // Use the Textcolor function to set colors for the top section
    Textcolor(color);

    std::cout << topSection;

    // Use the Textcolor function to set colors for the middle section
    Textcolor(color);
    std::cout << middleSection;
    // Use the Textcolor function to set colors for the bottom section
    Textcolor(Black);
    std::cout << bottomSection;

    // Reset to default color
    Textcolor(defaultColor);

    return 0;
}