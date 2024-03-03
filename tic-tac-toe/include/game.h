#ifndef TIC_TAC_TOE_GAME_H
#define TIC_TAC_TOE_GAME_H

#include <memory>
#include <SFML/Graphics.hpp>
#include "cell.h"
#include "Bot.h"

class Game {
public:
    Game(unsigned int grid_size, float cell_size);
    void update(const sf::Vector2i &mouse_position);
    void restart();
private:
    bool game_over(unsigned int moves, const std::vector<std::vector<Cell>> &grid);
    bool player_move(const sf::Vector2i &mouse_position);
    [[nodiscard]] static bool isWin(const std::vector<std::vector<Cell>> &grid, unsigned int ID) ;
    [[nodiscard]] static bool isTie(unsigned int moves) ;
public:
    std::vector<std::vector<Cell>> grid_;
    unsigned int player_score_;
    unsigned int bot_score_;
    int winner_ID;
    unsigned int moves_;
};

#endif //TIC_TAC_TOE_GAME_H
