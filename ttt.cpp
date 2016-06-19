#include <iostream>
#include "board.h"
#include "computer.h"
#include "ttt.h"
#include "Game.h"
#include "IO.h"

using namespace std;

int main() {
    Board board;
    Computer computer;
    Game game(&board);
    IO io;

    char turn, again;
    bool playing;

    io.displayInstructions();

    while (true) {
        board.reset();
        game.setLetters(io.inputPlayerLetter());
        computer.setSmart(io.inputComputerSmartness());
        turn = whoGoesFirst();
        cout << "The " << turn << " will go first." << endl << endl;
        playing = true;
        again = '?';

        while (playing) { // The main game loop
            io.drawBoard(board);

            // Who's turn is it?
            int move;

            if (turn == 'p') {
                // player's turn
                move = getPlayerMove(board);
                if (move == 9)
                    break;
                board.setPlace(move, game.getPlayerLetter());
                cout << "You played " << move << endl;

                // Check if player won
                if (game.isWinner(game.getPlayerLetter(), board)) {
                    io.drawBoard(board);
                    cout << "Hooray! You have won the game!" << endl
                         << endl;
                    playing = false;
                } else {
                    if (board.isFull()) {
                        io.drawBoard(board);
                        cout << "The game is a tie!" << endl
                             << endl;
                        break;
                    } else {
                        turn = 'c';
                    }
                }
            } else {
                // computer's turn
                move = getComputerMove(game, board, computer);
                board.setPlace(move, game.getComputerLetter());
                cout << "The computer played " << move << endl;

                if (game.isWinner(game.getComputerLetter(), board)) {
                    io.drawBoard(board);
                    cout << "The computer has beaten you! You lose." << endl
                         << endl;
                    playing = false;
                } else {
                    if (board.isFull()) {
                        io.drawBoard(board);
                        cout << "The game is a tie!";
                        break;
                    } else {
                        turn = 'p';
                    }
                }
            }
        }

        while (again != 'y' && again != 'n') {
            cout << "Do you want to play again? (y/n): ";
            cin >> again;
        }
        if (again == 'y') {
            continue;
        } else {
            break;
        }
    }

    cout << endl << "Sorry to see you go. Perhaps a nice game of Global Thermonuclear War next time?" << endl;

    return 0;
}


/*
 * Randomly choose the player who goes first.
 */
char whoGoesFirst() {
    srand((unsigned)time(0));

    if ((rand() % 2) == 0) {
        return 'c';
    } else {
        return 'p';
    }
}


int getPlayerMove(Board &board) {
    // Next move by the player
    int nextMove = 0;

    while (1) {
        cout << "What's your next move? (0-8, 9 to quit) #" << endl;
        cin >> nextMove;

        // No possibility of passing an out of bounds index to board.getPlace(),
        // because we're short-circuiting the condition:
        // if nextMove < 1 the condition evaluates to true as a whole, so the
        // remaining expression will not even be evaluated.
        if (nextMove < 0 || nextMove > 9 || !board.placeEmpty(nextMove)) {
            cout << endl << "Invalid choice, try again." << endl << endl;
            continue;
        }

        break;
    }

    return nextMove;
}

int getComputerMove(Game& game, Board& board, Computer &computer) {
    return computer.getMove(game, board);
}
