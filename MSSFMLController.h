//
// Created by Daniel on 14.05.2019.
//

#ifndef SAPER_NOWY_MSSFMLCONTROLLER_H
#define SAPER_NOWY_MSSFMLCONTROLLER_H
#include "Minesweeperboard.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"

class MSSFMLController {
    Minesweeperboard &board;
    MSSFMLView &view;
public:
    MSSFMLController(Minesweeperboard &test, MSSFMLView &test1);
    void kontrola(sf::Event &event);
};


#endif //SAPER_NOWY_MSSFMLCONTROLLER_H
