#ifndef TTT_BOARD_H
#define TTT_BOARD_H

#include <vector>

class Board {
private:
    // The board representation
    char board[9];

public:
    static const char EMPTY_PLACE = ' ';

    Board();

    Board(const Board &oldBoard);

    void reset();

    bool placeEmpty(int place) const;

    const char &getPlace(int place) const;

    void setPlace(int place, char value);

    std::vector<int> getPossibleMoves() const;

    const int getRandomMoveFromList(const int list[], int listSize) const;

    bool isFull() const;

    int evaluate(const char &player) const;
};

#endif /* TTT_BOARD_H */
