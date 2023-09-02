#include <stdio.h>
#include <string.h>

/*!
  This program implements a simple two-player game called "Bricker" played on a 5x5 grid. This program let two players to
  play take turns on a 5x5 game board. Different player is represented by 'X' and 'O'. The player needs to start game on
  terminal (command line). The game starts with an empty or a customized board, the customized information is from command
  lines. When program starts, it asks for the input from players, players enter the specified data of row and column. The
  program checks the input to ensure valid moves and checks for game termination conditions. If a player's move is valid,
  their symbol is placed on the give position on the board, and the surrounding cells are updated accordingly. The game
  continues until there are no more empty cells. The program will notice players whether the inputs are valid or not. Upon game
  completion, it identifies the winner. The current game board is displayed after each move and then asking for the input
  from another player. The program structure separates functionality into modular functions, promoting readability and maintainability.
 */

// The size of the board
#define NUM_BOARD_SPACES 25

// Check the valid of movements
int isValidMove(const char *initial_board, int row, int col) {
    if (row < 0 || row > 4 || col < 0 || col > 4) {
        return 0;
    }

    int index = row * 5 + col;

    if (initial_board[index] == 'X' || initial_board[index] == 'O' || initial_board[index] == '*') {
        return 0;
    }

    return 1;
}

// Update the surrounding cells
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

// Show the game-board
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

// Check whether the game over or not
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

    char initial_board[NUM_BOARD_SPACES + 1];
    // Initialize the board
    memset(initial_board, 'E', 25);
    initial_board[25] = '\0';

    // If the number of arguments is two and the length of second argument is twenty-five, customize the initial board
    // using parameters from command lines
    if (argc == 2 && strlen(argv[1]) == 25) {
        strncpy(initial_board, argv[1], 25);
    }

    // Show the initial board
    displayBoard(initial_board);

    // Start from player 1
    int currentPlayer = 1;
    int row, col;
    // Store the data of the last player
    int lastPlayer = 0;

    // Loop for the game (take turns) (with condition)
    while (!isGameOver(initial_board)) {

        // Player take turns enter the data of row and column
        printf("Player %d turn: ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Logic operation with condition to judge the valid of entered row and column
        if (isValidMove(initial_board, row, col)) {
            // Put the corresponding sign of player on give position
            char playerToken = (currentPlayer == 1) ? 'X' : 'O';
            int index = row * 5 + col;
            initial_board[index] = playerToken;
            // Update surrounding cells
            updateSurroundingCells(initial_board, row, col);
            lastPlayer = currentPlayer;
            // Change player
            currentPlayer = (currentPlayer == 1) ? 2 : 1;

            // Show game-board when condition is TRUE
            displayBoard(initial_board);
        } else {
            // When the condition is not TRUE, print message and skip printing the current game-board
            printf("Invalid Move!\n");
            continue;
        }
    }

    // Judge the winner when the game loop over
    if (lastPlayer != 0) {
        printf("Player %d Wins!\n", lastPlayer);
    }

    return 0;
}
