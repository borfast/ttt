#ifndef _BOARD_H
#define _BOARD_H

#include <vector>

class Board {
  private:
    // The board representation
    char board[9];

    // The letter for each player
    char playerLetter, computerLetter, currentPlayer;

  public:
    Board();
    Board(Board &oldBoard);
    void draw();
    void reset();
    void setLetters(char playerLetter);
    const char &getPlayerLetter() const;
    const char &getComputerLetter() const;

    const char &getCurrentPlayer() const;
    void setCurrentPlayer(char player);

    bool isEmpty(int place) const;
    // const char& getPlace(int place) const;
    void setPlace(int place, char value);
    void makeMove(int place);

    void getPossibleMoves(std::vector<int> &possibleMoves) const;
    const int getRandomMoveFromList(const int list[], int listSize) const;

    bool isWinner(const char player) const;
    bool isFull() const;
    int evaluate(const char &player) const;
};

#endif /* _BOARD_H */
