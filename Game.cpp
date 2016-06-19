#include "Game.h"

Game::Game(Board *board) : board(board) { }

const char& Game::getCurrentPlayer() const {
    return this->currentPlayer;
}

void Game::setCurrentPlayer(char player) {
    this->currentPlayer = player;
}


const char& Game::getPlayerLetter() const {
    return this->playerLetter;
}

const char& Game::getComputerLetter() const {
    return this->computerLetter;
}

void Game::setLetters(char playerLetter) {
    this->playerLetter = playerLetter;
    if (playerLetter == 'X') {
        computerLetter = 'O';
    } else {
        computerLetter = 'X';
    }
}


void Game::makeMove(int place, char player) {
    board->setPlace(place, player);
}


/*
 * Given a player's letter, this function returns true if that player has won.
 * It does so by testing all possible winning combinations. I'm sure there's a
 * better way to do this but right now I don't really feel like thinking about it.
 */
bool Game::isWinner(const char player, const Board& board) {
    return ((board.getPlace(6) == player && board.getPlace(7) == player &&
             board.getPlace(8) == player) || // across the top

            (board.getPlace(3) == player && board.getPlace(4) == player &&
             board.getPlace(5) == player) || // across the middle

            (board.getPlace(0) == player && board.getPlace(1) == player &&
             board.getPlace(2) == player) || // across the bottom

            (board.getPlace(6) == player && board.getPlace(3) == player &&
             board.getPlace(0) == player) || // down the left side

            (board.getPlace(7) == player && board.getPlace(4) == player &&
             board.getPlace(1) == player) || // down the middle

            (board.getPlace(8) == player && board.getPlace(5) == player &&
             board.getPlace(2) == player) || // down the right side

            (board.getPlace(6) == player && board.getPlace(4) == player &&
             board.getPlace(2) == player) || // diagonal

            (board.getPlace(8) == player && board.getPlace(4) == player &&
             board.getPlace(0) == player)); // diagonal
}







