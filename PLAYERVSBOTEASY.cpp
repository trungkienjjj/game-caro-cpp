#include "PLAYERVSBOTEASY.h"
int Danh_gia_nuoc_di_ez(int x, int y) {
    int score = 0;
    char players[2] = { 'X', 'O' };
    int weights[2] = { 1000, 300 }; // Trọng số cho X và O

    for (int p = 0; p < 2; ++p) {
        board[x][y].c = players[p];

        // Kiểm tra chiến thắng
        if (checkWin(x, y, players[p])) {
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
void AI_move_ez() {
    bestMoveX = -1;
    bestMoveY = -1;
    int bestScore = -1;

    for (int i = 0; i < SIZE; ++i) {
        for (int j = 0; j < SIZE; ++j) {
            if (board[i][j].c == ' ') {
                int score = Danh_gia_nuoc_di_ez(i, j);
                if (score > bestScore) {
                    bestMoveX = i;
                    bestMoveY = j;
                    bestScore = score;
                }
            }
        }
    }

    board[bestMoveX][bestMoveY].c = 'X';
}
void PlayerVsBOT() {
    playSound(9);
    StartBoard();
    DrawBoardBOT();
    printBoard();

    system("color F0");
    while (true) {
        gotoxy(cursorY, cursorX + SIZE + 1);

        char move;
        while (true) {
            gotoxy(cursorY, cursorX);
            cout << 'O';
            move = _getch(); playSound(1);
            gotoxy(cursorY, cursorX);
            cout << board[cursorX][cursorY].c;
            if (move == 'w' && cursorX > 0) cursorX--;
            if (move == 's' && cursorX < SIZE - 1) cursorX++;
            if (move == 'a' && cursorY > 0) cursorY--;
            if (move == 'd' && cursorY < SIZE - 1) cursorY++;
            if (move == 27) AskContinueBOTEasy();
            if (move == '\r' && board[cursorX][cursorY].c == ' ') {
                board[cursorX][cursorY].c = 'O';
                break;
            }
        }

        printBoard();

        if (checkWin(cursorX, cursorY, 'O')) {
            gotoxy(0, SIZE + 4);
            cout << "You win!" << endl;
            YOUWIN();
            AskContinueBOTEasy();   //Đoạn này giữ tên ez đi, nhưng mà đổi lại bên hard
            break;
        }
        AI_move_ez();

        printBoard();
        if (checkWin(bestMoveX, bestMoveY, 'X')) {
            gotoxy(0, SIZE + 4);
            cout << "Computer wins!" << endl;
            system("Cls");
            COMPUTERWIN();
            AskContinueBOTEasy();
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


