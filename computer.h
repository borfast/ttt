#ifndef _COMPUTER_H
#define _COMPUTER_H

#include "Game.h"

struct minimaxresult {
    int bestMove;
    int bestScore;
};

class Computer {
  private:
    int smartness;
    static const int fullBoardList[9], cornersList[4], sidesList[4];
    const int center;

public:
    Computer();
    int getMove(Game& game, Board& board) const;
    int stupidMove(Board &board) const;
    int notSoStupidMove(Game& game, Board& board) const;

    int smartMove(Game& game, Board& board) const;
    minimaxresult minimax(Board& board, char player, int currentDepth,
                          int maxDepth) const;
    void setSmart(int smartness);
};

#endif /* _COMPUTER_H */