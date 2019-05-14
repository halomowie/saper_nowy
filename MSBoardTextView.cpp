//
// Created by Daniel on 05.05.2019.
//

#include "MSBoardTextView.h"
#include <iostream>
MSBoardTextView::MSBoardTextView(Minesweeperboard &giera): board(giera) {

}

void MSBoardTextView::display() const {
    for(int y=0; y<board.getBoardHeight(); y++){
        for(int x=0; x<board.getBoardWidth(); x++){
            std::cout<<"[";
            std::cout<< board.getFieldInfo(x,y);
            std::cout<<"]";
        }
        std::cout<<std::endl;
    }
}