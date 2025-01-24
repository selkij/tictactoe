#include <stdio.h>
#include <stdbool.h>

/*
      |   |   | 
    - . - o - x -
      |   |   | 
    - o - x - . -
      |   |   | 
    - o - . - . -
      |   |   | 
*/

int make_move(int line, int column, bool player_turn, int grid[3][3]) {
    if(line > 2 || column > 2) {
        printf("Invalid move: %d %d\n", line, column);
        return 0;
    }

    if(grid[line][column] != 0) {
        printf("This spot is already taken!\n");
        return 0;
    }

    grid[line][column] = (player_turn == true) ? 2 : 1;
    return 1;
}

void show_grid(int grid[3][3]) {
    for(int y=0; y<3; y++) {
        printf("  |   |   | \n");
        for(int x=0; x<3; x++) {
            if(grid[y][x] == 1){
                if(x == 2) {
                    printf("- o -\n");
                } else {
                    printf("- o ");
                }
                
            } else if(grid[y][x] == 2) {
                if(x == 2) {
                    printf("- x -\n");
                } else {
                    printf("- x ");
                }
            } else if(grid[y][x] == 0) {
                if(x == 2) {
                    printf("- . -\n");
                } else {
                    printf("- . ");
                }
            }
        }
    }

    printf("  |   |   | \n");
}

bool is_grid_full(int grid[3][3]) {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(grid[i][j] == 0) {
                return false;
            }
        }
    }
    return true;
}

bool is_game_won(int grid[3][3]) {
    // Check lines
    for (int i = 0; i < 3; i++) {
        if (grid[i][0] == 1 && grid[i][1] == 1 && grid[i][2] == 1) {
            return 1;
        }
        if (grid[0][i] == 1 && grid[1][i] == 1 && grid[2][i] == 1) {
            return 1;
        }
        if (grid[i][0] == 2 && grid[i][1] == 2 && grid[i][2] == 2) {
            return 1;
        }
        if (grid[0][i] == 2 && grid[1][i] == 2 && grid[2][i] == 2) {
            return 1;
        }
    }

    if (grid[0][0] == 1 && grid[1][1] == 1 && grid[2][2] == 1) {
        return 1;
    }
    if (grid[0][2] == 1 && grid[1][1] == 1 && grid[2][0] == 1) {
        return 1;
    }
    if (grid[0][0] == 2 && grid[1][1] == 2 && grid[2][2] == 2) {
        return 1;
    }
    if (grid[0][2] == 2 && grid[1][1] == 2 && grid[2][0] == 2) {
        return 1;
    }

    return false;
}

int main(void) {
    // colonne | ligne
    int grid[3][3] = { 
        {0, 0, 0}, 
        {0, 0, 0}, 
        {0, 0, 0}
    };

    int win = 0;

    // false is o | true is x
    bool player_turn = false;

    printf("Welcome to Tic Tac Toe!\n");
    while(win == false){
        printf("Please enter your move (ex: 1 2), Player %d\n", player_turn);
        
        int l, c;
        scanf("%d %d", &l, &c);
        
        if(make_move(l, c, player_turn, grid) == 1) {
            show_grid(grid);
            player_turn = !player_turn;

            if(is_grid_full(grid)) {
                win = true;
            }

            if(is_game_won(grid) == 1) {
                printf("Player 1 won!\n");
                win = true;
            }
            
            if(is_game_won(grid) == 2) {
                printf("Player 2 won!\n");
                win = true;
            }
        }
    } 

    printf("Game is finished!\n");

    return 0;
}