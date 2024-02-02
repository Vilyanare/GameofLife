#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

int *dead_state (int *board, int height, int width) {
    memset(board, 0, (height * width) * sizeof(int));
    return board;
}

int *random_state (int *board, int height, int width) {
    srand(time(0));
    board = dead_state(board, height, width);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            board[(x * width) + y] = rand() % 2;
        }
    }
    return board;
}

int main () {
    int width = 5, height = 5;
    int board[width][height];
    random_state(*board, width, height);
    for (int x = 0; x < width; x++) {
        for (int y = 0; y < height; y++) {
            cout << board[x][y] << " ";
        }
        cout << endl;
    }
    return 0;
}
