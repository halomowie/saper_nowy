//
// Created by Daniel on 06.05.2019.
//

#ifndef SAPER_NOWY_MSTEXTCONTROLLER_H
#define SAPER_NOWY_MSTEXTCONTROLLER_H

#include "Minesweeperboard.h"
#include "MSBoardTextView.h"
class MSTextController {
    Minesweeperboard &board;
const MSBoardTextView &view;
public:
    MSTextController(Minesweeperboard &board,MSBoardTextView &view);
    void play();
};


#endif //SAPER_NOWY_MSTEXTCONTROLLER_H
