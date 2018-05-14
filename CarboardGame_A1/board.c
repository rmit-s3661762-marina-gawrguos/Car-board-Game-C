
/******************************************************************************
** Student name: 	Marina Gawrguos
** Student number: 	s3661762
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "board.h"
Cell board[BOARD_HEIGHT][BOARD_WIDTH];
Cell BOARD_1[BOARD_HEIGHT][BOARD_WIDTH] =
        {
                { BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
                { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY },
                { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, BLOCKED, EMPTY, BLOCKED, EMPTY, EMPTY },
                { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY },
                { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED }
        };

Cell BOARD_2[BOARD_HEIGHT][BOARD_WIDTH] =
        {
                { BLOCKED, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, EMPTY, EMPTY, EMPTY, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY },
                { EMPTY, BLOCKED, BLOCKED, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY, EMPTY }
        };

void initialiseBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH])
{
    /*i represents the board height and j represents the board width*/
    int i;
    int j;
    /*loop that iterates and assigns each item in the 2D to EMPTY*/
    for (i=0;i<BOARD_HEIGHT;i++)
    {
        for (j=0;j<BOARD_WIDTH;j++)
        {
            board[i][j]=EMPTY;
        }
    }
}

void loadBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH],
               Cell boardToLoad[BOARD_HEIGHT][BOARD_WIDTH])
{

    int i;
    int j;
/*loop that iterates and assigns the empty board to the board to Load*/
    for(i=0;i<BOARD_HEIGHT;i++)
    {
        for(j=0;j<BOARD_WIDTH;j++)
        {
                board[i][j]=boardToLoad[i][j];
        }
    }

}

Boolean placePlayer(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Position position)
{
/*check to see if the position to place player is either blocked, at the far left edge of board or at the far right edge of the board*/
    if(board[position.y][position.x]==BLOCKED||position.x>FAR_RIGHT_EDGE||position.x<FAR_LEFT_EDGE||position.y>FAR_RIGHT_EDGE||position.y<FAR_LEFT_EDGE)
    {
        return FALSE;
    }
        /*if position is empty, assign the position to PLAYER*/
    else if(board[position.y][position.x]==EMPTY)
    {
        board[position.y][position.x]=PLAYER;
        return TRUE;
    }
    return FALSE;
}

    PlayerMove movePlayerForward(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player *player) {
        int newXposition;
        int newYposition;
        Position playerPosition;
        newXposition=getNextForwardPosition(player).x;
        newYposition=getNextForwardPosition(player).y;
        /*if player moves forward to a blocked cell, print the following error message*/
                if (board[newYposition][newXposition]==BLOCKED)
                {
                    printf("Error: Cannot move forward because the road is blocked.\n");
                    return CELL_BLOCKED;
                }
                    /*if player moves forward to the far left, right,top or bottom of the board, print the following error message*/
                else if(newXposition<FAR_LEFT_EDGE||newXposition>FAR_RIGHT_EDGE||newYposition<FAR_LEFT_EDGE||newYposition>FAR_RIGHT_EDGE)
                {
                    printf("The player is at the edge of the board and cannot move further in that direction.\n");
                    return OUTSIDE_BOUNDS;
                }
                    /*if the player moves forward to an empty position, assign the new position to the PLAYER and update their position*/
                else  if(board[newYposition][newXposition]==EMPTY)
                {
                    board[player->position.y][player->position.x]=EMPTY;
                    playerPosition.x=newXposition;
                    playerPosition.y=newYposition;
                    board[newYposition][newXposition]=PLAYER;
                    updatePosition(player,playerPosition);
                    return PLAYER_MOVED;
                }


        return PLAYER_MOVED;
    }

    void displayBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player *player)
    {


        /*variable i represents height and j represents the width*/
        int i;
        int j;
        printf("| |0|1|2|3|4|5|6|7|8|9|\n");
        /*loop that iterates and checks if the board[i][j] is either a blocked/empty/player output and print it out*/
        for (i = 0; i < BOARD_HEIGHT; i++) {
            printf("|%d|", i);
            for (j = 0; j < BOARD_WIDTH; j++) {
                if (board[i][j] == BLOCKED) {
                    printf("%s|", BLOCKED_OUTPUT);
                } else if (board[i][j] == EMPTY) {
                    printf("%s|", EMPTY_OUTPUT);
                }
                else if(board[i][j]==PLAYER)
                {
                    displayDirection(player->direction);

                }
                else {
                    printf("|");
                }
            }
            printf("\n");
        }
    }




