#ifndef TIC_TAC_TOE_DRAW_H
#define TIC_TAC_TOE_DRAW_H

#include <SFML/Graphics.hpp>
#include "cell.h"

class Draw
{
public:
    explicit Draw(const sf::Font &font);

    void title(sf::RenderWindow &window) ;
    void grid(sf::RenderWindow &window, std::vector< std::vector<Cell> >& grid, const sf::Texture* blank_txt, const sf::Texture* O_txt, const sf::Texture* X_txt) ;
    void score(sf::RenderWindow &window, unsigned int bot_score, unsigned int player_score);
    void winner(sf::RenderWindow &window, unsigned int winner);
private:
    sf::Font my_font_;
};

#endif //TIC_TAC_TOE_DRAW_H
