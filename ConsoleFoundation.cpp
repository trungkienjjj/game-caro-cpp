#include "ConsoleFoundation.h"

// H�m nh�m view
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
Gi?i th�ch h�m FixConsoleWindow:
1. D?ng �?u, ta khai b�o h�m FixConsoleWindow v?i ki?u tr? v? l� void v� ko c� tham s? truy?n v�o
2. D?ng th? hai, ta s? s? d?ng h�m GetConsoleWindow() �? l?y CON TR? consoleWindow c� ki?u d? li?u HWND (Handle to Windows) �?n c?a s? hi?n t?i.
   <Ki?u HWND ��?c s? d?ng �? �?i di?n cho c?a s? console trong window)
3. ? d?ng th? ba, c� th? hi?u style l� bi?n l�u tr? c�c th�ng tin c?a c?a s?(c�c c? v� c�c h?ng s? �?i di?n cho c?a s? hi?n th?), ta s? d?ng
h�m GetWindowLong v?i hai tham s? l� consoleWindow v� GWL_STYLE
<GWL_STYLE l� h?ng s? s? d?ng trong Windows AOI �? ch? �?nh lo?i th�ng tin ta mu?n l?y ho�c thi?t l?p cho c?a s?>
4. D?ng th? t� ngh?a l� ta s? x�a �i c�c c? WS_MAXIMIZEBOX v� WS_THICKFRAME kh?i bi?n style, vi?c n�y gi�p lo?i b? vi?c ng�?i d�ng k�o gi?n m�n h?nh console d?n �?n v? m�n h?nh.
5. D?ng th? n�m ngh?a l� ta set l?i c?a s? console theo nh?ng th�ng tin ta �? �?nh ? trc ��.





*/
void GotoXY(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
/*
Gi?i th�ch h�m GotoXY
Ta s? d?ng c?u tr�c d? li?u COORD - m?t ki?u d? li?u trong l?p tr?nh Windows ��?c s? d?ng �?
�?i di?n cho m?t c?p t?a �? hai chi?u,bao g?m t?a �? X (ngang) v� t?a �? Y (d?c).
Ta g�n ho�nh v� tung �? cho bi?n coord r?i thi?t l?p v? tr� l�n m�n h?nh b?ng h�m SetConsoleCursorPosition
Khi ��, n?u ta g?i h�m GotoXY v?i c�c tham s? x v� y, n� s? di chuy?n con tr? �?n v? tr� ��?c ch? �?nh b?i x v� y tr�n
c?a s? console.

*/

// H�m kh?i t?o d? li?u m?c �?nh ban �?u cho ma tr?n b�n c?
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