#include <stdio.h>
#include <string.h>

#define NUM_BOARD_SPACES 25

int main(int argc, char *argv[]) {
    // Check the number of command line arguments
    if (argc != 2) {
        printf("Incorrect number of arguments!\n");
        return 1;
    }

    // Store initial data of board with the string array (maximum 25 characters)
    char initial_board[NUM_BOARD_SPACES + 1];
    // Copy strings from command line input to initial_board
    strncpy(initial_board, argv[1], 25);
    initial_board[25] = '\0';

    for (int i = 0; i < 25; i++) {
        char c = initial_board[i];
        if (c != 'X' && c != 'O' && c != '*' && c != 'E') {
            printf("Invalid initial board data!\n");
            return 1;
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
