//
// Created by borfast on 19-06-2016.
//

#ifndef TTT_IO_H
#define TTT_IO_H


#include "board.h"

class IO {
public:
    char inputPlayerLetter();
    int inputComputerSmartness();
    void displayInstructions();
    void drawBoard(Board& board);
};


#endif //TTT_IO_H
