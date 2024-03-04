#include "bot.h"
#include "global_variables.h"


void Bot::move(unsigned int (&grid)[3][3]) {
    int best_score = - 1000;
    unsigned best_row = -1;
    unsigned best_col = -1;
    for (size_t row = 0; row<3; row++){
        for (size_t col = 0; col<3; col++){
            if (grid[row][col] == BLANK_ID){

                grid[row][col] = BOT_ID;
                int score = minimax(grid, 0, false);
                grid[row][col] = BLANK_ID;

                if (score > best_score){
                    best_row = row;
                    best_col = col;
                    best_score = score;
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

    if(maximizing_player){
        int best = -1000;
        for (size_t row = 0; row < 3; row++) {
            for (size_t col = 0; col < 3; col++) {
                if (grid[row][col] == BLANK_ID) {
                    grid[row][col] = BOT_ID;
                    best = std::max(best, minimax(grid, depth + 1, false));
                    grid[row][col] = BLANK_ID;
                }
            }
        }
        return best - depth;
    }else {
        int best = 1000;
        for (size_t row = 0; row < 3; row++) {
            for (size_t col = 0; col < 3; col++) {
                if (grid[row][col] == BLANK_ID) {
                    grid[row][col] = PLAYER_ID;
                    best = std::min(best, minimax(grid, depth + 1, true));
                    grid[row][col] = BLANK_ID;
                }
            }
        }
        return best;
    }
}


int Bot::evaluate(unsigned int grid[3][3]) {
    for(size_t row = 0; row < 3; row++){
        if (grid[row][0] == grid[row][1] && grid[row][1] == grid[row][2]){
            if (grid[row][0] == BOT_ID)
                return +10;
            else if (grid[row][0] == PLAYER_ID)
                return -10;
        }
    }

    for (size_t col = 0; col<3; col++){
        if (grid[0][col] == grid[1][col] && grid[1][col] == grid[2][col]){
            if (grid[0][col] == BOT_ID)
                return +10;
            else if (grid[0][col] == PLAYER_ID)
                return -10;
        }
    }

    if (grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
        if (grid[0][0] == BOT_ID)
            return +10;
        else if (grid[0][0] == PLAYER_ID)
            return -10;
    }

    if (grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
        if (grid[0][2] == BOT_ID)
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

