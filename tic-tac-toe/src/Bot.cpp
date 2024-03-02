#include "Bot.h"
#include "global_variables.h"


void Bot::move(std::vector<std::vector<Cell>> &grid, const unsigned int &moves) {
    if(moves == 9) return;
    if(moves == 1) first_move(grid);
    else {
        //check if can bot win
        if (horizontal_move(grid, BOT_ID));
        else if (vertical_move(grid, BOT_ID));
        else if (diagonal_move(grid, BOT_ID));
            // check if bot can block X
        else if (horizontal_move(grid, PLAYER_ID));
        else if (vertical_move(grid, PLAYER_ID));
        else if (diagonal_move(grid, PLAYER_ID));
        else random_move(grid);
    }
}

void Bot::first_move(std::vector<std::vector<Cell>> &grid) {
    // first bot move
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 5);
    int option = dis(gen);
    while (true) {
        if (option == 1) {
            if (grid[0][0].ID == BLANK_ID) {
                grid[0][0].ID = BOT_ID;
                return;
            }
        } else option = dis(gen);
        if (option == 2) {
            if (grid[0][2].ID == BLANK_ID) {
                grid[0][2].ID = BOT_ID;
                return;
            }
        } else option = dis(gen);
        if (option == 3) {
            if (grid[2][0].ID == BLANK_ID) {
                grid[2][0].ID = BOT_ID;
                return;
            }
        } else option = dis(gen);
        if (option == 4) {
            if (grid[2][2].ID == BLANK_ID) {
                grid[2][2].ID = BOT_ID;
                return;
            }
        } else option = dis(gen);
        if (option == 5) {
            if (grid[1][1].ID == BLANK_ID) {
                grid[1][1].ID = BOT_ID;
                return;
            }
        } else option = dis(gen);
    }
}

bool Bot::diagonal_move(std::vector<std::vector<Cell>> &grid, const unsigned int ID ) {
    if(grid[0][0].ID == ID && grid[2][2].ID == ID
       || grid[0][2].ID == ID && grid[2][0].ID == ID){
        if(grid[1][1].ID == BLANK_ID) {
            grid[1][1].ID = BOT_ID;
            return true;
        }
    }else if(grid[0][0].ID == ID && grid[1][1].ID == ID){
        if(grid[2][2].ID == BLANK_ID) {
            grid[2][2].ID = BOT_ID;
            return true;
        }
    }else if(grid[2][2].ID == ID && grid[1][1].ID == ID){
        if(grid[0][0].ID == BLANK_ID) {
            grid[0][0].ID = BOT_ID;
            return true;
        }
    }else if(grid[2][0].ID == ID && grid[1][1].ID == ID) {
        if (grid[0][2].ID == BLANK_ID) {
            grid[0][2].ID = BOT_ID;
            return true;
        }
    }else if(grid[0][2].ID == ID && grid[1][1].ID == ID) {
        if (grid[2][0].ID == BLANK_ID) {
            grid[2][0].ID = BOT_ID;
            return true;
        }
    }
    return false;
}

bool Bot::vertical_move(std::vector<std::vector<Cell>> &grid, const unsigned int ID ) {
    for(int y = 0; y < 3; y++){
        if(grid[y][0].ID == ID && grid[y][2].ID == ID){
            if(grid[y][1].ID == BLANK_ID) {
                grid[y][1].ID = BOT_ID;
                return true;
            }
        }else if((grid[y][0].ID == ID && grid[y][1].ID == ID)){
            if(grid[y][2].ID == BLANK_ID) {
                grid[y][2].ID = BOT_ID;
                return true;
            }
        }else if((grid[y][1].ID == ID && grid[y][2].ID == ID)){
            if(grid[y][0].ID == BLANK_ID) {
                grid[y][0].ID = BOT_ID;
                return true;
            }
        }
    }
    return false;
}

bool Bot::horizontal_move(std::vector<std::vector<Cell>> &grid, const unsigned int ID ) {
    for(int x = 0; x < 3; x++)
    {
        if(grid[0][x].ID == ID && grid[2][x].ID == ID){
            if(grid[1][x].ID == BLANK_ID) {
                grid[1][x].ID = BOT_ID;
                return true;
            }
        }else if(grid[0][x].ID == ID && grid[1][x].ID == ID){
            if(grid[2][x].ID == BLANK_ID) {
                grid[2][x].ID = BOT_ID;
                return true;
            }
        }else if(grid[1][x].ID == ID && grid[2][x].ID == ID){
            if(grid[0][x].ID == BLANK_ID) {
                grid[0][x].ID = BOT_ID;
                return true;
            }
        }
    }
    return false;
}

bool Bot::random_move(std::vector<std::vector<Cell>> &grid) {
    for(int y = 0; y < 3; y++){
        for (int x = 0; x < 3; x++) {
            if(grid[y][x].ID == BLANK_ID){
                grid[y][x].ID = BOT_ID;
                return true;
            }
        }
    }
    return false;
}
