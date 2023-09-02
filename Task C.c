#include <stdio.h>
#include <string.h>

int isValidMove(const char *initial_board, int row, int col) {
    if (row < 0 || row > 4 || col < 0 || col > 4) {
        printf("Invalid move data!\n");
        return 0;
    }

    int index = row * 5 + col;

    if (initial_board[index] == 'X' || initial_board[index] == 'O' || initial_board[index] == '*') {
        return 0;
    }

    return 1;
}

void updateSurroundingCells(char *initial_board, int row, int col) {
    int directions[8][2] = {
            {-1, 0}, {-1, -1}, {-1, 1},
            {0, -1}, {0, 1},
            {1, 0}, {1, -1}, {1, 1}
    };

    for (int d = 0; d < 8; d++) {
        int newRow = row + directions[d][0];
        int newCol = col + directions[d][1];

        if (newRow >= 0 && newRow < 5 && newCol >= 0 && newCol < 5) {
            int newIndex = newRow * 5 + newCol;
            if (initial_board[newIndex] == 'E') {
                initial_board[newIndex] = '*';
            }
        }
    }
}

void displayBoard(const char *initial_board) {
    printf("  01234\n");
    printf(" *******\n");

    int k = 0;

    for (int i = 0; i < 5; i++) {
        printf("%d", i);
        for (int j = 0; j < 7; j++) {
            if (j == 0 || j == 6) {
                printf("*");
            } else {
                char c = initial_board[k];
                if (c == 'E') {
                    printf(" ");
                } else {
                    printf("%c", initial_board[k]);
                }
                k++;
            }
        }
        printf("\n");
    }

    printf(" *******\n");
}

int isGameOver(const char *initial_board) {
    for (int i = 0; i < 25; i++) {
        if (initial_board[i] == 'E') {
            return 0;
        }
    }
    return 1;
}

int main(int argc, char *argv[]) {
    printf("Welcome to Bricker!\n");

    char initial_board[26];
    memset(initial_board, 'E', 25);
    initial_board[25] = '\0';

    if (argc == 2 && strlen(argv[1]) == 25) {
        strncpy(initial_board, argv[1], 25);
    }

    displayBoard(initial_board);

    int currentPlayer = 1;
    int row, col;
    int lastPlayer = 0;

    while (!isGameOver(initial_board)) {

        printf("Player %d turn: ", currentPlayer);
        scanf("%d %d", &row, &col);

        if (isValidMove(initial_board, row, col)) {
            char playerToken = (currentPlayer == 1) ? 'X' : 'O';
            int index = row * 5 + col;
            initial_board[index] = playerToken;
            updateSurroundingCells(initial_board, row, col);
            lastPlayer = currentPlayer;
            currentPlayer = (currentPlayer == 1) ? 2 : 1;

            displayBoard(initial_board);
        } else {
            printf("Invalid Move!\n");
            continue;
        }
    }

    displayBoard(initial_board);
    if (lastPlayer != 0) {
        printf("Player %d Wins!\n", lastPlayer);
    }

    return 0;
}
