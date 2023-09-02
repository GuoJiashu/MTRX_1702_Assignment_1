#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM_BOARD_SPACES 25

int main(int argc, char *argv[]) {
    if (argc != 5) {
        printf("Incorrect number of arguments!\n");
        return 1;
    }

    char initial_board[NUM_BOARD_SPACES + 1];
    strncpy(initial_board, argv[1], 25);
    initial_board[25] = '\0';

    int player = atoi(argv[2]);
    int row = atoi(argv[3]);
    int col = atoi(argv[4]);

    if (player != 1 && player != 2){
        printf("Invalid move data!\n");
        return 1;
    }

    if (row < 0 || row > 4 || col < 0 || col > 4){
        printf("Invalid move data!\n");
        return 1;
    }

    int index = row * 5 + col;

    if (initial_board[index] == 'X' || initial_board[index] == 'O' || initial_board[index] == '*') {
        printf("Invalid move: cell is occupied!\n");
        return 1;
    }

    char playerToken = (player == 1) ? 'X' : 'O';
    initial_board[index] = playerToken;

    for (int i = 0; i < 25; i++) {
        char c = initial_board[i];
        if (c != 'X' && c != 'O' && c != '*' && c != 'E') {
            printf("Invalid initial board data!\n");
            return 1;
        }
    }

    int directions[8][2] = {
            {-1, 0}, {-1, -1}, {-1, 1},
            {0, -1},                        {0, 1},
            {1, 0},  {1, -1}, {1, 1}
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

    int i, j;

    printf("  01234\n");
    printf(" *******\n");

    int k = 0;

    for (i = 0; i < 5; i++) {
        printf("%d", i);
        for (j = 0; j < 7; j++) {
            if (j == 0 || j == 6) {
                printf("*");
            } else {
                char c = initial_board[k];
                if (c == 'E'){
                    printf(" ");
                }else{
                    printf("%c", initial_board[k]);
                }
                k++;
            }
        }
        printf("\n");
    }

    printf(" *******\n");

    return 0;
}
