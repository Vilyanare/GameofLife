#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

/**/

//Function that initializes a board to all 0's
int *dead_state (int *board, int height, int width) {
    memset(board, 0, (height * width) * sizeof(int));
    return board;
}

//Function that initializes a board with random states
int *random_state (int *board, int height, int width) {
    srand(time(0));
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            board[(x * width) + y] = rand() % 2;
        }
    }
    return board;
}

//Function to pretty print a board state.  1 = # 0 = " "
void render_board(int *board, int height, int width) {
    for (int x = 0; x < width + 2; x++) {
        cout << "-";
    }
    cout << endl;
    for (int x = 0; x < width; x++)  {
        cout << "|";
        for (int y = 0; y < height; y++) {
            cout << ((board[(x * width) + y]) ? "#" : " ");
        }
        cout << "|" << endl;
    }
    for (int x = 0; x < width + 2; x++) {
        cout << "-";
    }
    cout << endl;
}

int main () {
    int width = 5, height = 5;
    int board[width][height];
    random_state(*board, height, width);
    render_board(*board, height, width);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            cout << board[x][y] << " ";
        }
        cout << endl;
    }
    return 0;
}
