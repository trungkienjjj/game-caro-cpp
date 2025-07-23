#include "MenuGame.h"
#include "Sound.h"

#pragma comment(lib, "winmm.lib")//Kien them
void playSound(int i); bool isSoundOn = true;
void About()
{
    int x = 20 ; 
    int y = 3 ; 
    
    system("cls");
    system("color F0");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    Textdecorate("animationAbout.txt", 1.0, 3, 175);
    Textdecorate("animation.txt", 2.0, 5, 175);
    system("cls");

   // DrawBoardAbout(18,15,30,0);
   // PrintCaro3();
    system("color F0");
   // PrintCaroFound2(170, 151, 221, 358);

  
    //cout << "ABOUT";
    //Logo(2);
   // LOGOTEAMFound(50, 6, Red, Blue);
   // InFIle3("test5.txt", 0, 0, 1);
    InFIle3("AboutBoard.txt",50,0,1,Red,Blue);
    playSound(12);
    InFIle3("CaroAbout.txt", 17, 0, 1, Green, Yellow);
    Textcolor(Red);
    GotoXY(47+x, 15+y);
    cout << "DO AN GAME CARO - LOP23TNT1  - HCMUS" << endl;
    GotoXY(56+x, 16+y);
    cout << "GROUP AI's SLAVE" << endl;
    GotoXY(42+x, 17+y);
    cout << "Bang My Linh           - Student ID: 23122009" << endl;
    GotoXY(42+x, 18+y);
    cout << "Nguyen Lam Phu Quy     - Student ID: 23122048" << endl;
    GotoXY(42+x, 19+y);
    cout << "Dao Sy Duy Minh        - Student ID: 23122041 " << endl;
    GotoXY(42+x, 20+y);
    cout << "Nguyen Tran Trung Kien - Student ID: 23122038 " << endl;
    GotoXY(42+x, 21+y);
    cout << "Giang vien huong dan: Truong Toan Thinh " << endl;
    GotoXY(56+x, 22+y);
    cout << "!!" << endl;
    GotoXY(56+x, 24+y);
    cout << "Esc :BACK";
    X_decorate(120, 5, Red);
    O_decorate(120, 30, Blue);
    char command = ' ';
    command = _getch(); playSound(2);
    system("cls");
}
void Help() {
    system("cls");
    system("Color F0");
    SetConsoleCP(437);
    SetConsoleOutputCP(437);
    Textdecorate("HelpTil.txt", 2.0, 5, 175);

    system("cls");
    system("Color F0");
    In_Tep("Help.txt",Blue);
    playSound(12);
    DrawBoardAbout(18,18,40,0);
}

struct Name {
    char data[30];
};
vector <Name> ch;


// Hàm để hiển thị menu con
void submenu(int & currentChoice_sub,string SubmenuName,string choice1 , string choice2 , string choice3) {
    const int MAX_CHOICE_sub = 3;
    char key1;
    int centerX = 60; // Giả sử màn hình console có độ rộng là 80 ký tự
    int centerY = 20; // Đặt menu ở hàng thứ 10
    system("cls");
    system("color F0");
    PrintCaro3();
      do {
        
        GotoXY(centerX, centerY);
        Textcolor(Violet); // Màu xanh cyan đậm
        cout << "==="<<SubmenuName<< " === \n";
        Textcolor(Black); // Màu bình thường
        for (int i = 1; i <= MAX_CHOICE_sub; ++i) {
            GotoXY(centerX, centerY + i);// Di chuyển con trỏ đến đoạn chọn
            if (currentChoice_sub == i) {
                Textcolor(Red); 
                cout << "-> ";
            }
            else {
                Textcolor(Black); // Màu bình thường
                cout << "   ";
            }

            switch (i) {
            case 1: cout << choice1 ; break;
            case 2: cout << choice2 ; break;
            case 3: cout << choice3 ; break;
            }
        }
        key1 = _getch(); 
        if ((key1 == 'w' || key1 == 'W') && currentChoice_sub > 1) { playSound(1); currentChoice_sub--; }
        else if ((key1 == 's' || key1 == 'S') && currentChoice_sub < MAX_CHOICE_sub) {
            playSound(1); currentChoice_sub++;
        }
        else if (key1 == 'm' || key1 == 'M') On_Of_sound();
        else if (key1 == 'q' || key1 == 'Q') nn();
        else if (key1 == 13)playSound(2);
        } while (key1 != 13);
        
}
void Nothing() {
    Sleep(100);
}

void XuLySubMenuFound(string SubmenuName,string choice1,string choice2,string choice3, void (*func1)(), void (*func2)(), void (*func3)(int),void(*Loadgame)() ){
    //system("Color F0");
    AnTroChuot();
    int subChoice = 1;
    while (true) {
        submenu(subChoice, SubmenuName, choice1, choice2,choice3);
        switch (subChoice) {
        case 1:
            func1();                               
            break;
        case 2:                   
            func2();           
            break;
        case 3:
            func3(99);
            return;
        }
    }
    //_getch();
}
void XuLySubMenu() {
    XuLySubMenuFound("PlayMode", "1.PlayerVsBotEasy\n", "2.PlayerVsBotHard\n", "3.Return To MainMenu\n", PlayerVsBOTEASY, PlayerVsBOT, ScreenStartGame, Sub_Loadingbar);
}
void XuLySubMenuLoadGame() {
    XuLySubMenuFound("LoadMode", "1.LoadPLayerVsPlayer\n", "2.LoadPlayerVsBOT\n", "3.Return to MainMenu\n", XuLyLoadGamePlayer,XuLyLoadGameBot,ScreenStartGame,Nothing );
}
// Hàm để hiển thị menu chính
void showMenu(int& currentChoice) {
    const int MAX_CHOICE = 7;
    char key;
    int centerX = 60; // Giả sử màn hình console có độ rộng là 80 ký tự
    int centerY = 20; // Đặt menu ở hàng thứ 10
    
    do {
        GotoXY(centerX, centerY); // Di chuyển con trỏ đến vị trí giữa
        Textcolor(Blue); // Màu xanh dương đậm
        cout << "====== Main Menu ======\n";
        Textcolor(Black); // Màu bình thường
        for (int i = 1; i <= MAX_CHOICE; ++i) {
            GotoXY(centerX, centerY + i); // Di chuyển con trỏ đến từng lựa chọn
            if (currentChoice == i) {
                Textcolor(Red); // Vàng đậm
                cout << "-> ";
            }
            else {
                Textcolor(Black); // Màu bình thường
                cout << "   ";
            }
            switch (i) {
            case 1: cout << "PlayerVsPlayers\n"; break;
            case 2: cout << "PlayersVsBot(Easy or Hard)\n"; break;
            case 3: cout << "LoadGame\n"; break;
            case 4: cout << "HISTORY\n"; break;
            case 5: cout << "Help\n"; break;
            case 6: cout << "About\n"; break;
            case 7: cout << "Exit\n"; break;
            }
        }
        key = _getch();
        if ((key == 'w' || key == 'W') && currentChoice > 1) { playSound(1); currentChoice--; }
        else if ((key == 's' || key == 'S') && currentChoice < MAX_CHOICE) { playSound(1); currentChoice++; }
        else if (key == 'm' || key == 'M') {
            On_Of_sound();
        }
        else if (key == 'q' || key == 'Q') {
            nn();
        }
        else if (key == 13) playSound(2);
    } while (key != 13);

  
}
int caroload = 0;
void ScreenStartGame(int n) {
    int check = n; 
    system("cls");
    system("Color F0");
    AnTroChuot();   
    if (caroload == 0){
        CARO1();
        caroload++;
    }   
    system("cls");
    PrintCaro2();
    Sleep(150);
    X_decorate(10, 15,Red);
    O_decorate(127, 15, Blue);
    PrintCaro3();
    Textcolor(Black);
    GotoXY(50, 32); cout << "....... W - S : Move  ";
    GotoXY(50, 33); cout << "....... Enter : Select ";
    GotoXY(50, 34); cout << ".......   M   : Mute ";
    GotoXY(50, 35); cout << ".......   Q   : On/Off Music ";
    int mainChoice = 1;
    while (check) {
        showMenu(mainChoice);
        switch (mainChoice) {
        case 1:         
            PlayervsPlayer();
            system("cls");
            ScreenStartGame(99);          
            break;
        case 2:
            playSound(2);
            Textcolor(240);
            XuLySubMenu();
       
            break;
        case 3:
        {playSound(2);
        system("cls");
        XuLySubMenuLoadGame();
        }
        case 4:
            playSound(2);
            break;
        case 5:
            playSound(2);
            system("cls");
            Help();
            system("Pause");
            system("cls");
            ScreenStartGame(99);
            break;
        case 6:
            playSound(2);
            About();
            ScreenStartGame(99);
            break;
        case 7:
            playSound(2);
            Textcolor(240);
            cout << "Exiting Program.";
            exit(0);
        }
     
    }  
}


void XuLyLoadGame(int i) {
    //XulyLoadgame

    int b = 52;// left
    int y = 2;//top
    string taptin;
    bool ktra;
    do {
        system("cls");
        ktra = true;
        InFIle3("ListLoadBot.txt", 30, 0, 5,Green,Blue);
        //team1();
        if (i == 1) {
            LoadBot();
        }
        else if (i == 2) {

            LoadHumans();
        }
        in_currFile();

        Textcolor(Green);
        GotoXY(b, y); cout << "Please type your saved file name here : ";
        Textcolor(Blue);
        getline(cin, taptin);
        Textcolor(Black);
        if (i == 2) {
            ifstream input("CurFile.txt");
            while (!input.eof()) {
                string line;
                getline(input, line);
                while (taptin.compare(line) == 0) {
                    Textcolor(Red);
                    GotoXY(b, y + 1); cout << "File non existent";
                    GotoXY(b, y + 2); cout << "Press anykeys to type again";
                    GotoXY(b, y + 3); cout << "Press Esc to exit ";
                    Textcolor(Black);
                    if (_getch() == 27)
                    {
                        system("cls");
                        ScreenStartGame(99);
                    }
                    else {
                        GotoXY(b, y); cout << "Please type your saved file name here:";
                        Textcolor(Blue);
                        getline(cin, taptin);
                    }
                }
            }
        }
        if (i == 1) {
            ifstream input("CurBot.txt");
            while (!input.eof()) {
                string line;
                getline(input, line);
                while (taptin.compare(line) == 0) {
                    Textcolor(Red);
                    GotoXY(b, y + 1); cout << "File non existent";
                    GotoXY(b, y + 2); cout << "Press anykeys to type again";
                    GotoXY(b, y + 3); cout << "Press Esc to exit ";
                    Textcolor(Black);
                    if (_getch() == 27)
                    {
                        system("cls");
                        ScreenStartGame(99);
                    }
                    else {
                        Textcolor(Green);
                        GotoXY(b, y); cout << "Please type your saved file name here:";
                        Textcolor(Blue);
                        getline(cin, taptin);
                    }
                }
            }
        }
        ifstream L;
        L.open(taptin, ios::in);
        if (L.fail() == 1)
        {
            ktra = false;
            Textcolor(Red);
            GotoXY(b, y + 1); cout << "File non existent";
            GotoXY(b, y + 2); cout << "Press anykeys to type again";
            GotoXY(b, y + 3); cout << "Press Esc to exit ";
            Textcolor(Black);
            if (_getch() == 27)
            {
                system("cls");
                ScreenStartGame(99);
            }
        }
    } while (ktra == false);
    system("cls");
    if (i == 1) {
        LoadGame(taptin);
    }
    else if (i == 2) {
        LoadGameBot(taptin);
    }
}
void XuLyLoadGamePlayer() {
    LoadHumansBar();
    system("cls");
    LoadHumans();
    XuLyLoadGame(1);
}
void XuLyLoadGameBot() {
    LoadBotBar();
    system("cls");
    LoadBot();
    XuLyLoadGame(2);
}

void in_currFile() {
    int a = 45;
    GotoXY(a - 5, 11);
    Textcolor(245);
    cout << "CURRENT FILE PVP" << endl;
    string f_name = "CurFile.txt";
    ifstream file(f_name);
    if (!file.is_open()) {
        std::cerr << "Error! Please try again" << f_name << std::endl;
    }
    else {
        string line;
        int i = 0;
        while (getline(file, line)) {
            GotoXY(a, 12 + i);
            Textcolor(252);
            cout << line << endl;
            i++;
        }
        file.close();
    }
    GotoXY(a + 33, 11);
    Textcolor(245);
    cout << "CURRENT FILE PVC" << endl;
    f_name = "CurBot.txt";
    ifstream file_b(f_name);
    if (!file_b.is_open()) {
        std::cerr << "Error! Please try again" << f_name << std::endl;
    }
    else {
        string line;
        int i = 0;
        while (getline(file_b, line)) {
            GotoXY(a + 37, 12 + i);
            Textcolor(252);
            cout << line << endl;
            i++;
        }
        file_b.close();
    }
}
