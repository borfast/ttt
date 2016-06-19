#ifndef _TTT_H
#define _TTT_H

char inputPlayerLetter();
int inputComputerSmartness();
char whoGoesFirst();
void displayInstructions();
int getPlayerMove(Board &board);
int getComputerMove(Board &board, Computer &computer);

#endif /* _TTT_H */