//
// Created by Daniel on 14.05.2019.
//

#include "MSSFMLController.h"
#include <SFML/Graphics.hpp>
#include "MSSFMLView.h"
#include <cmath>
#include <iostream>
#include "Minesweeperboard.h"

MSSFMLController::MSSFMLController(Minesweeperboard &giera, MSSFMLView &widok): board(giera), view(widok)  {

}
void MSSFMLController::kontrola(sf::Event &event) {
    double mousex = (((event.mouseButton.x) - view.getx_planszy()) / view.getCel_len());
    double mousey = (((event.mouseButton.y) - view.gety_planszy()) / view.getCel_len());
    round(mousex);
    round(mousey);

    if (board.getGameState() == RUNNING) {
        if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Right) {
                board.toggleFlag(mousex, mousey);
            } else if (event.mouseButton.button == sf::Mouse::Left) {
                if(event.mouseButton.x>=10 and event.mouseButton.x<=100 and event.mouseButton.y>=50 and event.mouseButton.y<=80){
                }
                board.revealField(mousex, mousey);
            }
        }
    }
    else if(board.getGameState()== FINISHED_WIN or board.getGameState()== FINISHED_LOSS){

    }
}

