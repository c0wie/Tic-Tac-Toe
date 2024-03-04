#include "draw.h"
#include "global_variables.h"

Draw::Draw(const sf::Font &font) :
        my_font_(font)
{}

void Draw::title(sf::RenderWindow &window) {
    sf::Text title("TIC-TAC-TOE", my_font_, 60);
    title.setPosition(sf::Vector2f(SCREEN_WIDTH/2, 50.0f));
    title.setOrigin(title.getGlobalBounds().width/2, title.getGlobalBounds().height/2);
    title.setFillColor(sf::Color::Black);
    title.setOutlineThickness(1.0f);
    title.setOutlineColor(sf::Color::White);
    window.draw(title);
}

void Draw::grid(sf::RenderWindow &window, std::vector< std::vector<Cell> >& grid, const sf::Texture* blank_txt, const sf::Texture* O_txt, const sf::Texture* X_txt) {
    for(auto &row : grid)
        for(auto &cell : row){
            if(cell.ID == BLANK_ID)
                cell.body.setTexture(blank_txt);
            else if(cell.ID == PLAYER_ID)
                cell.body.setTexture(X_txt);
            else if(cell.ID == BOT_ID)
                cell.body.setTexture(O_txt);
            else std::exit(EXIT_FAILURE);
            window.draw(cell.body);
        }

}

void Draw::score(sf::RenderWindow &window, const unsigned int bot_score, const unsigned int player_score) {
    sf::Text player_score_text("Player score is 0", my_font_, 30);
    player_score_text.setPosition(sf::Vector2f(165.0f, 185.0f));
    player_score_text.setOrigin(player_score_text.getGlobalBounds().width/2, player_score_text.getGlobalBounds().height/2);
    player_score_text.setFillColor(sf::Color::Black);
    player_score_text.setOutlineThickness(1.0f);
    player_score_text.setOutlineColor(sf::Color::White);

    sf::Text bot_score_text("Bot score is 0", my_font_, 30);
    bot_score_text.setPosition(sf::Vector2f(145.0f, 225.0f));
    bot_score_text.setOrigin(bot_score_text.getGlobalBounds().width/2, bot_score_text.getGlobalBounds().height/2);
    bot_score_text.setFillColor(sf::Color::Black);
    bot_score_text.setOutlineThickness(1.0f);
    bot_score_text.setOutlineColor(sf::Color::White);

    player_score_text.setString(player_score_text.getString().substring(0,16));
    bot_score_text.setString(bot_score_text.getString().substring(0, 13));

    player_score_text.setString(player_score_text.getString() + std::to_string(player_score));
    bot_score_text.setString(bot_score_text.getString() + std::to_string(bot_score));
    window.draw(player_score_text);
    window.draw(bot_score_text);
}

void Draw::winner(sf::RenderWindow &window, const unsigned int winner) {
    if(winner == BLANK_ID) return;

    sf::Text winner_text, subtitle;

    subtitle.setFont(my_font_);
    subtitle.setCharacterSize(20);
    subtitle.setString("Click to continue");
    subtitle.setOrigin(subtitle.getGlobalBounds().width/2, subtitle.getGlobalBounds().height/2);
    subtitle.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2 + 40.0f);
    subtitle.setFillColor(sf::Color::Black);
    subtitle.setOutlineThickness(1.0f);
    subtitle.setOutlineColor(sf::Color::White);

    winner_text.setFont(my_font_);
    winner_text.setCharacterSize(50);
    winner_text.setFillColor(sf::Color::Black);
    winner_text.setOutlineThickness(1.0f);
    winner_text.setOutlineColor(sf::Color::White);

    if(winner == PLAYER_ID)
        winner_text.setString("Player wins");
    else if(winner == BOT_ID)
        winner_text.setString("Bot wins");
    else if(winner == TIE_ID)
        winner_text.setString("Tie");

    winner_text.setOrigin(winner_text.getGlobalBounds().width/2, winner_text.getGlobalBounds().height/2);
    winner_text.setPosition(SCREEN_WIDTH/2, SCREEN_HEIGHT/2);

    window.draw(winner_text);
    window.draw(subtitle);
}
