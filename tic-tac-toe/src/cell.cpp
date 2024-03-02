#include "cell.h"

Cell::Cell(const sf::Vector2f &pos, const float size) :
    cell_size(size),
    ID(BLANK_ID)
{
    body.setSize(sf::Vector2f (cell_size, cell_size));
    body.setOrigin(body.getSize().x/2,body.getSize().y/2);
    body.setPosition(pos);
}

bool Cell::isClicked(const sf::Vector2f &mouse_pos ) {
    sf::RectangleShape mouse(sf::Vector2f(10.0f, 10.0f));
    mouse.setPosition(static_cast<sf::Vector2f>(mouse_pos));

    sf::Rect<float> m_boundaries = mouse.getGlobalBounds();
    sf::Rect<float> c_boundaries = body.getGlobalBounds();

    if(c_boundaries.contains(m_boundaries.left, m_boundaries.top)
       && c_boundaries.contains(m_boundaries.left + m_boundaries.width, m_boundaries.top)
       && c_boundaries.contains(m_boundaries.left, m_boundaries.top + m_boundaries.height)
       && c_boundaries.contains(m_boundaries.left + m_boundaries.width, m_boundaries.top + m_boundaries.height)){
        return true;
    }
    return false;
}