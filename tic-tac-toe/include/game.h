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
    bool player_move(const sf::Vector2i &mouse_position);
    [[nodiscard]] bool isWin(unsigned int ID) const;
    [[nodiscard]] bool isTie() const;
public:
    std::vector<std::vector<Cell>> grid_;
    unsigned int player_score_;
    unsigned int bot_score_;
    int winner_ID;
    unsigned int moves_;
};

#endif //TIC_TAC_TOE_GAME_H
