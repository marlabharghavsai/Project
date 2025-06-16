#include <iostream>
using namespace std;

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char turn = 'X';
int row, col;

bool draw = false;

void display_board() {
    system("cls");
    cout << "TIC-TAC-TOE\n";
    for (int i = 0; i < 3; i++) {
        cout << " ";
        for (int j = 0; j < 3; j++) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        if (i < 2) cout << "\n-----------\n";
    }
    cout << "\n";
}

void player_turn() {
    int choice;
    cout << "Player [" << turn << "] turn. Enter cell number (1-9): ";
    cin >> choice;

    switch (choice) {
        case 1: row = 0; col = 0; break;
        case 2: row = 0; col = 1; break;
        case 3: row = 0; col = 2; break;
        case 4: row = 1; col = 0; break;
        case 5: row = 1; col = 1; break;
        case 6: row = 1; col = 2; break;
        case 7: row = 2; col = 0; break;
        case 8: row = 2; col = 1; break;
        case 9: row = 2; col = 2; break;
        default: cout << "Invalid\n"; return;
    }

    if (board[row][col] != 'X' && board[row][col] != 'O') {
        board[row][col] = turn;
        turn = (turn == 'X') ? 'O' : 'X';
    } else {
        cout << "Cell already filled! Try again\n";
        player_turn();
    }
}

bool game_over() {
    for (int i = 0; i < 3; i++)
        if (board[i][0] == board[i][1] &&
            board[i][0] == board[i][2]) return false;

    for (int i = 0; i < 3; i++)
        if (board[0][i] == board[1][i] &&
            board[0][i] == board[2][i]) return false;

    if (board[0][0] == board[1][1] && board[0][0] == board[2][2]) return false;
    if (board[0][2] == board[1][1] && board[0][2] == board[2][0]) return false;

    draw = true;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (board[i][j] != 'X' && board[i][j] != 'O') draw = false;

    return !draw;
}

int main() {
    while (game_over()) {
        display_board();
        player_turn();
    }
    display_board();
    if (!draw) cout << "Player " << (turn == 'X' ? 'O' : 'X') << " wins!\n";
    else cout << "Game is a draw!\n";
}
