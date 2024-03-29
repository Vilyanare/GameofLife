#include<iostream>
#include<cstdlib>
#include<ctime>
#include<vector>
using namespace std;

/*GAME OF LIFE
Simulation of cells based on 4 rules
1. Any live cell with 0 or 1 live neighbors becomes dead, because of underpopulation
2. Any live cell with 2 or 3 live neighbors stays alive, because its neighborhood is just right
3. Any live cell with more than 3 live neighbors becomes dead, because of overpopulation
4. Any dead cell with exactly 3 live neighbors becomes alive, by reproduction*/

//Function that sets a board to all 0's
vector<vector<int>> dead_state (vector<vector<int>> board) {
    for(int x = 0; x < board.size(); x++) {
        for (int y = 0; y < board[0].size(); y++) {
            board[x][y] = 0;
        }
    }
    return board;
}

//Function that sets all board variables to random states
vector<vector<int>> random_state (vector<vector<int>> board) {
    srand(time(0));
    for (int x = 0; x < board.size(); x++) {
        for (int y = 0; y < board[0].size(); y++) {
            board[x][y] = abs(rand() % 2);
        }
    }
    return board;
}

//Function to pretty print a board state.  1 = # 0 = " "
void render_board(vector<vector<int>> board) {
    for (int x = 0; x < board.size() + 2; x++) {
        cout << "-";
    }
    cout << endl;
    for (int x = 0; x < board.size(); x++)  {
        cout << "|";
        for (int y = 0; y < board[0].size(); y++) {
            char state = board[x][y] ? '#' : ' ';
            cout << state;
        }
        cout << "|" << endl;
    }
    for (int x = 0; x < board.size() + 2; x++) {
        cout << "-";
    }
    cout << endl;
}

//Function that calculates the next board based on the 4 rules and updates board.
vector<vector<int>> next_board_state(vector<vector<int>> board) {
    return board;
}

int main () {
    const int width = 5, height = 5;
    vector<int> row(width, 0);
    vector<vector<int>> board(height, row);
    board = dead_state(board);
    board = random_state(board);
    render_board(board);
    board = next_board_state(board);
    render_board(board);
    return 0;
}
