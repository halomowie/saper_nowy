//
// Created by Daniel on 05.05.2019.
//

#include "Minesweeperboard.h"
#include <iostream>
Minesweeperboard::Minesweeperboard() {
    boardwidth=10;
    boardheight=10;
    fill_board();
    debug_display();
}

Minesweeperboard::Minesweeperboard(int width, int height, GameMode gmode) {
    mode=gmode;
    boardwidth=width;
    boardheight=height;
    fill_board();
    debug_display();
}
//Zerowanie planszy i losowanie bomb
void Minesweeperboard::fill_board() {
    state=RUNNING;
    for (int y = 0; y < boardheight ; ++y) {
        for (int x = 0; x < boardwidth ; ++x) {

            board[x][y].isRevealed=false;
            board[x][y].hasMine=false;
            board[x][y].hasFlag=false;
        }
        
    }

    int liczbamin=0;
    if (mode == EASY) {
        liczbamin = boardwidth * boardheight * 0.1;
    } else if (mode == NORMAL) {
        liczbamin = boardwidth * boardheight * 0.2;
    } else if (mode == HARD) {
        liczbamin = boardwidth * boardheight * 0.3;
    } else if (mode == DEBUG) {
        for (int i=0; i<boardwidth; i++) {
            board[i][0].hasMine = true;
        }
        for (int i=0; i<boardwidth and i<boardheight; i++) {
            board[i][i].hasMine = true;
        }
        for (int i=0; i<boardheight; i=i+2){
            board[0][i].hasMine = true;
        }


    }

    if (mode == EASY or mode == NORMAL or mode == HARD) {
        for (int i = 0; i < liczbamin;) {
            int szerokosc = (std::rand() % boardwidth);
            int wysokosc = (std::rand() % boardheight);
            if (board[szerokosc][wysokosc].hasMine == true) {
                continue;
            } else if (board[szerokosc][wysokosc].hasMine == false) {
                board[szerokosc][wysokosc].hasMine = true;
                i++;
            }

        }
    }

}
//Wyswietlanie pola
void Minesweeperboard::debug_display() const {
    for (int y = 0; y < boardheight ; ++y) {
        for (int x = 0; x < boardwidth ; ++x) {
            std::cout << "{";
            if (board[x][y].hasMine == true) {
                std::cout << "M";
            } else {
                std::cout << ".";
            }


            if (board[x][y].isRevealed == true) {
                std::cout << "o";
            } else {
                std::cout << ".";
            }

            if (board[x][y].hasFlag == true) {
                std::cout << "f";
            } else {
                std::cout << ".";
            }
            std::cout << "}";
        }
        std::cout << std::endl;
    }
}
//Sprawdza czy pole jest na planszy
bool Minesweeperboard::rightField(int x, int y) const {
    if(x<0 and x>boardwidth and y<0 and y>boardheight){
        return false;
    }
    else {
        return true;
    }

}
//Wysokosc planszy
int Minesweeperboard::getBoardHeight() const {
    return boardheight;
}
//Szerokosc planszy
int Minesweeperboard::getBoardWidth() const {
    return boardwidth;
}
//Liczba min na planszy
int Minesweeperboard::getMineCount() const {
    int lm=0;
    for (int y = 0; y < boardheight ; ++y) {
        for (int x = 0; x < boardwidth ; ++x) {
            if(board[x][y].hasMine==true){
                lm++;
            }
        }
    }

    return lm;
}
//Sprawdz czy pole ma flage
bool Minesweeperboard::hasFlag(int x, int y) const {
    if(board[x][y].hasFlag==true){
        return true;
    }
    else if(rightField(x,y)==false){
        return false;
    }
    else if(board[x][y].hasFlag==false){
        return false;
    }
    else if(board[x][y].isRevealed==true){
        return false;
    }
}
//Sprawdz czy pole jest odkryte
bool Minesweeperboard::isRevealed(int x, int y) const {
    if(board[x][y].isRevealed==true){
        return true;
    }
    else {
        return false;
    }
}
//Liczenie bomb wokół pola
int Minesweeperboard::countMines(int x, int y) const {
    int miny_pole;
    if(x>boardwidth or y>boardwidth or x<0 or y<0) {
        return -1;
    }

    else if(board[x][y].isRevealed==false) {
        return -1;
    }

    else if(x>=0 and y>=0 and y<boardheight and x<boardwidth) {
        for(int i=y-1; i<=y+1; i++){
            for(int z=x-1; z<=x+1; z++){
                if (i==y and z==x) {
                    continue;
                }

                else if(z<0 or i<0 or z>boardwidth or i>boardheight){
                    continue;
                }
                else if(board[z][i].hasMine==true){
                    miny_pole++;
                }
            }
        }
    }


    return miny_pole;
}
//Odkryj pole
void Minesweeperboard::revealField(int x, int y) {
    int LICZBA_MIN=getMineCount();
    int UKRYTE_BOMBY_SUMA_ODKRYTE_POLA=0;
    int UKRYTE_BOMBY=0;
    int LICZBA_POL=boardwidth*boardheight;
    int LICZBA_ZAKRYTYCH=0;
    int ODKRYTE_POLA=0;
    

    for (int h = 0; h < boardheight ; ++h) {
        for (int w = 0; w < boardwidth; ++w) {
            if(board[w][h].isRevealed==false){
                ++LICZBA_ZAKRYTYCH;
            }
        }
    }



    if(board[x][y].isRevealed==false and board[x][y].hasMine==true and (LICZBA_ZAKRYTYCH!=LICZBA_POL or mode==DEBUG)) {
        board[x][y].isRevealed=true;
        state=FINISHED_LOSS;
    }
    else if(board[x][y].isRevealed==false and board[x][y].hasMine==true and mode!=DEBUG and LICZBA_ZAKRYTYCH==LICZBA_POL){
        board[x][y].hasMine=false;
        board[x][y].isRevealed=true;
        for (int i = 0; i < 1;) {
            int szerokosc = (std::rand() % boardwidth);
            int wysokosc = (std::rand() % boardheight);
            if (board[szerokosc][wysokosc].hasMine == true) {
                continue;
            } else if (board[szerokosc][wysokosc].hasMine == false and (szerokosc!=x or wysokosc!=y)) {
                board[szerokosc][wysokosc].hasMine = true;
                i++;
            }

        }
    }
    else if(board[x][y].isRevealed==false and board[x][y].hasMine==false and (LICZBA_POL!=LICZBA_ZAKRYTYCH or LICZBA_POL==LICZBA_ZAKRYTYCH)){
        board[x][y].isRevealed=true;
    }
    else if(board[x][y].isRevealed==true){

    }
    else if(x<0 or x>boardwidth or y<0 or y>boardheight){

    }
    else if(board[x][y].hasFlag=true){

    }

    else if(state==FINISHED_LOSS or state==FINISHED_WIN){

    }

    for (int h = 0; h < boardheight; ++h) {
        for (int w = 0; w < boardwidth ; ++w) {
            if(board[w][h].hasMine==true and board[w][h].isRevealed==false){
                ++UKRYTE_BOMBY;
            }
            if(board[w][h].isRevealed==true){
                ++ODKRYTE_POLA;
            }
        }
    }
    UKRYTE_BOMBY_SUMA_ODKRYTE_POLA=UKRYTE_BOMBY+ODKRYTE_POLA;
    if(UKRYTE_BOMBY_SUMA_ODKRYTE_POLA==LICZBA_POL){
        state=FINISHED_WIN;
    }
    else {

    }


}
//Gamestate
GameState Minesweeperboard::getGameState() const {
    return state;
}
//Informacje na temat pola
char Minesweeperboard::getFieldInfo(int x, int y) const {
    int miny_pole = countMines(x, y);
    if (x < 0 or x > boardwidth or y < 0 or y > boardwidth) {
        char TEST[2] = "#";
        return TEST[0];
    } else if (board[x][y].isRevealed == false and board[x][y].hasFlag == true) {
        char TEST[2] = "F";
        return TEST[0];

    } else if (board[x][y].isRevealed == false and board[x][y].hasFlag == false) {
        char TEST[2] = " ";
        return TEST[0];
    } else if (board[x][y].isRevealed == true and board[x][y].hasMine == true) {
        char TEST[2] = "x";
        return TEST[0];
    } else if (board[x][y].isRevealed == true and miny_pole == 0) {
        char TEST[2] = " ";
        return TEST[0];
    } else if (board[x][y].isRevealed == true and miny_pole == 1) {
        char TEST[2] = "1";
        return TEST[0];
    } else if (board[x][y].isRevealed == true and miny_pole == 2) {
        char TEST[2] = "2";
        return TEST[0];
    } else if (board[x][y].isRevealed == true and miny_pole == 3) {
        char TEST[2] = "3";
        return TEST[0];
    } else if (board[x][y].isRevealed == true and miny_pole == 4) {
        char TEST[2] = "4";
        return TEST[0];
    } else if (board[x][y].isRevealed == true and miny_pole == 5) {
        char TEST[2] = "5";
        return TEST[0];
    } else if (board[x][y].isRevealed == true and miny_pole == 6) {
        char TEST[2] = "6";
        return TEST[0];
    } else if (board[x][y].isRevealed == true and miny_pole == 7) {
        char TEST[2] = "7";
        return TEST[0];
    } else if (board[x][y].isRevealed == true and miny_pole == 8) {
        char TEST[2] = "8";
        return TEST[0];
    }
}
//Toggle flag
void Minesweeperboard::toggleFlag(int x, int y) {
    int ODKRYTE_POLA=0;
    int ZAKRYTE_LUB_OFLAGOWANE_MINY=0;
    int ODKRYTE_POLA_SUMA_ZAKRYTE_LUB_OFLAGOWANE_MINY=0;
    int LICZBA_MIN=getMineCount();
    int OFLAGOWANE_MINY=0;
    int LICZBA_POL=boardwidth*boardheight;
    if (board[x][y].isRevealed == false) {
        if (board[x][y].hasFlag == true) {
            board[x][y].hasFlag = false;
        } else if (board[x][y].hasFlag == false) {
            board[x][y].hasFlag = true;
        }
    }
    else if (board[x][y].isRevealed == true) {

    }
    else if (rightField(x,y) == false) {

    }
    else if (state==FINISHED_LOSS or state==FINISHED_WIN){

    }



    for (int h = 0; h < boardheight ; ++h) {
        for (int w = 0; w < boardwidth ; ++w) {
            if(board[w][h].hasFlag==true and board[w][h].hasMine==true){
                ++OFLAGOWANE_MINY;
            }
            else if(board[w][h].hasMine==true and (board[w][h].isRevealed==false or board[w][h].hasFlag==true)){
                ++ZAKRYTE_LUB_OFLAGOWANE_MINY;
            }
            else if(board[w][h].isRevealed==true){
                ++ODKRYTE_POLA;
            }
        }
    }
    ODKRYTE_POLA_SUMA_ZAKRYTE_LUB_OFLAGOWANE_MINY=ODKRYTE_POLA+ZAKRYTE_LUB_OFLAGOWANE_MINY;
    if(OFLAGOWANE_MINY==LICZBA_MIN and ODKRYTE_POLA_SUMA_ZAKRYTE_LUB_OFLAGOWANE_MINY==LICZBA_POL){
        state=FINISHED_WIN;
    }

}

//SPRAWDZA CZY W OKOLICY SA BOMBY

bool Minesweeperboard::isNearBomb(int x, int y) {

    for (int i = y - 1; i <= y + 1; i++) {
        for (int z = x - 1; z <= x + 1; z++) {
            if (i == y and z == x) {
                continue;
            } else if (z < 0 or i < 0 or z > boardwidth or i > boardheight) {
                continue;
            } else if (board[z][i].hasMine == true) {
                return true;
            }
        }
    }
    return false;
}