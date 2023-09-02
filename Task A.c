#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Incorrect number of arguments!\n");
        return 1;
    }

    char initial_board[26];
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
