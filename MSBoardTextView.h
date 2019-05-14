//
// Created by Daniel on 05.05.2019.
//

#ifndef SAPER_NOWY_MSBOARDTEXTVIEW_H
#define SAPER_NOWY_MSBOARDTEXTVIEW_H
#include "Minesweeperboard.h"

class MSBoardTextView {
    const Minesweeperboard &board;
public:
    MSBoardTextView(Minesweeperboard &test);
    void display() const;
};


#endif //SAPER_NOWY_MSBOARDTEXTVIEW_H
