#include <stdio.h>
#include <stdlib.h>

const int ROWS = 10;
const int COLS = 10;
char maze[ROWS][COLS] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', '#', ' ', 'X', '#'}, // Enemy at (1,8)
    {'#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '#'},
    {'#', ' ', '#', 'P', ' ', ' ', ' ', ' ', ' ', '#'}, // Player start position
    {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', '#', ' ', ' ', '#', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', '#', ' ', '#'},
    {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
    {'#', ' ', '#', '#', '#', ' ', '#', '#', '#', '#'},
    {'#', 'E', '#', '#', '#', '#', '#', '#', '#', '#'} // Exit
};

int playerX = 3;
int playerY = 3;
bool isGameOver = false;

void printMaze() {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            printf("%c ", maze[i][j]);
        }
        printf("\n");
    }
}

bool movePlayer(char input) {
    // This function is responsible for moving the player based on the input direction ('w', 'a', 's', 'd') and the current layout of the maze.
    // Steps to follow:
    // 1. Determine the new position of the player based on the input direction.
    //    - 'w' moves the player up, 's' down, 'a' left, and 'd' right.
    // 2. Check if the new position is within the bounds of the maze and not blocked by a wall ('#').
    //    - If the move is invalid (out of bounds or into a wall), do not update the player's position.
    // 3. Update the player's position on the maze map:
    //    - Clear the current position of the player by setting it to ' ' (space).
    //    - Mark the new position with 'P' to represent the player.
    // 4. Check the new position for an enemy ('X') or the exit ('E'):
    //    - If the player reaches the enemy ('X'), display a message indicating the game is over due to encountering an enemy and set `isGameOver` to true.
    //    - If the player reaches the exit ('E'), display a congratulatory message indicating the player has escaped the maze and set `isGameOver` to true.
    // Note: The game's main loop checks the `isGameOver` flag to determine if the game should end.

    // Begin your implementation below this comment
    // placeholder for new location
    int newX = playerX;
    int newY = playerY;

    // set new position accordingly
    switch (input) {
    case 'w':
        newX = playerX - 1;
        break;
    case 'a':
        newY = playerY - 1;
        break;
    case 's':
        newX = playerX + 1;
        break;
    case 'd':
        newY = playerY + 1;
        break;
    }

    // make sure player can move into that space (no wall)
    if (maze[newX][newY] != '#') {
        // move player in the array
        maze[playerX][playerY] = ' ';
        maze[newX][newY] = 'P';

        // set player location
        playerX = newX;
        playerY = newY;
    }

    // check for game over (enemy) or win (exit)
    if (playerX == 1 && playerY == 8) {
        isGameOver = true;
        printf("You ran into an enemy and died. Game Over :( ");
    }
    else if (playerX == 9 && playerY == 1) {
        isGameOver = true;
        printf("You escaped the maze! You win! :) ");
    }

    return true;
    // End your implementation above this comment  
}

int main() {
    char input;

    while (!isGameOver) {
        printMaze();
        printf("Move (WASD): ");
        scanf_s(" %c", &input); // Space before %c to ignore 'enter' CHANGE TO scanf_s LATER

        if (input == 'w' || input == 'a' || input == 's' || input == 'd') {
            movePlayer(input);
        }
    }

    system("Pause");

    return 0;
}