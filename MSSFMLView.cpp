//
// Created by Daniel on 07.05.2019.
//

#include "MSSFMLView.h"
#include <iostream>
MSSFMLView::MSSFMLView(Minesweeperboard &giera): board(giera)
{
    board_height=board.getBoardHeight();
    board_width=board.getBoardWidth();
    cel_len=30;
    x_planszy=200;
    y_planszy=100;

    rect.setSize(sf::Vector2f(cel_len, cel_len));
    rect2.setSize(sf::Vector2f(cel_len-2,cel_len-2));

    if ( !font.loadFromFile( "pixel.ttf" )){

        std::cout << "Error loading font" << std::endl;

        system( "pause" );
    }

    text.setFont( font );
    text.setFillColor(sf::Color::Black);
    text.setCharacterSize(26);

    state.setFont( font );
    state.setCharacterSize(30);
    state.setFillColor(sf::Color::Red);
    state.setPosition(10,10);

    reset.setFont(font);
    reset.setCharacterSize(30);
    reset.setFillColor(sf::Color::Red);
    reset.setPosition(10,50);
    reset.setString("Reset");

//    rect3.setPosition(10,50);
//    rect3.setSize(sf::Vector2f(90,30));
//    rect3.setFillColor(sf::Color::White);
}


void MSSFMLView::draw(sf::RenderWindow & win)
{

    state.setString("Saperek");
    for(int x=0;x<board_width;x++){

        int xh=(cel_len)*x;


        for(int y=0;y<board_height;y++){
            int yh=(cel_len)*y;

            rect.setPosition(xh+x_planszy, yh+y_planszy);
            rect2.setPosition(xh+x_planszy+1, yh+y_planszy+1);
            text.setString(board.getFieldInfo(x,y));
            text.setPosition(xh+x_planszy+8,yh+y_planszy);

            if(board.isRevealed(x,y)==true){
                rect2.setFillColor(sf::Color(73, 75, 79));
            }
            else{
                rect2.setFillColor(sf::Color(118, 119, 122));
            }

            win.draw(rect);
            win.draw(rect2);
            win.draw(text);

        }
    }


    if(board.getGameState()==RUNNING){
        state.setString("Gra w toku");
    }
    else if(board.getGameState()==FINISHED_LOSS){
        state.setString("Przegrana");
    }
    else if(board.getGameState()==FINISHED_WIN){
        state.setString("Wygrana");
    }
    win.draw(state);
//    win.draw(rect3);
    win.draw(reset);




}

int MSSFMLView::getCel_len() {
    return cel_len;
}

int MSSFMLView::getx_planszy() {
    return x_planszy;
}

int MSSFMLView::gety_planszy() {
    return y_planszy;
}