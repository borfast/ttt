#ifndef _COMPUTER_H
#define	_COMPUTER_H

struct minimaxresult {
    int bestMove;
    int bestScore;
};

class Computer {
private:
    int smartness;
    static const int fullBoardList[9], cornersList[4], sidesList[4];
    const int center;

    int stupidMove(Board& board) const;
    int notSoStupidMove(Board& board) const;
    int smartMove(Board& board) const;
    minimaxresult minimax(Board& board, char player, int currentDepth, int maxDepth) const;

public:
    Computer();
    void setSmart(int smartness);
    int getMove(Board& board) const;
};

#endif	/* _COMPUTER_H */