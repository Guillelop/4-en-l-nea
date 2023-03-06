#include <iostream>
#include <vector>
using namespace std;

const int ROWS = 6;
const int COLS = 7;
const char EMPTY = ' ';
const char PLAYER_1 = 'X';
const char PLAYER_2 = 'O';

vector<vector<char>> board;

void init_board() {
    board.resize(ROWS);
    for (int i = 0; i < ROWS; i++) {
        board[i].resize(COLS);
        for (int j = 0; j < COLS; j++) {
            board[i][j] = EMPTY;
        }
    }
}

void print_board() {
    
    cout<<"    ###                                        ###       ##"<<endl;
    cout<<"   ## ##                                         ##"<<endl;
    cout<<"  ##  ##             ####    #####               ##      ###     #####     ####     ####"<<endl;
    cout<<" ##   ##            ##  ##   ##  ##              ##       ##     ##  ##   ##  ##       ##"<<endl;
    cout<<" ########           ######   ##  ##              ##       ##     ##  ##   ######    #####"<<endl;
    cout<<"     ##            ##       ##  ##              ##       ##     ##  ##   ##       ##  ##"<<endl;
    cout<<"     ##             #####   ##  ##             ####     ####    ##  ##    #####    #####"<<endl<<endl;

    for (int i = ROWS - 1; i >= 0; i--) {
        cout << "|";
        for (int j = 0; j < COLS; j++) {
            cout << board[i][j] << "|";
        }
        cout << endl;
    }
    cout << "---------------" << endl;
    cout << "|1|2|3|4|5|6|7|" << endl;
}

bool is_valid_move(int col) {
    if (col < 0 || col >= COLS) {
        return false;
    }
    if (board[ROWS - 1][col] != EMPTY) {
        return false;
    }
    return true;
}

void make_move(int col, char player) {
    for (int i = 0; i < ROWS; i++) {
        if (board[i][col] == EMPTY) {
            board[i][col] = player;
            break;
        }
    }
}

bool check_win(char player) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == player && board[i][j+1] == player &&
                board[i][j+2] == player && board[i][j+3] == player) {
                return true;
            }
        }
    }
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player && board[i+1][j] == player &&
                board[i+2][j] == player && board[i+3][j] == player) {
                return true;
            }
        }
    }
    for (int i = 0; i <= ROWS - 4; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == player && board[i+1][j+1] == player &&
                board[i+2][j+2] == player && board[i+3][j+3] == player) {
                return true;
            }
        }
    }
    for (int i = 3; i < ROWS; i++) {
        for (int j = 0; j <= COLS - 4; j++) {
            if (board[i][j] == player && board[i-1][j+1] == player &&
                board[i-2][j+2] == player && board[i-3][j+3] == player) {
                return true;
        }
    }
}
return false;
}

bool is_board_full() {
for (int i = 0; i < ROWS; i++) {
for (int j = 0; j < COLS; j++) {
if (board[i][j] == EMPTY) {
return false;
}
}
}
return true;
}

int main() {
init_board();
bool player_1_turn = true;
bool game_over = false;
while (!game_over) {
print_board();
char player = player_1_turn ? PLAYER_1 : PLAYER_2;
int col;
cout << "Jugador " << player << ", introduzca un número del 1 al 7: ";
cin >> col;
col--;
if (!is_valid_move(col)) {
cout << "movimiento inválido, por favor, inténtelo de nuevos." << endl;
continue;
}
make_move(col, player);
if (check_win(player)) {
cout << "El jugador:  " << player << " ha ganado!!!" << endl;
game_over = true;
} else if (is_board_full()) {
cout << "Empate!!!" << endl;
game_over = true;
} else {
player_1_turn = !player_1_turn;
}
}
print_board();
return 0;
}

//Hecho por Guillem Munné López 1ºASIR©
