/******************************************************************************
** Student name: 	Marina Gawrguos
** Student number: 	s3661762
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "player.h"
#include "board.h"


void initialisePlayer(Player * player, Position * position, Direction direction)
{
    player->moves=0;
    player->direction=direction;
    player->position.x = position->x;
    player->position.y = position->y;

}

void turnDirection(Player * player, TurnDirection turnDirection)
{
    /*if the user wants to turn right from their current direction*/
    if(turnDirection==TURN_RIGHT&&player->direction==NORTH)
    {
        player->direction=EAST;
    }
    else if(turnDirection==TURN_RIGHT&&player->direction==EAST)
    {
        player->direction=SOUTH;
    }
    else if(turnDirection==TURN_RIGHT&&player->direction==SOUTH)
    {
        player->direction=WEST;
    }
    else if(turnDirection==TURN_RIGHT&&player->direction==WEST)
    {
        player->direction=NORTH;
    }
    /*if the user wants to turn left from their current direction*/
    else if(turnDirection==TURN_LEFT&&player->direction==NORTH)
    {
        player->direction=WEST;
    }
    else if(turnDirection==TURN_LEFT&&player->direction==WEST)
    {
        player->direction=SOUTH;
    }
    else if(turnDirection==TURN_LEFT&&player->direction==SOUTH)
    {
        player->direction=EAST;
    }
    else if(turnDirection==TURN_LEFT&&player->direction==EAST)
    {
        player->direction=NORTH;
    }
}

Position getNextForwardPosition(const Player * player)
{
    Position newPosition;
    newPosition.y=0;
    newPosition.x=0;
    /*if the player wants to move forward and their current direction is NORTH, decrement the y position*/
    if(player->direction==NORTH)
    {
        newPosition.x=player->position.x;
        newPosition.y=player->position.y;
        newPosition.y--;
    }
        /*if the player wants to move forward and their current direction is EAST, increment the x position*/
    else if(player->direction==EAST)
    {
        newPosition.x=player->position.x;
        newPosition.y=player->position.y;
        newPosition.x++;
    }
        /*if the player wants to move forward and their current direction is SOUTH, increment the y position*/
    else if(player->direction==SOUTH)
    {
        newPosition.x=player->position.x;
        newPosition.y=player->position.y;
        newPosition.y++;
    }
        /*if the player wants to move forward and their current direction is WEST, decrement the X position*/
    else if(player->direction==WEST)
    {
        newPosition.x=player->position.x;
        newPosition.y=player->position.y;
        newPosition.x--;
    }
    return newPosition;
}

void updatePosition(Player * player, Position position)
{
    /*update the player's position and increment moves when the player moves forward*/
    player->position.x=position.x;
    player->position.y=position.y;
    player->moves++;
}

void displayDirection(Direction direction)
{
    /*print the arrow based on what the direction is*/
    if(direction==NORTH)
    {
        printf("%s|",DIRECTION_ARROW_OUTPUT_NORTH);
    }
    else if(direction==EAST)
    {
        printf("%s|",DIRECTION_ARROW_OUTPUT_EAST);
    }
    else if(direction==SOUTH)
    {
        printf("%s|",DIRECTION_ARROW_OUTPUT_SOUTH);
    }
    else if(direction==WEST) {
        printf("%s|",DIRECTION_ARROW_OUTPUT_WEST);
    }
}
