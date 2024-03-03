#include "bot.h"
#include "global_variables.h"


void Bot::move(unsigned int (&grid)[3][3]) {
    unsigned int grid_copy[3][3];
    std::memcpy(grid_copy, grid, sizeof(grid_copy));

    int bestVal = -1000;
    unsigned best_row = -1;
    unsigned best_col = -1;
    for (size_t row = 0; row<3; row++){
        for (size_t col = 0; col<3; col++){
            if (grid[row][col] == BLANK_ID){
                grid_copy[row][col] = PLAYER_ID;
                int CellVal = minimax(grid_copy, 0, false);
                grid_copy[row][col] = BLANK_ID;

                if (CellVal > bestVal){
                    best_row = row;
                    best_col = col;
                    bestVal = CellVal;
                }
            }
        }
    }
    grid[best_row][best_col] = BOT_ID;
}

int Bot::minimax(unsigned int grid[3][3], int depth, bool maximizing_player) {
    int score = evaluate(grid);
    if(score != 0)
        return score;
    if(!cells_left(grid))
        return 0 ;
    int best = (maximizing_player)? -1000:+1000;
    for (size_t row = 0; row < 3; row++){
        for (size_t col = 0; col < 3; col++){
            if (grid[row][col] == BLANK_ID){
                grid[row][col] = (maximizing_player)? BOT_ID : PLAYER_ID;
                if(maximizing_player)
                    best = std::max(best, minimax(grid, depth+1, !maximizing_player) );
                else
                    best = std::min(best, minimax(grid, depth+1, !maximizing_player) );
                grid[row][col] = BLANK_ID;
            }
        }
    }
    if(maximizing_player) best -= depth;
    return best;
}


int Bot::evaluate(unsigned int grid[3][3]) {
    for(size_t row = 0; row < 3; row++){
        if (grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2]){
            if (grid[row][0] == PLAYER_ID)
                return +10;
            else if (grid[row][0] == BOT_ID)
                return -10;
        }
    }

    for (size_t col = 0; col<3; col++){
        if (grid[0][col] == grid[1][col] && grid[1][col] == grid[2][col]){
            if (grid[0][col] == PLAYER_ID)
                return +10;
            else if (grid[0][col] == BOT_ID)
                return -10;
        }
    }

    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
        if (grid[0][0] == PLAYER_ID)
            return +10;
        else if (grid[0][0] == PLAYER_ID)
            return -10;
    }

    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
        if (grid[0][2] == PLAYER_ID)
            return +10;
        else if (grid[0][2] == PLAYER_ID)
            return -10;
    }

    return 0;
}

bool Bot::cells_left(unsigned int grid[3][3]) {
    for(int i = 0; i<3; i++)
        for (int j = 0; j<3; j++)
            if (grid[i][j] == BLANK_ID)
                return true;
    return false;
}

