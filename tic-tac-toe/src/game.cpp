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
    Bot::move(grid_, moves_);
    moves_++;
    if(isWin(PLAYER_ID)) {
        player_score_++;
        winner_ID = PLAYER_ID;
    } else if(isWin(BOT_ID)) {
        bot_score_++;
        winner_ID = BOT_ID;
    } else if(isTie()) {
        winner_ID = TIE_ID;
    }
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


bool Game::isWin(const unsigned int ID) const {
    // Check rows and columns
    for(int i = 0; i < 3; i++) {
        if ((grid_[i][0].ID == ID && grid_[i][1].ID == ID && grid_[i][2].ID == ID) ||
            (grid_[0][i].ID == ID && grid_[1][i].ID == ID && grid_[2][i].ID == ID)) {
            return true;
        }
    }

// Check diagonals
    if ((grid_[0][0].ID == ID && grid_[1][1].ID == ID && grid_[2][2].ID == ID) ||
        (grid_[0][2].ID == ID && grid_[1][1].ID == ID && grid_[2][0].ID == ID)) {
        return true;
    }
    return false;
}

bool Game::isTie() const {
    if(moves_ >= 9) return true;
    return false;
}
