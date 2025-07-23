#include "PLAYERVSBOT.h"
//#include <Windows.h>;
#include "Textfile.h"
#include "Sound.h"
#include "Charactars.h"
using namespace std;
bool LEVEL = true;
bool TURN_B = true; //true người chơi false máy chơi
bool TheLastValueBot = TURN_B;
int ScorePlayer =0;
int ScoreBot = 0;;
string Player_Name;
string Bot_Name;
int characterXBot;
int characterOPlayer;
int timesBot = 0;
const char* characterXBotFile;
const char* characterOPlayerFile;
struct _POINT_BOT {
    int x, y;
    char c;
};
struct win {
    int x, y;//Lưu tọa độ của những điểm 5 quân liên tiếp
};
_POINT_BOT board[SIZE][SIZE];
int cursorX = LEFT, cursorY = TOP;
int bestMoveX, bestMoveY;


int real_cellX, real_cellY;

int countX_bot =0, countO_bot =0;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x * 4 + 2 + LEFT;
    coord.Y = y * 2 + 1 + TOP;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void StartBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j].x = i;
            board[i][j].y = j;
            board[i][j].c = ' ';
        }
    }
    TURN_B = true;
    countX_bot = 0; countO_bot = 0;
    timesBot = 0;
    ScoreBot = 0; 
    ScorePlayer = 0;
}

void DrawBoardBOT()
{
 
    int BOARD_SIZE_BOT = SIZE;
    for (int i = 0; i < BOARD_SIZE_BOT * 2; i++)
    {
        GotoXY( BOARD_SIZE_BOT * 4 + LEFT, i + 1);
        
        if ((i + 1) % 2 == 1)
        {
            
            cout << char(186); }//186
        else 
            
            cout << char(182);  //182
    }

    // vẽ dòng ngang
    for (int i = 0; i < BOARD_SIZE_BOT * 2; i = i + 2)
    {
        GotoXY(LEFT, i);
        
        for (int j = 0; j < BOARD_SIZE_BOT * 4; j++)
        {
            if (j % 4 == 0)
                cout << char(197);
            else
                cout << char(196);
        }
    }

    // vẽ cột trái
    for (int i = 0; i < BOARD_SIZE_BOT * 2; i++)
    {
        GotoXY(LEFT, i + 1);
        
        if ((i + 1) % 2 == 1)
            cout << char(186);
        else
            cout << char(199);
    }

    // vẽ cột dọc
    for (int i = 1; i < BOARD_SIZE_BOT * 2; i = i + 2)
    {
        for (int j = 0; j < BOARD_SIZE_BOT * 4; j = j + 4)
        {
            GotoXY(j + LEFT, i);
            
            if (j == 0)
                continue;
            cout << char(179);
        }
    }

    // vẽ dòng đầu
    GotoXY(LEFT, 0);
    
    for (int i = 0; i < BOARD_SIZE_BOT * 4; i++)
    {
        if (i % 4 == 0)
            cout << char(209);
        else
            cout << char(205);
    }
    GotoXY(LEFT, 0); cout << char(201);
    GotoXY( BOARD_SIZE_BOT * 4 + LEFT, 0); cout << char(187);
    system("color F6");
   
    // vẽ dòng cuối
    GotoXY(LEFT, BOARD_SIZE_BOT * 2);
    for (int i = 0; i < BOARD_SIZE_BOT * 4; i++)
    {
        if (i % 4 == 0)
            cout << char(207);
        else
            cout << char(205);
    }

    GotoXY(LEFT, BOARD_SIZE_BOT * 2); cout << char(200);
    GotoXY( BOARD_SIZE_BOT * 4 + LEFT, BOARD_SIZE_BOT * 2);
    cout << char(188);
    //vẽ Giao Dien
    KhungGiaoDien();
    GotoXY(LEFT + 65, TOP + 9);
    cout << "So luot cua X la ";
    GotoXY(LEFT + 95, TOP + 9);
    cout << "So luot cua O la ";
    GotoXY(LEFT + 95, TOP + 10);
    //cout << "Luot cua ";
    GotoXY(2 + LEFT, 1);
}
void printBoard() {

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            gotoxy(j, i);
            if (i == real_cellX && j == real_cellY) {

                CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
                GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
                WORD saved_attributes = consoleInfo.wAttributes;

                // Đặt màu của văn bản là màu xanh lá
                SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | (saved_attributes & 0x00F0));

                cout << "X";

                // Khôi phục lại các thuộc tính màu ban đầu
                SetConsoleTextAttribute(hConsole, saved_attributes);

            }
            else {
                if (board[i][j].c == 'X') {
                    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
                    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
                    WORD saved_attributes = consoleInfo.wAttributes;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | (saved_attributes & 0x00F0));
                    cout << board[i][j].c;
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                }
                else {
                    CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
                    GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
                    WORD saved_attributes = consoleInfo.wAttributes;
                    SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (saved_attributes & 0x00F0));
                    cout << board[i][j].c;
                    SetConsoleTextAttribute(hConsole, saved_attributes);
                }

            }
        }
        cout << endl;
    }
    GotoXY(LEFT + 112, TOP + 9);
    cout << countO_bot;
    GotoXY(LEFT + 82, TOP + 9);
    cout << countX_bot;
}


bool checkWin(int x, int y, char player, bool ok) {
    int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
    vector <win> win_list;
    
    for (int d = 0; d < 4; ++d) {
        int count = 0;
        for (int i = -4; i <= 4; ++i) {
            int checkX = x + i * directions[d][0];
            int checkY = y + i * directions[d][1];
            if (checkX >= 0 && checkX < SIZE && checkY >= 0 && checkY < SIZE && board[checkX][checkY].c == player) {
                count++;
                win_list.push_back(win{ checkX, checkY });
                if (count == 5) {
                    if (ok == true) {
                        if (player == 'X') {
                            int j = 15;
                            playSound(13);
                            while (j > 0) {
                                j--;
                                Sleep(50);

                                
                                // Đặt lại màu cho ô 
                               //22 là vàng nền xanh 
                                Textcolor(FullRed);
                                for (int i = 0; i < 5; i++) {
                                    gotoxy(win_list[i].y, win_list[i].x);
                                    cout << ' ';
                                }
                                Sleep(125);
                                Textcolor(22);//22 là màu đen nền xanh 
                                for (int i = 0; i < 5; i++)
                                {
                                    gotoxy(win_list[i].y, win_list[i].x);
                                    cout << 'X';
                                }
                                

                            }
                            Sleep(400);
                        }
                        if (player == 'O') {
                            playSound(13);
                            int j = 10;
                            while (j > 0) {
                                j--;
                                Sleep(50);
                                Textcolor(FullYellow); // Đặt lại màu cho ô 
                                for (int i = 0; i < 5; i++)
                                {
                                    gotoxy(win_list[i].y, win_list[i].x);
                                    cout << 'O';
                                }
                                Sleep(75);
                                Textcolor(Blue);
                                for (int i = 0; i < 5; i++) {
                                    gotoxy(win_list[i].y, win_list[i].x);
                                    cout << ' ';
                                }

                            }

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

bool isDraw() {
    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j].c == ' ') {
                return false; // Còn ô trống, chưa hòa
            }
        }
    }
    return true; // Không còn ô trống, hòa
}
int Danh_gia_nuoc_di(int x, int y) {
    int score = 0;
    char players[2] = { 'X', 'O' };
    int weights[2] = { 1000, 1000 }; // Trọng số cho X và O

    for (int p = 0; p < 2; ++p) {
        board[x][y].c = players[p];

        // Kiểm tra chiến thắng
        if (checkWin(x, y, players[p],false)) {
            score += weights[p];
        }

        int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
        for (int d = 0; d < 4; ++d) {
            // Đánh giá dựa trên các quân cờ xung quanh và cơ hội tạo hàng thắng
            int cnt = 0;
            for (int i = -4; i <= 4; ++i) {
                int checkX = x + i * directions[d][0];
                int checkY = y + i * directions[d][1];
                if (checkX >= 0 && checkX < SIZE && checkY >= 0 && checkY < SIZE) {
                    if (board[checkX][checkY].c == players[p]) {
                        cnt++;
                        if (cnt >= 3) {
                            score += weights[p] / 2; // Tăng điểm nếu có 3 quân liền kề
                        }
                    }
                    else {
                        cnt = 0;
                    }
                }
            }
        }
       
     

       

        // Thuật toán leo đồi: đánh giá dựa trên cải thiện tình hình
        int improvementScore = 0;
        for (int d = 0; d < 4; ++d) {
            int playerCount = 0;
            // Kiểm tra quân cờ liên tiếp trong mỗi hướng
            for (int i = 1; i <= 4; ++i) {
                int checkX = x + i * directions[d][0];
                int checkY = y + i * directions[d][1];
                if (checkX >= 0 && checkX < SIZE && checkY >= 0 && checkY < SIZE && board[checkX][checkY].c == players[p]) {
                    playerCount++;
                }
                else {
                    break;
                }
            }
            // Càng nhiều quân liên tiếp, điểm cải thiện càng cao
            improvementScore += playerCount * playerCount; // Ví dụ: ưu tiên dài hơn chuỗi
        }
        score += improvementScore;
    }
    board[x][y].c = ' '; // Đặt lại ô trống sau đánh giá
    return score;
}


void Next_Move(bool level) {
    bestMoveX = -1;
    bestMoveY = -1;
    int bestScore = -1;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j].c == ' ') {
                int score;
                if (level == true)
                    score = Danh_gia_nuoc_di(i, j);
                else score = Danh_gia_nuoc_di_ez(i, j);
                if (score > bestScore) {
                    bestMoveX = i;
                    bestMoveY = j;
                    bestScore = score;
                }
            }
        }
    }

    board[bestMoveX][bestMoveY].c = 'X';
    real_cellX = bestMoveX;
    real_cellY = bestMoveY;
}
void LoadGameBot(string taptin) //Ham xu ly load game
{
  
 //system("color F0");
 // PlaySound(9);
   
    char t;
    ifstream L;
    L.open(taptin, ios::in);
    L >> characterXBot;
    L >> characterOPlayer;
    L >> LEVEL;
    L >> TheLastValueBot;
    L >> ScoreBot;
    L >> ScorePlayer;
    L >> Bot_Name;
    L >> Player_Name;
    TURN_B = false;
    //StartBoard();
    DrawBoardBOT();
    printBoard();
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
        {
            L >> t;
            if (t == '2')
            {
                board[i][j].c = -1;
                GotoXY(board[i][j].x, board[i][j].y);
                Textcolor(252);
                cout << 'X';
            }
            else if (t == '1')
            {
                board[i][j].c = 1;
                GotoXY(board[i][j].x, board[i][j].y);
                Textcolor(249);
                cout << 'O';
            }
        }
    L.close();
    //L >> _TURN;
    
   // StartGame(&countX, &countO);
    // StartBoard();
   // DrawBoardBOT();
    //printBoard();
    if (TheLastValueBot == false)
        Xturn();
    else
        Oturn();
   GotoXY(6, 2);
   TURN_B = TheLastValueBot;
   // bool validEnter = true;
    int h = 1;
    play_PvC(LEVEL);
}
bool checkFile_pvc(string taptin) {
    ifstream input("CurFile.txt");
    while (!input.eof()) {
        string line;
        getline(input, line);
        if (taptin.compare(line) == 0) {
            return false;
        }
    }
    return true;
}
void Name_file_bot(const char* s, string &taptin) {
    getline(cin, taptin);
    cin.ignore();
    while (taptin.length() > 20 || !checkFile_pvc(taptin)) {
        GotoXY(7, 34);
        for (int i = 0; i < (int)taptin.length(); i++) {
            cout << '\b' << ' ' << '\b';
        }
        GotoXY(5, 36);
        cout << "Not Valid!!!";
        GotoXY(5, 34);
        getline(cin, taptin);
    }

    ofstream outFile(s, ios::app);
    if (!outFile.is_open()) {
        cerr << "Khong the mo tap tin " << s << std::endl;
    }
    else {
        outFile << taptin << endl;
        outFile.close();
    }
}

void SaveGame_ESC_BOT() //Ham xu ly save game sau khi nhan ESC
{
    int command;
    Textcolor(240);
    GotoXY(5, 32); cout << "DO you want to save game ?                                       ";
    GotoXY(5, 33); cout << "   Yes : Press Y ";
    GotoXY(5, 34); cout << "   No :  Press T ";
    command = toupper(_getch());
    while (command != 'Y' && command != 'T') {
        command = toupper(_getch());
    }
    if (command == 'Y')
    {
        GotoXY(5, 32); cout << "                                                                    ";
        GotoXY(5, 34); cout << "                                         ";
        GotoXY(5, 33); cout << "Please name your file :...    " << endl;
        GotoXY(5, 34); cout << " FileName: ";
        string taptin;
        const char* filecur = "CurBot.txt";
        Name_file_bot(filecur,taptin);
        ofstream S;
        S.open(taptin, ios::out);
        S << characterXBot << endl;
        S << characterOPlayer << endl;
        S << LEVEL << endl;
        S << TheLastValueBot << endl;
        
        // S << _TURN;
         S << ScoreBot << endl;
         S << ScorePlayer << endl;
         S << Bot_Name << endl;
         S << Player_Name << endl;
        for (int i = 0; i < SIZE; i++)
            for (int j = 0; j < SIZE; j++)
            {
                if (board[i][j].c == -1)
                    S << 2;
                else
                    S << board[i][j].c;
            }
        S.close();
        ScreenStartGame(99);
    }
    else if (command == 'T') {
        ScreenStartGame(99);
    }
}

void play_PvC(bool level) {
    HienCharacter(characterXBot, characterOPlayer, characterXBotFile, characterOPlayerFile);
    GotoXY(110 + LEFT, 4);
    Textcolor(Blue);
    cout << Player_Name;
    GotoXY(80 + LEFT, 4);
    Textcolor(Red);
    cout << Bot_Name;
    Textcolor(Black);
    GotoXY(65 + LEFT, 5);
    cout << "Score";
    GotoXY(75 + LEFT, 5);
    cout << ScoreBot;
    GotoXY(98 + LEFT, 5);
    cout << "Score";
    GotoXY(108 + LEFT, 5);
    cout << ScorePlayer;
    while (true) {
        gotoxy(cursorY, cursorX + SIZE + 1);

        char move;
        while (true) {
            printBoard();
            gotoxy(cursorY, cursorX);
            CONSOLE_SCREEN_BUFFER_INFO consoleInfo;
            GetConsoleScreenBufferInfo(hConsole, &consoleInfo);
            WORD saved_attributes = consoleInfo.wAttributes;
            SetConsoleTextAttribute(hConsole, FOREGROUND_BLUE | (saved_attributes & 0x00F0));
            cout << 'O';
            move = _getch();
            gotoxy(cursorY, cursorX);
            cout << board[cursorX][cursorY].c;
            if (move == 'm' || move == 'M') On_Of_sound();
            if (move == 'q' || move == 'Q') nn();
            if (move == 'w' && cursorX > 0) { cursorX--; playSound(1); }
            if (move == 's' && cursorX < SIZE - 1) { cursorX++; playSound(1); }
            if (move == 'a' && cursorY > 0) { cursorY--; playSound(1); }
            if (move == 'd' && cursorY < SIZE - 1) { cursorY++; playSound(1); }
            if (move == 27) { // AskContinueBOTEasy(); 
                AskcontinueBot();
             //   SaveGame_ESC_BOT();
                ScreenStartGame(99);
                return;
            }
            if (move == '\r' && board[cursorX][cursorY].c == ' ') {
                playSound(2);
                board[cursorX][cursorY].c = 'O';
                countO_bot++;
                Xturn();
                TURN_B = !TURN_B;
                break;
            }
        }
        printBoard();
        GotoXY(LEFT + 112, TOP + 9);
        cout << countX_bot;
        if (checkWin(cursorX, cursorY, 'O', true)) {
            gotoxy(0, SIZE + 4);
            Sleep(1000);
            YOUWIN();
        
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    board[i][j].x = i;
                    board[i][j].y = j;
                    board[i][j].c = ' ';
                }
            }
            TURN_B = true;
            countX_bot = 0; countO_bot = 0;
            ScorePlayer++;
            //AskContinueBOTEasy();
            AskcontinueBot();
           
            break;
        }
        Next_Move(level);
        countX_bot++;
       
        Oturn();
        TURN_B = !TURN_B;
        printBoard();
        if (checkWin(bestMoveX, bestMoveY, 'X', true)) {
            gotoxy(0, SIZE + 4);
            Sleep(1000);
            system("Cls");
            ScoreBot++;
            for (int i = 0; i < SIZE; i++) {
                for (int j = 0; j < SIZE; j++) {
                    board[i][j].x = i;
                    board[i][j].y = j;
                    board[i][j].c = ' ';
                }
            }
            TURN_B = true;
            countX_bot = 0; countO_bot = 0;
            COMPUTERWIN();
            //AskContinueBOTEasy();
            AskcontinueBot();
            break;
        }
        /*else
            cout << "Draw" << endl;*/
        else if (isDraw()) {
            DRAW();
            break;
        }
    }
}
void nothing() {

}
void PlayerVsBOT() {
    LEVEL = true;
   // Sub_Loadingbar();
 
        PVCBAR();
    system("cls");
    playSound(9);
    StartBoard();
    AskNameBot();
    system("cls");
    XuLyChacracter(characterXBot, characterOPlayer, timesBot, nothing, ContinueGameBot);
    DrawBoardBOT();
    printBoard();
    
    //system("color F0");
   
    play_PvC(true);

}

int Danh_gia_nuoc_di_ez(int x, int y) {
    int score = 0;
    char players[2] = { 'X', 'O' };
    int weights[2] = { 1000, 300 }; // Trọng số cho X và O

    for (int p = 0; p < 2; ++p) {
        board[x][y].c = players[p];

        // Kiểm tra chiến thắng
        if (checkWin(x, y, players[p],false)) {
            score += weights[p];
        }

        int directions[4][2] = { {1, 0}, {0, 1}, {1, 1}, {1, -1} };
        for (int d = 0; d < 4; ++d) {
            // Đánh giá dựa trên các quân cờ xung quanh và cơ hội tạo hàng thắng
            int cnt = 0;
            for (int i = -4; i <= 4; ++i) {
                int checkX = x + i * directions[d][0];
                int checkY = y + i * directions[d][1];
                if (checkX >= 0 && checkX < SIZE && checkY >= 0 && checkY < SIZE) {
                    if (board[checkX][checkY].c == players[p]) {
                        cnt++;
                        if (cnt >= 3) {
                            score += weights[p] / 2; // Tăng điểm nếu có 3 quân liền kề
                        }
                    }
                    else {
                        cnt = 0;
                    }
                }
            }
        }






    }
    board[x][y].c = ' '; // Đặt lại ô trống sau đánh giá
    return score;
}


void AskNameBot() {
 // AskName(1, Green, " Player ", " BOT "); 
    AskName(1, Blue, "Player", "Bot", Player_Name, Bot_Name);
}


void PlayerVsBOTEASY() {
    LEVEL = false;
  //  Sub_Loadingbar();
    int i = 0;
    
        PVCBAR();
        i++;
    
    system("cls");
    playSound(9);
    
    StartBoard();
  AskNameBot();
  system("cls");
  XuLyChacracter(characterXBot, characterOPlayer, timesBot, nothing, ContinueGameBot);
    DrawBoardBOT();
    printBoard();
    
    play_PvC(false);
}
void ContinueGameBot() {
    //PVCBAR();
    system("cls");
    playSound(9);
  //StartBoard();
    DrawBoardBOT();
    printBoard();
    play_PvC(LEVEL);
}