//
// Created by Daniel on 06.05.2019.
//

#include "MSTextController.h"
#include "MSBoardTextView.h"
#include <iostream>
MSTextController::MSTextController(Minesweeperboard &giera, MSBoardTextView &widok):board(giera), view(widok) {

}

void MSTextController::play() {
    int punkt_x;
    int punkt_y;
    int opcja;
     do {
         view.display();
         std::cout << "Co chcesz zrobic 1 - Flaga lub 2 - odkryc pole" << std::endl;
         std::cin >> opcja;
         if(opcja==1){
             std::cout << "Podaj wspolrzedne wykonywanej akcji" << std::endl;
             std::cin >> punkt_x;
             std::cin >> punkt_y;
             board.toggleFlag(punkt_x,punkt_y);
         }
         else if(opcja==2) {
             std::cout << "Podaj wspolrzedne wykonywanej akcji" << std::endl;
             std::cin >> punkt_x;
             std::cin >> punkt_y;
             board.revealField(punkt_x,punkt_y);
         }
         if(board.getGameState()==RUNNING) {
             std::cout << "Grasz dalej" << std::endl;
         }
         else if(board.getGameState()==FINISHED_WIN){
             std::cout << "Koniec Wygrana" << std::endl;
         }
         else if(board.getGameState()==FINISHED_LOSS){
             std::cout << "Koniec Przegrana" << std::endl;
         }
     } while (board.getGameState()==RUNNING);

     view.display();
     if(board.getGameState()==FINISHED_WIN){
        std::cout << "Koniec Wygrana" << std::endl;
    }
     else if(board.getGameState()==FINISHED_LOSS){
        std::cout << "Koniec Przegrana" << std::endl;
    }
}