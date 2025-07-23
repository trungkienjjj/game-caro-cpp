#include "ConsoleFoundation.h"

// Hàm nhóm view
void setConsoleWindow(int w, int h)
{
    HWND console = GetConsoleWindow();
    RECT r;
    GetWindowRect(console, &r);

    MoveWindow(console, r.left, r.top, w, h, TRUE);
}
void FixConsoleWindow() {
    HWND consoleWindow = GetConsoleWindow();
    LONG style = GetWindowLong(consoleWindow, GWL_STYLE);
    style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
    SetWindowLong(consoleWindow, GWL_STYLE, style);
}
/*
Gi?i thích hàm FixConsoleWindow:
1. D?ng ð?u, ta khai báo hàm FixConsoleWindow v?i ki?u tr? v? là void và ko có tham s? truy?n vào
2. D?ng th? hai, ta s? s? d?ng hàm GetConsoleWindow() ð? l?y CON TR? consoleWindow có ki?u d? li?u HWND (Handle to Windows) ð?n c?a s? hi?n t?i.
   <Ki?u HWND ðý?c s? d?ng ð? ð?i di?n cho c?a s? console trong window)
3. ? d?ng th? ba, có th? hi?u style là bi?n lýu tr? các thông tin c?a c?a s?(các c? và các h?ng s? ð?i di?n cho c?a s? hi?n th?), ta s? d?ng
hàm GetWindowLong v?i hai tham s? là consoleWindow và GWL_STYLE
<GWL_STYLE là h?ng s? s? d?ng trong Windows AOI ð? ch? ð?nh lo?i thông tin ta mu?n l?y hoãc thi?t l?p cho c?a s?>
4. D?ng th? tý ngh?a là ta s? xóa ði các c? WS_MAXIMIZEBOX và WS_THICKFRAME kh?i bi?n style, vi?c này giúp lo?i b? vi?c ngý?i dùng kéo gi?n màn h?nh console d?n ð?n v? màn h?nh.
5. D?ng th? nãm ngh?a là ta set l?i c?a s? console theo nh?ng thông tin ta ð? ð?nh ? trc ðó.





*/
void GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*
Gi?i thích hàm GotoXY
Ta s? d?ng c?u trúc d? li?u COORD - m?t ki?u d? li?u trong l?p tr?nh Windows ðý?c s? d?ng ð?
ð?i di?n cho m?t c?p t?a ð? hai chi?u,bao g?m t?a ð? X (ngang) và t?a ð? Y (d?c).
Ta gán hoành và tung ð? cho bi?n coord r?i thi?t l?p v? trí lên màn h?nh b?ng hàm SetConsoleCursorPosition
Khi ðó, n?u ta g?i hàm GotoXY v?i các tham s? x và y, nó s? di chuy?n con tr? ð?n v? trí ðý?c ch? ð?nh b?i x và y trên
c?a s? console.

*/

// Hàm kh?i t?o d? li?u m?c ð?nh ban ð?u cho ma tr?n bàn c?
void AnTroChuot()
{
    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = FALSE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void HienTroChuot()
{

    CONSOLE_CURSOR_INFO Info;
    Info.bVisible = TRUE;
    Info.dwSize = 20;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
    Textcolor(Green);


}
void Textcolor(int color)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, color);
}