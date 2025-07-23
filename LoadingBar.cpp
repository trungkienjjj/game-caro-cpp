#include "Loadingbar.h"



void updateLoadingBar(int percentage, int loadingBarWidth, int loadingBarHeight) {


    int filledWidth = (percentage * loadingBarWidth) / 100;

    for (int h = 0; h < loadingBarHeight; h++) {
        GotoXY(30, 20 + h);  // Chỉnh lại vị trí Y cho mỗi dòng
        if (h == 0) {
            cout << "Loading: [";  // Chỉ hiển thị "Loading:" ở dòng đầu tiên
        }
        else {
            cout << "         [";  // Các dòng sau chỉ cần khoảng trống
        }
        // Hiệu ứng gradient: bắt đầu với màu đỏ và dần chuyển sang xanh
        for (int i = 0; i < filledWidth; ++i) {
            // Thay đổi màu dựa trên i
    
            int colorCode = 12 + (2 * (i * 5 / loadingBarWidth)); // Tính toán ví dụ
            Textcolor(colorCode);
            cout << "\xDB"; // Ký tự khối
        }

        // Chuyển sang phần chưa điền
        Textcolor(Grey); // Màu xám cho phần chưa điền
        for (int i = filledWidth; i < loadingBarWidth; ++i) {
            cout << "\xB0"; // Ký tự bóng nhẹ
        }

        // Kết thúc với một góc ]
        Textcolor(Black); // Quay lại màu bình thường
        cout << "] " << (h == 0 ? to_string(percentage) + "%" : ""); // Chỉ hiển thị phần trăm ở dòng đầu tiên
        cout.flush();
    }
}

/**void NewLoadingBar() {
   // system("Color F0");
    Playnn();
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    //CONSOLE_SCREEN_BUFFER_INFO csbi;
    //GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    //int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    //int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    const int loadingBarHeight = 4;
    const int loadingBarWidth = 83; // Tăng kích thước của loading bar
    AnTroChuot();
    // Tính toán vị trí trung tâm
    int centerX = 50;
    int centerY = 20;
    int n = 0;
    //Carofirst(50, 6);
    for (int i = 0; i <= 100; ++i) {
        n++;
        GotoXY(centerX, centerY); // Di chuyển đến vị trí trung tâm
        updateLoadingBar(i, loadingBarWidth, loadingBarHeight);
        this_thread::sleep_for(chrono::milliseconds(1)); // Đợi 100ms
        Textcolor(Red);
        GotoXY(centerX - 10, centerY + 5);
        if (n % 3 == 0) {
            cout << ".........";
        }
        else {
            cout << "         ";
            Sleep(50);
            GotoXY(centerX - 10, centerY + 5);
            cout << "...";
        }
        GotoXY(centerX + 5, centerY + 3);
        if (i > 1 && i < 40)
        {
            cout << "\n\n\t\tCreating Temporary files";

        }
        else if (i > 40 && i < 80)
        {

            cout << "\n\n\t\tAccessing Main Memory   ";
        }
        else if (i > 80 && 1 < 92)
        {

            cout << "\n\n\t\tAccessing Cache        ";
        }


    }
    cout << "\n\n\t\tLoading Complete!";
    Sleep(200);

    system("cls");
    system("Color F0");
    cout << "\n";
    Logo(3);

    GotoXY(60, 8); cout << "WElCOME";
    Sleep(100);
    GotoXY(70, 8); cout << "TO";
    Sleep(100);
    GotoXY(75, 8); cout << "OUR";
    Sleep(100);
    GotoXY(80, 8); cout << "CARO";
    Sleep(100);
    GotoXY(85, 8); cout << "GAME";
    TrangTri(100);

    GotoXY(60, 23);  system("Pause");


}*/
void NewLoadingBar() {
    // system("Color F0");
    
    playSound(6);
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    //CONSOLE_SCREEN_BUFFER_INFO csbi;
    //GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    //int consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    //int consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
    const int loadingBarHeight = 4;
    const int loadingBarWidth = 83; // Tăng kích thước của loading bar
    AnTroChuot();
    // Tính toán vị trí trung tâm
    int centerX = 50;
    int centerY = 20;
    int n = 0;
    //Carofirst(50, 6);
    for (int i = 0; i <= 100; ++i) {
        n++;
        GotoXY(centerX, centerY); // Di chuyển đến vị trí trung tâm
        updateLoadingBar(i, loadingBarWidth, loadingBarHeight);
        this_thread::sleep_for(chrono::milliseconds(0)); // Đợi 100ms
        Textcolor(Red);
        GotoXY(centerX - 10, centerY + 5);
        if (n % 3 == 0) {
            cout << ".........";
        }
        else {
            cout << "         ";
            Sleep(50);
            GotoXY(centerX - 10, centerY + 5);
            cout << "...";
            //InFIle3("Obar.txt", centerX - 10, centerY + 6, 0,Blue,Red);
         
        }

        if (i > 1 && i < 40)
        {
            GotoXY(centerX + 5, centerY + 3);
            cout << "\n\n\t\tCreating Temporary files";
            InFIle3("Obar.txt", centerX - 10, centerY + 6, 0,Blue,Red);
        }
        else if (i > 40 && i < 80)
        {
            GotoXY(centerX + 5, centerY + 3);
            cout << "\n\n\t\tAccessing Main Memory   ";
            InFIle3("Xbar.txt", centerX + 10, centerY + 6, 0,Blue,Red);
        }
        else if (i > 80 && 1 < 92)
        {
            GotoXY(centerX + 5, centerY + 3);
            cout << "\n\n\t\tAccessing Cache        ";
            InFIle3("Obar.txt", centerX + 30, centerY + 6, 0,Blue,Red);
        }


    }
    GotoXY(centerX + 5, centerY + 3);
    cout << "\n\n\t\tLoading Complete!";
    InFIle3("Xbar.txt", centerX + 50, centerY + 6, 0,Blue,Red);
    Sleep(200);

    system("cls");
    system("Color F0");
    cout << "\n";
    Logo(3);

    GotoXY(60, 8); cout << "WElCOME";
    Sleep(100);
    GotoXY(70, 8); cout << "TO";
    Sleep(100);
    GotoXY(75, 8); cout << "OUR";
    Sleep(100);
    GotoXY(80, 8); cout << "CARO";
    Sleep(100);
    GotoXY(85, 8); cout << "GAME";
    TrangTri(100);

    GotoXY(60, 23);  system("Pause");


}


void _LoadingBar()
{
    system("cls");


    system("color FA ");
    playSound(6);
    //set ASCII to print special character ...
    //code page 437 
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
    system("cls");



    cout << "\n\n\n\t\t\t\tLoading....";
    cout << "\n\n\n\t\t\t\t";
    for (int i = 0; i < 50; i++)
        cout << (char)bar1;
    cout << "\r";
    cout << "\t\t\t\t";

    for (int i = 0; i < 50; i++)
    {
        cout << (char)bar2;
        Sleep(150);
        cout << "\t Loading " << 2 * i << "%\t";

        Sleep(150 - i * 3);
    }

    system("cls");
}
void Sub_LoadingbarOld() {
    playSound(7);
    system("cls");
    //set ASCII to print special character ...
    //code page 437 
    system("color FA ");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    int bar1 = 177, bar2 = 219;
    cout << "\n\n\n\t\t\t\tLoading....";
    cout << "\n\n\n\t\t\t\t";
    for (int i = 0; i < 25; i++)
        cout << (char)bar1;
    cout << "\r";
    cout << "\t\t\t\t";
    for (int i = 0; i < 25; i++)
    {
        cout << (char)bar2;
        Sleep(100);
    }

    system("Pause");
    system("cls");
}
void Sub_Loadingbar(){
    playSound(7);
    CARO1();
}