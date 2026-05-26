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
// 6. Check win condition
bool checkWin(char board[SIZE][SIZE], char player) {
    for (int i = 0; i < SIZE; i++) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
    }
    for (int j = 0; j < SIZE; j++) {
        if (board[0][j] == player && board[1][j] == player && board[2][j] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}
// 7. Check draw condition
bool isBoardFull(char board[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}
// 8. Switch player
char switchPlayer(char activePlayer) {
    return (activePlayer == 'X') ? 'O' : 'X';
}
int main() {
    char board[SIZE][SIZE];
    char activePlayer = 'X';
    int row, col;
    bool validMove = false;
    bool gameOver = false;
    char winner = ' ';
    char playAgain = 'y';
    // 10. Replay loop
    while (playAgain == 'y' || playAgain == 'Y') {
        // 1. Program start + 2. Board initialization
        initializeBoard(board);
        activePlayer = 'X';
        gameOver = false;
        winner = ' ';
        while (!gameOver) {
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
            // 6. Check win condition
            if (checkWin(board, activePlayer)) {
                gameOver = true;
                winner = activePlayer;
            }
            // 7. Check draw condition
            else if (isBoardFull(board)) {
                gameOver = true;
            }
            // 8. Switch player
            else {
                activePlayer = switchPlayer(activePlayer);
            }
        }
        // 9. End of round
        displayBoard(board);
        if (winner != ' ') {
            printf("Player %c wins!\n", winner);
        } else {
            printf("It's a draw!\n");
        }
        // 10. Replay option
        printf("Play again? (y/n): ");
        scanf(" %c", &playAgain);
    }
    return 0;
}
