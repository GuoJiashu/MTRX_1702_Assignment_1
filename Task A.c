#include <stdio.h>
// Deal with strings through this library
#include <string.h>

// Accept arguments from the terminal
// argc represents the number of arguments, argv[] here accept the value entered from the terminal
int main(int argc, char *argv[]) {
    // Here to judge the number of arguments, if the number is not equal to 2, it will print a message
    if (argc != 2) {
        printf("Incorrect number of arguments!\n");
        // When the code finds not correct inputs here, it will quit and return 1 which means not normal "shut down" or "error" occurs here
        return 1;
    }

    // Here creat a string, and it stores 26 characters
    char initial_board[26];
    // Use function strncpy to copy the information from the second arguments
    // Only get 25 characters from the arguments because our game is 5x5, it will make sure we just deal with 25 characters
    strncpy(initial_board, argv[1], 25);
    // It is a important one, it set an ending character(26th) '\0', the purpose is to make that the data stored in initial_board is a valid string, because the string in C must end with NULL
    initial_board[25] = '\0';
    // This is a loop, it will over all the character inside the initial_board, and to check are they valid characters
    // If find any character not 'X' or 'O' or '*', it will print a message and then return 1(same function like above)

    for (int i = 0; i < 25; i++) {
        char c = initial_board[i];
        if (c != 'X' && c != 'O' && c != '*' && c != 'E') {
            printf("Invalid initial board data!\n");
            return 1;
        }
    }

    // Produce game board
    // This is the declaration for the variable will used in the next
    int i, j;

    // The outer frame
    printf("  01234\n");
    printf(" *******\n");

    // This is the declaration for the variable will used in the next
    // Index for the loop of initial_board
    int k = 0;

    // For loop here is to produce the board
    // It will over 5 times, which means the structure of the board 5x5
    for (i = 0; i < 5; i++) {
        // This is the number beside the board
        printf("%d", i);
        // Actually we have 7 columns, so the loop need run over 7 times
        for (j = 0; j < 7; j++) {
            // It tells when to print *, the outer '*' for the two side
            if (j == 0 || j == 6) {
                printf("*");
            } else {
                // Here is to make special board, from the previous inputs, the user may input 'X' or 'O' or '*' or 'E'
                char c = initial_board[k];
                if (c == 'E'){
                    // If entered 'E' then leave a space there
                    printf(" ");
                }else{
                    // If 'O', 'X', '*', print them
                    printf("%c", initial_board[k]);
                }
                k++;
            }
        }
        printf("\n");
    }

    // Print the base
    printf(" *******\n");

    return 0;
}
