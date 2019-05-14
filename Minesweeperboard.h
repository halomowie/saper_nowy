//
// Created by Daniel on 05.05.2019.
//

#ifndef SAPER_NOWY_MINESWEEPERBOARD_H
#define SAPER_NOWY_MINESWEEPERBOARD_H

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

struct Field
{
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
};


class Minesweeperboard {

    Field board[100][100];
    int boardwidth;
    int boardheight;

    GameMode mode;
    GameState state;

public:
    void fill_board();
    Minesweeperboard();
    Minesweeperboard(int width, int height, GameMode mode);
    void debug_display() const;
    int getBoardWidth() const;
    int getBoardHeight() const;
    int getMineCount() const;
    bool hasFlag(int x, int y) const;
    bool rightField(int x, int y) const;
    bool isRevealed(int x, int y) const;
    int countMines(int x, int y) const;
    void revealField(int x, int y);
    GameState getGameState() const;
    char getFieldInfo(int x, int y) const;
    void toggleFlag(int x, int y);
    bool isNearBomb(int x, int y);

};


#endif //SAPER_NOWY_MINESWEEPERBOARD_H
