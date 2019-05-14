#include <iostream>
#include "Minesweeperboard.h"
#include "MSBoardTextView.h"
#include "MSTextController.h"
#include "MSSFMLView.h"
#include <ctime>
#include <SFML/Graphics.hpp>
#include <cmath>
#include "MSSFMLController.h"

int main()
{   srand(time(NULL));
    // Create the main window
    sf::RenderWindow saper(sf::VideoMode(800, 600), "SFML window");
    Minesweeperboard board(10,10, HARD);
    MSSFMLView view (board);
    MSSFMLController ctrl(board,view);
    // Start the game loop
    while (saper.isOpen())
    {
        // Process events
        sf::Event event;
        while (saper.pollEvent(event))
        {
            // Close window : exit
            if (event.type == sf::Event::Closed)
                saper.close();
        }

        ctrl.kontrola(event);


        // Clear screen
        saper.clear(sf::Color::Black);

        // Draw the sprite
        view.draw(saper);

        // Update the window
        saper.display();
    }

    return EXIT_SUCCESS;
}


//    srand(time(NULL));
//Minesweeperboard board(3,3,HARD);
//MSBoardTextView view(board);
//MSTextController ctrl( board,view );
//ctrl.play();
