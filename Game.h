#ifndef TTT_GAME_H
#define TTT_GAME_H


#include "board.h"

class Game {
private:
    Board* board;
    char currentPlayer, playerLetter, computerLetter;

public:
    Game(Board *board);

    const char& getCurrentPlayer() const;
    void setCurrentPlayer(char player);

    const char& getPlayerLetter() const;
    const char& getComputerLetter() const;
    void setLetters(char playerLetter);

    void makeMove(int place, char player);

    static bool isWinner(const char player, const Board& board);
};


#endif //TTT_GAME_H
