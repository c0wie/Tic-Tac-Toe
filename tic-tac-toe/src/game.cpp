#include "game.h"

Game::Game(const unsigned int grid_size, const float cell_size):
        moves_(0),
        player_score_(0),
        bot_score_(0),
        winner_ID(BLANK_ID)
{
    sf::Vector2f pos(SCREEN_WIDTH/2 - (cell_size + 5.0f), SCREEN_HEIGHT/2 - cell_size/2);
    for (int i = 0; i < grid_size; i++) {
        std::vector<Cell> row;
        for (int j = 0; j < grid_size; j++) {
            Cell cell(pos ,cell_size);
            row.push_back(cell);
            pos.x += cell_size + 10.0f;
        }
        pos.y += cell_size + 10.0f;
        pos.x -= grid_size * (cell_size + 10.0f);
        grid_.push_back(row);
    }
}

void Game::update(const sf::Vector2i &mouse_position) {
    if(!player_move(mouse_position)) return;
    moves_++;
    if(game_over(moves_, grid_)) return;
    unsigned int num_grid[3][3];
    for(int row = 0; row < 3; row++){
        for (int col = 0; col < 3; ++col) {
            num_grid[row][col] = grid_[row][col].ID;
        }
    }
    Bot::move(num_grid);
    for(int row = 0; row < 3; row++){
        for (int col = 0; col < 3; ++col) {
            grid_[row][col].ID = num_grid[row][col];
        }
    }
    moves_++;
    if(game_over(moves_, grid_)) return;
}

bool Game::player_move(const sf::Vector2i &mouse_position) {
    for(auto &row : grid_)
        for(auto &cell : row)
            if(cell.ID == BLANK_ID)
                if (cell.isClicked(static_cast<sf::Vector2f>(mouse_position))){
                    cell.ID = PLAYER_ID;
                    return true;
                }
    return false;
}

void Game::restart() {
    winner_ID = BLANK_ID;
    moves_ = 0;
    for(auto &row : grid_){
        for (auto &cell : row) {
            cell.ID = BLANK_ID;
        }
    }
}
bool Game::game_over(unsigned int moves, const std::vector<std::vector<Cell>> &grid) {
    if(isWin(grid, PLAYER_ID)) {
        player_score_++;
        winner_ID = PLAYER_ID;
        return true;
    } else if(isWin(grid, BOT_ID)) {
        bot_score_++;
        winner_ID = BOT_ID;
        return true;
    } else if(isTie(moves)) {
        winner_ID = TIE_ID;
        return true;
    }
    return false;
}


bool Game::isWin(const std::vector<std::vector<Cell>> &grid,const unsigned int ID) {
    // Check rows and columns
    for(int i = 0; i < 3; i++) {
        if ((grid[i][0].ID == ID && grid[i][1].ID == ID && grid[i][2].ID == ID) ||
            (grid[0][i].ID == ID && grid[1][i].ID == ID && grid[2][i].ID == ID)) {
            return true;
        }
    }

// Check diagonals
    if ((grid[0][0].ID == ID && grid[1][1].ID == ID && grid[2][2].ID == ID) ||
        (grid[0][2].ID == ID && grid[1][1].ID == ID && grid[2][0].ID == ID)) {
        return true;
    }
    return false;
}

bool Game::isTie(unsigned int moves) {
    if(moves >= 9) return true;
    return false;
}
