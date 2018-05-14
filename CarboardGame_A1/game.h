/******************************************************************************
** Student name: 	Marina Gawrguos
** Student number: 	s3661762
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#ifndef GAME_H
#define GAME_H
#define USERINPUTSIZE 50
#define INPUTSIZE 50
#define BASE 10
#define SPACE_DELIM " "
#define COMMA_DELIM ","
#define MAX_NO_1 13
#define MAX_NO_2 14
#define FIRST_ARRAY_POS 0
#define FOURTH_ARRAY_POS 4
#define SIXTH_ARRAY_POS 6
#define EIGHTH_ARRAY_POS 8



#include "helpers.h"
#include "board.h"
#include "player.h"

#define COMMAND_LOAD "load"
#define COMMAND_INIT "init"
#define COMMAND_FORWARD "forward"
#define COMMAND_FORWARD_SHORTCUT "f"
#define COMMAND_TURN_LEFT "turn_left"
#define COMMAND_TURN_LEFT_SHORTCUT "l"
#define COMMAND_TURN_RIGHT "turn_right"
#define COMMAND_TURN_RIGHT_SHORTCUT "r"
#define COMMAND_QUIT "quit"

#define DIRECTION_NORTH "north"
#define DIRECTION_EAST "east"
#define DIRECTION_SOUTH "south"
#define DIRECTION_WEST "west"

/**
 * Main menu option 1 - play the game as per the specification.
 *
 * This function makes all the calls to board & player and handles interaction
 * with the user (reading input from the console, error checking, etc...).
 *
 * It should be possible to break this function down into smaller functions -
 * but this is up to you to decide and is entirely your own design. You can
 * place the additional functions in this header file if you want.
 *
 * Note that if you don't break this function up it could become pretty big...
 */

void playGame();
void checkInputBoardToLoad();
void displayMenu();
void getInitialPositionAndDirection(Player *currentPlayer);
void checkForDirectionOrMove(Player *currentPlayer);
void printInstructionsAfterPlayerMoves();
void displayEmptyBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player *player);
#endif
