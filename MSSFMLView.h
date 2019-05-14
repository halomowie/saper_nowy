//
// Created by Daniel on 07.05.2019.
//
#ifndef SAPER_NOWY_MSSFMLVIEW_H
#define SAPER_NOWY_MSSFMLVIEW_H

#include <SFML/Graphics.hpp>
#include "MSBoardTextView.h"
#include "Minesweeperboard.h"

class MSSFMLView {
    const Minesweeperboard &board;
    int board_height;
    int board_width;
    int cel_len;
    int x_planszy;
    int y_planszy;
    sf::RectangleShape rect;
    sf::RectangleShape rect2;
//    sf::RectangleShape rect3;
    sf::Text reset;
    sf::Text text;
    sf::Font font;
    sf::Text state;
public:
    MSSFMLView (Minesweeperboard & test);
    void draw(sf::RenderWindow & win);
    int getCel_len();
    int getx_planszy();
    int gety_planszy();
};


#endif //SAPER_NOWY_MSSFMLVIEW_H
