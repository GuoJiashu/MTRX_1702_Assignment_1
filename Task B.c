#include <stdio.h>
// Deal with strings through this library
#include <string.h>
// Deal with strings through this library
#include <stdlib.h>

// Accept arguments from the terminal
// argc represents the number of arguments, argv[] here accept the value entered from the terminal
int main(int argc, char *argv[]) {
    // Here, to judge the number of arguments, if the number is not equal to two, it will print a message
    if (argc != 5) {
        printf("Incorrect number of arguments!\n");
        // When the code finds not correct inputs here, it will quit and return 1 which means not normal "shut down" or
        // "error" occurs here
        return 1;
    }

    // Here creat a string, and it stores 26 characters
    char initial_board[26];
    // Use function strncpy to copy the information from the second arguments
    // Only get 25 characters from the arguments because our game is 5x5, will make sure we just deal with 25 characters
    strncpy(initial_board, argv[1], 25);
    // It is an important one, it set an ending character(26th) '\0', the purpose is to make that the data stored in
    // initial_board is a valid string, because the string in C must end with NULL
    initial_board[25] = '\0';

    // Atoi function converts arguments from strings to integers
    int player = atoi(argv[2]);
    int row = atoi(argv[3]);
    int col = atoi(argv[4]);

    // The following two if sentences are to test the correct move data
    if (player != 1 && player != 2){
        printf("Invalid move data!\n");
        return 1;
    }

    if (row < 0 || row > 4 || col < 0 || col > 4){
        printf("Invalid move data!\n");
        return 1;
    }

    // This will detect the exact position about what has user input.
    int index = row * 5 + col;

    // Check if the cell is already occupied
    if (initial_board[index] == 'X' || initial_board[index] == 'O' || initial_board[index] == '*') {
        printf("Invalid move: cell is occupied!\n");
        return 1;
    }

    // Determine which symbol ('X', 'O') will be put there
    char playerToken = (player == 1) ? 'X' : 'O';
    // This will put the one of the symbol to the position that asked
    initial_board[index] = playerToken;

    // This is a loop, it will over all the character inside the initial_board, and to check are they valid characters
    for (int i = 0; i < 25; i++) {
        char c = initial_board[i];
        if (c != 'X' && c != 'O' && c != '*' && c != 'E') {
            printf("Invalid initial board data!\n");
            return 1;
        }
    }
    
    // This is a 2-D array, to represent eight different directions around the given position
    int directions[8][2] = {
            {-1, 0}, {-1, -1}, {-1, 1},
            {0, -1},                        {0, 1},
            {1, 0},  {1, -1}, {1, 1}
    };

    // Update the surrounding cells
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

    // Produces game board
    int i, j;

    // The outer frame
    printf("  01234\n");
    printf(" *******\n");

    // This is the declaration for the variable will be used in the next
    // Index for the loop of initial_board
    int k = 0;

    // For loop here is to produce the board
    // It will over five times, which means the structure of the board 5x5
    for (i = 0; i < 5; i++) {
        // This is the number beside the board
        printf("%d", i);
        // Actually, we have seven columns, so the loop needs to run over seven times
        for (j = 0; j < 7; j++) {
            // It tells when to print *, the outer '*' for the two sides
            if (j == 0 || j == 6) {
                printf("*");
            } else {
                // Here is to make special board; from the previous inputs, the user may input 'X' or 'O' or '*' or 'E'
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
