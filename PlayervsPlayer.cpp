#include "PlayervsPlayer.h"
string cur[100];
using namespace std;
int ScoreX = 0, ScoreO = 0; //Số điểm của 2 người chơi X và O
int countX1, countO1;
bool TheLastValue; //Giá trị cuối cùng để đánh X hoặc O
string playerX_Name;
string PlayerO_Name;
const char* characterXFile;//file txt của nhân vật X
const char* characterOFile;// file txt của nhân vật Y 
int characterX;// nhân vật x 
int characterO;// nhân vật O
int times = 0;// Số lần chọn 
// Hằng số
#define BOARD_SIZE 14
#define LEFT 14
#define TOP 0
int countX = 0, countO = 0;
struct _POINT { int x, y, c; };
struct _POINT _A[BOARD_SIZE + 1][BOARD_SIZE + 1];
bool _TURN = true; 
int _COMMAND;
int _X = LEFT, _Y;
int cellX, cellY;

struct win_p {
    int x, y;//Lưu tọa độ của những điểm 5 quân liên tiếp
};

bool checkFile_pvp(string taptin) {
    ifstream input("CurBot.txt");
    while (!input.eof()) {
        string line;
        getline(input, line);
        playSound(2);
        if (taptin.compare(line) == 0) {
            return false;
        }
    }
    return true;
}
void SaveGame_ESC() //Ham xu ly save game sau khi nhan ESC
{
    int command;
    Textcolor(Green);
    GotoXY(5, 32); cout << "DO you want to save game ?                                       ";
    Textcolor(Violet);
    GotoXY(5, 33); cout << "   Yes : Press Y ";
    GotoXY(5, 34); cout << "   No :  Press T ";
    Textcolor(Black);
    command = toupper(_getch()); playSound(2);
    while (command != 'Y' && command != 'T') {
        command = toupper(_getch()); playSound(2);
    }
    if (command == 'Y')
    {
        GotoXY(5, 32); cout << "                                                                    ";
        GotoXY(5, 34); cout << "                                         ";
        Textcolor(Green);
        GotoXY(5, 33); cout << "Please name your file :...    " << endl;
        GotoXY(5, 34); cout << " FileName: ";
        Textcolor(Black);
        string taptin; 
        Textcolor(Blue);
        getline(cin, taptin); playSound(2);
        Textcolor(Black);
        while (taptin.length() > 20 || !checkFile_pvp(taptin)) {
            GotoXY(8, 34); cout << "                                                          ";
            GotoXY(5, 35);
            Textcolor(Red);
            cout << "Over the characters limit (20)!!! or not valid";
            playSound(3);
            Textcolor(Green);
            GotoXY(5, 34); cout << " FileName: ";
            Textcolor(Blue);
            getline(cin, taptin); 
            playSound(2);
            Textcolor(Black);
        }
        const char* filecur = "CurFile.txt";
        ofstream outFile(filecur,ios::app);
        if (!outFile.is_open()) {
            cerr << "Cannot open the File " << filecur << std::endl;
        }
        outFile << taptin << endl;
        outFile.close();
        ofstream S;
        S.open(taptin, ios::out);
        S << characterX << endl;
        S << characterO << endl;
     // S << characterXFile << endl;
     // S << characterOFile << endl;
        S << countX1 << endl;
        S << countO1 << endl;
        S << TheLastValue << endl;
        S << PlayerO_Name << endl;
        S << playerX_Name << endl;
       
        // S << _TURN;
        S << ScoreX << endl;
        S << ScoreO << endl;
        for (int i = 0; i < BOARD_SIZE; i++)
            for (int j = 0; j < BOARD_SIZE; j++)
            {
                if (_A[i][j].c == -1)
                    S << 2;
                else
                    S << _A[i][j].c;
            }
        S.close();
        ScreenStartGame(99);
    }
    else if (command == 'T') {
        ScreenStartGame(99);
    }
}
void LoadGame(string taptin) //Ham xu ly load game
{
    char t;
    ifstream L;
    L.open(taptin, ios::in);
    L >> characterX;
    L >> characterO;
 // L >> characterXFile;
 // L >> characterOFile;
    L >> countX1;
    L >> countO1;
    L >> TheLastValue ;
    L >> PlayerO_Name;
    L >> playerX_Name;
    //L >> _TURN;
    L >> ScoreX;
    L >> ScoreO;
    FixConsoleWindow();
    StartGame(&countX, &countO);
    countX = countX1; 
    countO = countO1;
    for (int i = 0; i < BOARD_SIZE; i++)
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            L >> t;
            if (t == '2')
            {
                _A[i][j].c = -1;
                GotoXY(_A[i][j].x, _A[i][j].y);
                Textcolor(252);
                cout << 'X';
            }
            else if (t == '1')
            {
                _A[i][j].c = 1;
                GotoXY(_A[i][j].x, _A[i][j].y);
                Textcolor(249);
                cout << 'O';
            }
        }
    RedrawBoard();
    L.close();
    if (TheLastValue == true)
        Xturn();

    else
        Oturn();
    GotoXY(6, 2);
    _TURN = TheLastValue;
    play_PvP();
}

void XuLyLoadGame() {
    string taptin;
    bool ktra;
    do {

        ktra = true;
        //team1();
        LoadHumans();
        Textcolor(240);
        GotoXY(65, 10); cout << "Nhap ten file da luu :";
        getline(cin, taptin);
        playSound(2);
        ifstream L;
        L.open(taptin, ios::in);
        if (L.fail() == 1)
        {
            ktra = false; playSound(3);
            GotoXY(65, 12); cout << "File khong ton tai !";
            GotoXY(65, 14); cout << "Nhan phim bat ki de nhap lai!";
            GotoXY(65, 15); cout << "Nhan ESC de thoat";
            if (_getch() == 27)
            {
                playSound(2);
                system("cls");
                ScreenStartGame(99);
            }
        }
    } while (ktra == false);
    LoadGame(taptin);
}



void ResetData() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            _A[i][j].x = 4 * j + LEFT + 2;
            _A[i][j].y = 2 * i + TOP + 1;
            _A[i][j].c = 0;
        }
    }

    _TURN = true;
    _COMMAND = -1;
    _X = _A[0][0].x;
    _Y = _A[0][0].y;
    countX = 0;
    countO = 0;
    times = 0;
}


// Hàm nhóm view
void DrawBoard()
{
    system("Color F6");
    // vẽ cột phải
    for (int i = 0; i < BOARD_SIZE * 2; i++)
    {

        GotoXY(BOARD_SIZE * 4 + LEFT, i + 1);
        Textcolor(245);
        if ((i + 1) % 2 == 1)
            cout << char(186); //186
        else
            cout << char(182);  //182
    }

    // vẽ dòng ngang
    for (int i = 0; i < BOARD_SIZE * 2; i = i + 2)
    {

        GotoXY(LEFT, i);
        Textcolor(Violet);
        for (int j = 0; j < BOARD_SIZE * 4; j++)
        {
            if (j % 4 == 0)
                cout << char(197);
            else
                cout << char(196);
        }
    }

    // vẽ cột trái

    for (int i = 0; i < BOARD_SIZE * 2; i++)
    {

        GotoXY(LEFT, i + 1);
        Textcolor(Violet);
        if ((i + 1) % 2 == 1)
            cout << char(186);
        else
            cout << char(199);
    }

    // vẽ cột dọc
    for (int i = 1; i < BOARD_SIZE * 2; i = i + 2)
    {
        for (int j = 0; j < BOARD_SIZE * 4; j = j + 4)
        {

            GotoXY(j + LEFT, i);
            Textcolor(245);
            if (j == 0)
                continue;
            cout << char(179);
        }
    }

    // vẽ dòng đầu
    GotoXY(LEFT, 0);
    Textcolor(245);
    for (int i = 0; i < BOARD_SIZE * 4; i++)
    {

        if (i % 4 == 0)
            cout << char(209);
        else
            cout << char(205);
    }
    GotoXY(LEFT, 0);
    Textcolor(245);
    cout << char(201);
    GotoXY(BOARD_SIZE * 4 + LEFT, 0);
    Textcolor(245);
    cout << char(187);

    // vẽ dòng cuối
    GotoXY(LEFT, BOARD_SIZE * 2);
    Textcolor(245);
    for (int i = 0; i < BOARD_SIZE * 4; i++)
    {

        if (i % 4 == 0)
            cout << char(207);
        else
            cout << char(205);
    }
    GotoXY(LEFT, BOARD_SIZE * 2);
    Textcolor(245);
    cout << char(200);
    GotoXY(BOARD_SIZE * 4 + LEFT, BOARD_SIZE * 2);
    Textcolor(245);
    cout << char(188);
    //khung dao dien
    KhungGiaoDien();
    // về vị trí x y
    GotoXY(LEFT + 65, TOP + 9);
    cout << "So luot cua X la ";
    GotoXY(LEFT + 95, TOP + 9);
    cout << "So luot cua O la ";
    GotoXY(LEFT + 95, TOP + 10);
    //cout << "Luot cua ";
    GotoXY(LEFT + 2, 1);
}


// Hàm nhóm Control
void StartGame(int* dX, int* dY) {
    system("cls");
    ResetData();
  DrawBoard();
    *dX = 0; *dY = 0;
}



void GabageCollect() {
    // Dọn dẹp tài nguyên nếu có khai báo con trỏ
}
//Hàm in nước đi
void in_nuoc_di() {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            GotoXY(_A[i][j].x, _A[i][j].y);
            if (_A[i][j].c == -1)  cout << "X";
            if (_A[i][j].c == 1) cout << "O";
        }
    }
}
void ExitGame() {
    system("cls");
    GabageCollect();
}



//Hàm nhóm Model
bool checkWin_pvp(int x, int y, int player, bool ok) {
    int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
    vector <win_p> win_list;

    for (int d = 0; d < 4; ++d) {
        int count = 0;
        for (int i = -4; i <= 4; ++i) {
            int checkX = x + i * directions[d][0];
            int checkY = y + i * directions[d][1];
            if (checkX >= 0 && checkX < BOARD_SIZE && checkY >= 0 && checkY < BOARD_SIZE && _A[checkX][checkY].c == player) {
                count++;
                win_list.push_back(win_p{ checkX, checkY });
                if (count == 5) {
                    if (ok == true) {
                        if (player == -1) {
                            int j = 15;
                            playSound(13);
                            while (j > 0) {
                                j--;
                                Sleep(50);
                                
                                // Đặt lại màu cho ô 
                                Textcolor(FullRed);
                                for (int i = 0; i < 5; i++) {
                                    GotoXY(_A[win_list[i].x][win_list[i].y].x, _A[win_list[i].x][win_list[i].y].y);
                                    cout << ' ';
                                }

                                Sleep(125);

                                Textcolor(22);
                                for (int i = 0; i < 5; i++)
                                {
                                    GotoXY(_A[win_list[i].x][win_list[i].y].x, _A[win_list[i].x][win_list[i].y].y);
                                    cout << 'X';
                                }




                            }
                            Sleep(300);
                        }
                        if (player == 1) {
                            int j = 11;
                            playSound(13);
                            while (j > 0) {
                                j--;
                                Sleep(50);

                                // Đặt lại màu cho ô 
                               //22 là vàng nền xanh 
                                Textcolor(FullRed);
                                for (int i = 0; i < 5; i++) {
                                    GotoXY(_A[win_list[i].x][win_list[i].y].x, _A[win_list[i].x][win_list[i].y].y);
                                    cout << ' ';
                                }
                                Sleep(125);
                                Textcolor(22);//22 là màu đen nền xanh 
                                for (int i = 0; i < 5; i++)
                                {
                                    GotoXY(_A[win_list[i].x][win_list[i].y].x, _A[win_list[i].x][win_list[i].y].y);
                                    cout << 'O';
                                }

                            }

                            Sleep(400);

                        }
                    }
                    return true;
                }
            }
            else {
                count = 0;
                win_list.clear();
            }
        }
    }
    return false;
}
bool isDraw_pvp() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (_A[i][j].c == 0) {
                return false; // Còn ô trống, chưa hòa
            }
        }
    }
    return true; // Không còn ô trống, hòa
}


int TestBoard() {
    get_locate(_X, _Y);
    bool winX = checkWin_pvp(cellX,cellY, -1, true);
    bool winO = checkWin_pvp(cellX,cellY, 1, true);
    bool Draw = isDraw_pvp();
    if (winX) return -1;
    else if (winO) return 1;
    else return 2;
    return 0; // Hòa
}// Duyệt qua từng vòng ô xem c có bằng 0 hết hay không, nếu có return 0 cho ra hòa.
void get_locate(int pX, int pY) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].x == pX && _A[i][j].y == pY)
            {
                cellX = i; cellY = j;
                break;
            }
        }
    }
}

int CheckBoard(int pX, int pY) {
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (_A[i][j].x == pX && _A[i][j].y == pY && _A[i][j].c == 0) {
                if (_TURN == true) {
                    _A[i][j].c = -1; countX++;
                    countX1 = countX; 
                    return 1;
                }
                else {
                    _A[i][j].c = 1; countO++;
                    countO1 = countO;
                    return 1;
                }

            }
        }
    }
    return 0;
}

int ProcessFinish(int pWhoWin, int &countX, int &countO) {
    if (_TURN == true) {
        Xturn();
        TheLastValue = _TURN;
        printf_s("");
        GotoXY(LEFT + 112, TOP + 9);
        printf_s("%d", countO);

    }
    else {

        Oturn();
        TheLastValue = _TURN;
        GotoXY(LEFT + 82, TOP + 9);
        printf_s("%d", countX);

    }
    GotoXY(LEFT + 85, TOP + 20);// Nhảy đến vị trí thích hợp để in thắng, thua, hòa
    switch (pWhoWin) {
    case -1:

      //printf("Nguoi choi %d da thang\n", true, false);
        system("cls");
        ResetData();
        WINX();
        ScoreX++;
        countO1 = 0; 
        countX1 = 0;
        break;
    case 1:

     //printf("Nguoi choi %d da thang \n", false, true);
        system("cls");
        ResetData();
        WINO();
        countO1 = 0;
        countX1 = 0;
        ScoreO++;
       
        break;
    case 0:
     // printf("Nguoi choi %d da hoa nguoi choi %d\n", false, true);
        system("cls");
        DRAW();
       
        break;
    case 2:


        GotoXY(_X, _Y);
    }

    return pWhoWin;
}

void MoveRight() {
    if (_X < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].x) {
        _X += 4;

    }
}

void MoveLeft() {
    if (_X > _A[0][0].x) {
        _X -= 4;

    }
}

void MoveDown() {
    if (_Y < _A[BOARD_SIZE - 1][BOARD_SIZE - 1].y) {
        _Y += 2;

    }
}

void MoveUp() {
    if (_Y > _A[0][0].y) {
        _Y -= 2;

    }
}


void play_PvP() {
   
    GotoXY(LEFT + 110, 4);
    Textcolor(Blue);
    cout << PlayerO_Name;
    GotoXY(LEFT + 80, 4);
    Textcolor(Red);
    cout << playerX_Name;
    Textcolor(Black);
    GotoXY(LEFT + 65, 5);
    cout << "Score";
    GotoXY(LEFT + 75, 5);
    cout << ScoreX;
    GotoXY(LEFT + 98, 5);
    cout << "Score";
    GotoXY(LEFT + 108, 5);
    cout << ScoreO;
    HienCharacter(characterX, characterO, characterXFile, characterOFile);
    bool validEnter = true;
    AnTroChuot();
    Xturn();
    int k = ProcessFinish(TestBoard(), countX, countO);
    while (1) {
        while (1) {
            RedrawBoard();
            GotoXY(_X, _Y);
            if (_TURN == true)
            {
                Textcolor(Red);
                cout << "X";
                Textcolor(Black);
            }
            else
            {
                Textcolor(Blue);
                cout << "O";
                Textcolor(Black);
            }
            _COMMAND = toupper(_getch()); playSound(2);
            GotoXY(_X, _Y);
            get_locate(_X, _Y);
            if (_A[cellX][cellY].c == 0) cout << " ";
            if (_A[cellX][cellY].c == -1) { Textcolor(Red); cout << "X"; Textcolor(Black); }
            if (_A[cellX][cellY].c == 1) { Textcolor(Blue);  cout << "O"; Textcolor(Black);}

            if (_COMMAND == 27) {
                AskcontinuePlayer();
                //SaveGame_ESC();
                ScreenStartGame(99);
                return;


            }
            else {
                if (_COMMAND == 'M') {
                    On_Of_sound();
                }
                if (_COMMAND == 'Q') {
                    nn();
                }
                if (_COMMAND == 'A') { MoveLeft(); playSound(1); }
                else if (_COMMAND == 'W') { MoveUp(); playSound(1); }
                else if (_COMMAND == 'S') { MoveDown(); playSound(1); }
                else if (_COMMAND == 'D') { MoveRight(); playSound(1); }
                else if (_COMMAND == 13) {
                    playSound(2); // Người chơi đánh dấu trên màn hình bàn cờ
                    if (CheckBoard(_X, _Y) == 1) { _TURN = !_TURN; break; }

                    else validEnter = false;
                }
            }
        }
        // Tiếp theo là kiểm tra và xử lý thắng/thua/hòa/tiếp tục
        if (validEnter == true) {
            int result = ProcessFinish(TestBoard(), countX, countO);

            if (result == -1 || result == 1 || result == 0) {
                if (AskContinueFound(ContinueGame, SaveGame_ESC, XuLySubMenuLoadGame) != 'Y') {
                    playSound(2);
                    ExitGame();

                }
                else {
                    playSound(2);
                    StartGame(&countX, &countO);
                }
            }
        }

        validEnter = true; // Mở khóa
        in_nuoc_di();
    }
}


void AskNamePlayer() {
    AskName(1, Green, "Player X", "Player O", playerX_Name, PlayerO_Name);
}
void PlayervsPlayer() {
    playSound(9);
    system("cls");
    //system("color F0");

    PVPBAR();
    
    system("cls");
    AskNamePlayer();
    system("cls");
  //StartGame(&countX, &countO);
    countX = 0;
    countO = 0; 
    XuLyChacracter(characterX, characterO, times, ResetData, ContinueGame);
    play_PvP();
}

void RedrawBoard()
{
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            GotoXY(_A[i][j].x, _A[i][j].y);

            if (_A[i][j].c == -1)
            {
                Textcolor(Red);
                cout << 'X';
            }
            else if (_A[i][j].c == 1)
            {
                Textcolor(Blue);
                cout << 'O';
            }
        }
    }
}

void ContinueGame() {
    system("cls");
// ResetData(); GotoXY(_X, _Y);

    DrawBoard();
    RedrawBoard();
    play_PvP();
    

}





