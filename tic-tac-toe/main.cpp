#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include "game.h"
#include "draw.h"

int main() {
    // initialising  textures for game
    sf::Texture blank_txt, O_txt, X_txt;
    sf::Font font;
    if (!blank_txt.loadFromFile("./images/cell_off_background.jpg"))
        std::exit(EXIT_FAILURE);
    if (!O_txt.loadFromFile("./images/o.png"))
        std::exit(EXIT_FAILURE);
    if (!X_txt.loadFromFile("./images/x.png"))
        std::exit(EXIT_FAILURE);
    if(!font.loadFromFile("./images/aAntiCorona.ttf"))
        std::exit(EXIT_FAILURE);

    sf::RenderWindow app( sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "Tic-Tac-Toe" );

    Game game(3, 100.0f);
    Draw draw(font);

    while (app.isOpen()) {
        sf::Event e{};
        while (app.pollEvent(e)) {
            if ((e.type == sf::Event::KeyPressed && sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
                || e.type == sf::Event::Closed
                    ) {
                app.close();
            }
            if(game.winner_ID == BLANK_ID ) {
                if (e.type == sf::Event::MouseButtonPressed) {
                    sf::Vector2i mousePosition = sf::Mouse::getPosition(app);
                    game.update(mousePosition);
                }
            }
            else{
                if (e.type == sf::Event::MouseButtonPressed) {
                    game.restart();
                }
            }
        }
        app.clear(sf::Color(255, 115, 20));
        draw.grid(app, game.grid_, &blank_txt, &O_txt, &X_txt);
        draw.title(app);
        draw.score(app, game.bot_score_, game.player_score_);
        draw.winner(app, game.winner_ID);
        app.display();
    }
    return 0;
}