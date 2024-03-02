#ifndef TIC_TAC_TOE_CELL_H
#define TIC_TAC_TOE_CELL_H

#include <iostream>
#include <memory>
#include <SFML/Graphics.hpp>
#include "global_variables.h"

struct Cell
{
public:
    explicit Cell(const sf::Vector2f &pos, float cell_size);
    bool isClicked(const sf::Vector2f &mouse_pos );
public:
    sf::RectangleShape body;
    int ID;
    const float cell_size;
private:
};

#endif //TIC_TAC_TOE_CELL_H
