#include <stdio.h>
#include <stdbool.h>

#define SIZE 3

void initializeBoard(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            board[i][j] = ' ';
        }
    }
}

void displayBoard(char board[SIZE][SIZE]) {
    printf("\n");
    for (int i = 0; i < SIZE; i++) {
        printf(" %c | %c | %c \n", board[i][0], board[i][1], board[i][2]);
        if (i < SIZE - 1) {
            printf("---+---+---\n");
        }
    }
    printf("\n");
}

bool isValidMove(char board[SIZE][SIZE], int row, int col) {
    if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) {
        return false;
    }

    if (board[row][col] != ' ') {
        return false;
    }

    return true;
}

void updateBoard(char board[SIZE][SIZE], int row, int col, char player) {
    board[row][col] = player;
}

int main() {
    char board[SIZE][SIZE];
    char activePlayer = 'X';
    int row, col;
    bool validMove = false;

    // 1. Program start + 2. Board initialization
    initializeBoard(board);

    // 3. Display game state
    displayBoard(board);

    // 4. Player input (loop until valid)
    do {
        printf("Player %c, enter row and column (1-3): ", activePlayer);
        scanf("%d %d", &row, &col);

        row--;
        col--;

        validMove = isValidMove(board, row, col);

        if (!validMove) {
            printf("Invalid move. Try again.\n");
        }

    } while (!validMove);

    // 5. Update board
    updateBoard(board, row, col, activePlayer);

    displayBoard(board);

    return 0;
}