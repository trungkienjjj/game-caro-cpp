#include "Charactars.h"
using namespace std;
void InFIle() {
    string f_name = "LOADBOT.txt";
    ifstream file(f_name);
    if (!file.is_open()) {
        std::cerr << "Error! Please try again" << f_name << std::endl;
        playSound(3);
    }
    else {
        string line;
        int i = 0;
        while (getline(file, line)) {
            GotoXY(0, 12 + i);
            Textcolor(252);
            cout << line << endl;
            i++;
        }
        file.close();
    }
}
void InFIle1(const char* f_name, int x, int y, int color) {

    FILE* file;
    fopen_s(&file, f_name, "r");
    if (!file) {
        fprintf(stderr, "Error! Please try again %s\n", f_name);
        playSound(3);
    }
    else {
        char line[1024]; // Assuming a maximum line length
        int i = 0;
        while (fgets(line, sizeof(line), file)) {
            GotoXY(x, y + i);
            Textcolor(color);
            if (i < 12) {
                Sleep(1);
            }
            if (i > 0) {
                printf("%s", line); // line already contains a newline character
            }

            i++;
        }
        fclose(file);
    }
}
void InFIle1N(const char* f_name, int x, int y, int color, int time) {

    FILE* file;
    fopen_s(&file, f_name, "r");
    if (!file) {
        fprintf(stderr, "Error! Please try again %s\n", f_name);
        playSound(3);
    }
    else {
        char line[1024]; // Assuming a maximum line length
        int i = 0;
        while (fgets(line, sizeof(line), file)) {
            if (i != 0) {
                GotoXY(x, y + i);

                Sleep(time);
                Textcolor(color);
                printf("%s", line); // line already contains a newline character
            }
            i++;


        }
        fclose(file);
    }
}
void InFIle3(const char* namefile, int x, int y, int time,int color1,int color2 ) {
    FILE* file;
    fopen_s(&file, namefile, "r");
    if (!file) {
        fprintf(stderr, "Error! Please try again %s\n", namefile);
        playSound(3);

    }
    else {
        char line[1024];
        int i = 0;
        while (fgets(line, sizeof(line), file)) {


            Sleep(time);
            if (i != 0) {

                if ((i % 2) == 0) {
                    Textcolor(color1);
                }
                else {
                    Textcolor(color2);
                }
                GotoXY(x, y + i);
                printf("%s", line); // line already contains a newline character
            }

            i++;
        }
        fclose(file);

    }
}


void ClearAndSetColor() {
   
}

void PrintCharacterOptions() {
    GotoXY(CENTER_X, CENTER_Y - 1);
    cout << "                              ";
    GotoXY(CENTER_X, CENTER_Y);
    cout << "=== CHOSE YOUR CHARACTERS === ";
    Textcolor(176);
    GotoXY(CENTER_X, CENTER_Y + 1);  cout << "       Pikachu                ";
    GotoXY(CENTER_X, CENTER_Y + 2);  cout << "       Charizard              ";
    GotoXY(CENTER_X, CENTER_Y + 3);  cout << "       Squirtle               ";
    GotoXY(CENTER_X, CENTER_Y + 4);  cout << "                              ";
}
void DisplayStatus1() {
   
}
void DisplayStatus(int percentage, int loadingBarWidth, int loadingBarHeight, int x, int y, int color, string status) {
    int filledWidth = (percentage * loadingBarWidth) / 100;
    for (int h = 0; h < loadingBarHeight; h++) {
        GotoXY(x, y + h);  // Chỉnh lại vị trí Y cho mỗi dòng
        if (h == 0) {   
            cout << status;
        }
        else {
           cout << "         ";  // Các dòng sau chỉ cần khoảng trống
        }
        for (int i = 0; i < filledWidth; ++i) {
            Textcolor(color);
            cout << "\xDB"; // Ký tự khối
        }
        // Chuyển sang phần chưa điền
        Textcolor(Grey); // Màu xám cho phần chưa điền
        for (int i = filledWidth; i < loadingBarWidth; ++i) {
            cout << "\xB0"; // Ký tự bóng nhẹ
        }
        Textcolor(Black); // Quay lại màu bình thường
        cout << " " << percentage;
        cout.flush();
    }
}
//"HP:          "
//"Attack:      "
//"Defrense:    "
//"Sp.Atk:      "
//"Speed:       "
//
//
//
void XulyDisplayStatus(int hp, int attack, int defense, int atk, int speed, string types, string abilities, string tier, int color) {
    int x = 2;
    int y = 25;
    // y+ 2; 
    // y+ 4; y+6; y+8;
    system("cls");
    system("color F0");
    Textcolor(190); // Màu xanh cyan đậm

    PrintCharacterOptions();
    Textcolor(Black);
    GotoXY(x + 7, y - 6);
    cout << "Types :";
    Textcolor(color);
    cout << types;
    Textcolor(Black);
    GotoXY(x + 7, y - 5);
    cout << "Abilities: ";
    Textcolor(Blue);
    cout << abilities;
    GotoXY(x + 7, y - 4);
    Textcolor(Black);
    cout << "Tier: ";
    Textcolor(Blue);
    cout << tier;
    Textcolor(Black);
    DisplayStatus(hp, 30, 1, x, y, Red, "HP:        ");
    DisplayStatus(attack, 30, 1, x, y + 2, 246, "Attack:    ");
    DisplayStatus(defense, 30, 1, x, y + 4, Blue, "Defrense:  ");
    DisplayStatus(atk, 30, 1, x, y + 6, Green, "Sp.Atk:    ");
    DisplayStatus(speed, 30, 1, x, y + 8, Violet, "Speed:     ");
}
void DisplayCharacter(int choice) {

    switch (choice) {
    case 1:
        //isplayStatus();
       //updateLoadingBar(50,10, 1);
        XulyDisplayStatus(35, 55, 40, 50, 90, "Electric", "Static/Lighting Rod", "ZU", 111);
        InFIle1("Pikachu.txt", 60, 0, 246);
        break;
    case 2:

        XulyDisplayStatus(78, 84, 78, 100, 100, "Fire", "Blaze/Solar Power", "PUBL", 335);//335 là trắng nền đỏ 
        InFIle1("Charizard.txt", 50, 0, Red);
        break;
    case 3:
        XulyDisplayStatus(44, 48, 65, 50, 43, "Water", "Torrent/Rain Dish", "LC", 159);
        InFIle1("Meowtwo.txt", 60, 0, Blue);
        break;
    }
}

void Character(int& currentChoice_sub,int&times){
    const int MAX_CHOICE_sub = 3;
    char key1;
    int centerX = 5; // Giả sử màn hình console có độ rộng là 80 ký tự
    int centerY = 10; // Đặt menu ở hàng thứ 10
    system("cls");
    system("color F0");
    
    
    do {
     

        GotoXY(centerX, centerY);
        Textcolor(190); // Màu xanh cyan đậm
        cout << "=== CHOSE YOUR CHARACTERS === \n";
        DisplayCharacter(currentChoice_sub);

        X_decorate(12,1,Red);
        X_decorate(12,1,Red);
        if (times != 0) {
            O_decorate(12,1,Blue);
        }

        Textcolor(190); // Màu bình thường
        for (int i = 1; i <= MAX_CHOICE_sub; ++i) {
            GotoXY(centerX, centerY + i);// Di chuyển con trỏ đến đoạn chọn
            if (currentChoice_sub == i) {
                Textcolor(190);
                cout << "-> ";

            }
            else {
                Textcolor(176); // Màu bình thường
                cout << "   ";
            }

            switch (i) {
            case 1: { cout << "       Pikachu             ";

            }break;
            case 2: { cout << "       Charizard           ";

            } break;
            case 3: cout << "       Squirtle            "; break;
            }

        }
        key1 = _getch(); 
        if ((key1 == 'w' || key1 == 'W') && currentChoice_sub > 1) { currentChoice_sub--; playSound(1);
        }
        else if ((key1 == 's' || key1 == 'S') && currentChoice_sub < MAX_CHOICE_sub) { currentChoice_sub++; playSound(1);
        }
        else if (key1 == 'm' || key1 == 'M') On_Of_sound();
        else if (key1 == 'q' || key1 == 'Q') nn();

    } while (key1 != 13);
    if (key1 == 13) {
        playSound(2);
        times++;
    }


}
void ScreenVs(int characterX,int characterO ){
    playSound(14);
    int a = 5;

    const char* Taptin;
    int ColorX = 246, ColorO = 246;
    switch (characterX)
    {
    case 1:
        Taptin = "Pikachu2.txt";
        ColorO = 246;
        break;
    case 2:
        Taptin = "Charizard2.txt";
        ColorO = Red;
        break;

    case 3:
        Taptin = "Meowtwo2.txt";
        ColorO = Blue;
        break;
    default:
        Taptin = "Charizard2.txt";
        break;
    }

    const char* Taptin1;
    switch (characterO)
    {
    case 1:
        Taptin1 = "Pikachu2.txt";
        ColorX = 246;
        break;
    case 2:
        Taptin1 = "Charizard2.txt";
        ColorX = Red;
        break;
    case 3:
        Taptin1 = "Meowtwo2.txt";
        ColorX = Blue;
        break;
    default:
        Taptin1 = "Charizard2.txt";
        break;
    }

    for (int i = 0; i <= a; i++) {
        system("cls");
        // InFIle1N("Pikachu2.txt", 0+i, 0+i, 246+i,0);
         //InFIle1N("Meowtwo2.txt", 60-i, 30-i, Blue+i,0);
        InFIle1N(Taptin, 0 + i, 0 + i, ColorO + i, 0);
        InFIle1N(Taptin1, 60 - i, 30 - i, ColorX + i, 0);
        Sleep(50);
        int j = i;
        if (i == a) {

            InFIle1N("Vs.txt", 60, 17, Red, 1);
            InFIle1N(Taptin, 0 + a, 0 + a, ColorO, 1);
            InFIle1N(Taptin1, 60 - a, 30 - a, ColorX, 1);

        }
    }

}

void XuLyChacracter(int& characterX, int& characterO,int &times,void (*func)(),void (*func1)()){
    system("Color F0");
    AnTroChuot();
    
    PrintCharacterOptions();
 // XulyDisplayStatus(35, 55, 40, 50, 90, "Electric", "Static/Lighting Rod", "ZU", 111);
    X_decorate(12,1,Red);
    int subChoice = 1;
    char key1 = _getch();
    while (true) {
        Character(subChoice, times);
        switch (subChoice) {
        case 1:
            if (times == 1) {
                characterX = 1;
               // Confirm(50, 16, Red);
                ConfirmAnimation(50, 16, 6, 30);
            }
            else if (times == 2) {
            
                characterO = 1;
                ConfirmAnimation(50, 16, 6, 30);
                ScreenVs(characterX, characterO);
                system("cls");
                system("Color F6");
                func();
              func1();
                break;
            }

            break;
        case 2:
        {

            if (times == 1) {
                characterX = 2;
                ConfirmAnimation(50, 16, 6, 30);
               
            }
            else if (times == 2) {
                
                characterO = 2;
                ConfirmAnimation(50, 16, 6, 30);
               
                ScreenVs(characterX, characterO);
                system("cls");
                system("Color F6");
             func();
            func1();
                break;
            }
        }

        break;
        case 3:
            if (times == 1) {
                characterX = 3;
                ConfirmAnimation(50, 16, 6, 30);
               
            }
            else if (times == 2) {
                
                characterO = 3;
                ConfirmAnimation(50, 16, 6, 30);
               
                ScreenVs(characterX, characterO);
                system("cls");
                func();
             func1();
                break;
            }

            break;
        }
    }
}
void HienCharacter(int& characterX, int& characterO, const char*& characterXFile, const char*& characterOFile) {
    int a = 0;
    int color, color2;

    switch (characterX)
    {
    case 1:
        characterXFile = "Pikachu2.txt";
        color = 246;
        break;
    case 2:
        characterXFile = "Charizard2.txt";
        color = Red;
        break;
    case 3:
        characterXFile = "Meowtwo2.txt";
        color = Blue;
        break;
    default:
        InFIle1N("Pikachu2.txt", 0 + a, 30 + a, 246, 1);
        color = Blue;
        break;
    }
    InFIle1N(characterXFile, 0 + a, 30 + a, color, 1);

    switch (characterO)
    {
    case 1:
        characterOFile = "Pikachu2.txt";
        color2 = 246;
        break;
    case 2:
        characterOFile = "Charizard2.txt";
        color2 = Red;
        break;
    case 3:
        characterOFile = "Meowtwo2.txt";
        color2 = Blue;
        break;
    default:
        InFIle1N("Charizard2.txt", 0 + 75, 30 + a, Red, 1);
        color2 = Blue;
        break;
    }
    InFIle1N(characterOFile, 0 + 75, 30 + a, color2, 1);
    Textcolor(Green);
    GotoXY(25, 30);
    cout << "X Characters" << endl;
    Textcolor(Green);
    GotoXY(83, 30);
    cout << "O Characters"<<endl;
}