/******************************************************************************
** Student name: 	Marina Gawrguos
** Student number: 	s3661762
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "game.h"

void playGame()
{
    /*creating a player Object*/
    Player currentPlayer;
    printf("You can use the following commands to play the game:\n");
    printf("load <g>\n");
    printf("   g:number of the game board to load\n");
    printf("init <x>,<y>,<direction>\n");
    printf("x:horizontal position of the car on the board (between 0 and 9)\n");
    printf("direction:direction of the car's movement (north, east, south, west)\n");
    printf("forward (or f)\n");
    printf("turn_left (or l)\n");
    printf("turn_right (or r)\n");
    printf("quit\n");
    /*calling the display board function and initially passing into it 0 since there is no player when the game is first loaded*/
    displayEmptyBoard(board,0);
    checkInputBoardToLoad();
    getInitialPositionAndDirection(&currentPlayer);
    checkForDirectionOrMove(&currentPlayer);
}

void checkInputBoardToLoad() {
    char *load;
    char userInput[USERINPUTSIZE];
    Boolean valid;
    valid=FALSE;
    while(valid==FALSE){
    printf("At this stage of the program, only two commands are acceptable:\n");
    printf("load <g>\n");
    printf("quit\n");
    fgets(userInput, sizeof(userInput),stdin);
    if (userInput[strlen(userInput) - 1] != '\n') {
        readRestOfLine();
    }
    else {
        userInput[strlen(userInput) - 1] = '\0';
        /*if the comparison of the player's input is quit, then display the menu*/
        if (strcmp(userInput, COMMAND_QUIT) == 0) {
            displayMenu();
            continue;
        } else if (strcmp(userInput, "load \n") == 0) {
            printf("Invalid Input...\n");
            continue;
        }
        load = strtok(userInput, " ");
        if (strcmp(load, COMMAND_LOAD) == 0) {
            load = strtok(NULL, " ");
            if (load == NULL) {
                printf("Invalid Input...\n");
                continue;
            }
            if (strcmp(load, "1") == 0) {
                loadBoard(board, BOARD_1);
                displayBoard(board, NULL);
                valid=TRUE;
            } else if (strcmp(load, "2") == 0) {
                loadBoard(board, BOARD_2);
                displayBoard(board, NULL);
                valid=TRUE;
            }
            else {
                printf("Invalid Input...\n");
                continue;
            }
        }
        else {
            printf("Invalid Input...\n");
            continue;
        }
        }
    }
}


void getInitialPositionAndDirection(Player *currentPlayer)
{
    Position playerPosition;
    Direction currentDirection;
    char *token, *endptr, userInput[USERINPUTSIZE];
    int xPosition, yPosition;
    int num;
    Boolean valid;
    valid=FALSE;
    while(valid==FALSE){
    printf("At this stage of the program, only three commands are acceptable:\n");
    printf("load <g>\n");
    printf("init <x>,<y>,<direction>\n");
    printf("quit\n");
    fgets(userInput, sizeof(userInput), stdin);
        displayBoard(board, currentPlayer);
        if (userInput[strlen(userInput) - 1] != '\n') {
        readRestOfLine();
        }
        else {
        userInput[strlen(userInput) - 1] = '\0';
            if (strcmp(userInput, COMMAND_QUIT) == 0) {
                displayMenu();
            }
            if(strcmp(userInput,"load 1")==0)
            {
                loadBoard(board, BOARD_1);
                displayBoard(board, NULL);
                continue;
            }
            else if(strcmp(userInput,"load 2")==0)
            {
                loadBoard(board, BOARD_2);
                displayBoard(board, NULL);
                continue;
            }
            if(userInput[FOURTH_ARRAY_POS]!=' '||userInput[SIXTH_ARRAY_POS]!=','||userInput[EIGHTH_ARRAY_POS]!=',')
            {
                printf("Invalid Input...\n");
                continue;
            }
            else if (!(strlen(userInput) == MAX_NO_1 || strlen(userInput) == MAX_NO_2)) {
            printf("Invalid Input...\n");
            continue;
        }
        token = strtok(userInput, SPACE_DELIM);
        if (userInput[FIRST_ARRAY_POS] == '\0') {
            printf("Invalid Input...\n");
            continue;
        } else {
            if (strcmp(token, COMMAND_INIT) == 0) {
                printf("we got here\n");
                token = strtok(NULL, COMMA_DELIM);
                printf("%s\n",token);
                num=(int)strtol(token,&endptr,BASE);
                if(token== endptr||*endptr!='\0')
                {
                    printf("Invalid Input...\n");
                    continue;
                }
                xPosition = (int) strtol(token, &endptr, BASE);
                if (xPosition < FAR_LEFT_EDGE || xPosition > FAR_RIGHT_EDGE) {
                    printf("Invalid Input...\n");
                    continue;
                } else if (xPosition >= FAR_LEFT_EDGE && xPosition <= FAR_RIGHT_EDGE) {
                    playerPosition.x = xPosition;
                }
                token = strtok(NULL, COMMA_DELIM);
                num=(int)strtol(token,&endptr,BASE);
                if(token== endptr||*endptr!='\0')
                {
                    printf("Invalid Input...\n");
                    continue;
                }
                yPosition = (int) strtol(token, &endptr, BASE);
                if (yPosition < FAR_LEFT_EDGE || yPosition > FAR_RIGHT_EDGE) {
                    printf("Invalid Input...\n");
                    continue;
                } else if (yPosition >= FAR_LEFT_EDGE && yPosition <= FAR_RIGHT_EDGE) {
                    playerPosition.y = (int) strtol(token, &endptr, BASE);
                }
                if (board[yPosition][xPosition] == BLOCKED) {
                    printf("Cannot initialise Player since cell is blocked.\n");
                    continue;
                }
                token = strtok(NULL, COMMA_DELIM);
                if (strcmp(token, DIRECTION_NORTH) == 0) {
                    currentDirection = NORTH;
                    initialisePlayer(currentPlayer, &playerPosition, currentDirection);
                    placePlayer(board, playerPosition);
                    valid=TRUE;
                } else if (strcmp(token, DIRECTION_EAST) == 0) {
                    currentDirection = EAST;
                    initialisePlayer(currentPlayer, &playerPosition, currentDirection);
                    placePlayer(board, playerPosition);
                    valid=TRUE;
                } else if (strcmp(token, DIRECTION_SOUTH) == 0) {
                    currentDirection = SOUTH;
                    initialisePlayer(currentPlayer, &playerPosition, currentDirection);
                    placePlayer(board, playerPosition);
                    valid=TRUE;
                } else if (strcmp(token, DIRECTION_WEST) == 0) {
                    currentDirection = WEST;
                    initialisePlayer(currentPlayer, &playerPosition, currentDirection);
                    placePlayer(board, playerPosition);
                    valid=TRUE;
                }
            } else {
                printf("Invalid Input...\n");
                continue;
            }
        }
    }
    }
    }


/*method to check if the input by the player is a turn left,turn right or forward command*/
void checkForDirectionOrMove(Player *currentPlayer) {
    char input[INPUTSIZE];
    TurnDirection turn;
    Boolean stop;
    stop = FALSE;
    printInstructionsAfterPlayerMoves();
    while (stop == FALSE) {
        displayBoard(board, currentPlayer);
        printInstructionsAfterPlayerMoves();
        fgets(input, sizeof(input), stdin);
        if (input[strlen(input) - 1] != '\n') {
            readRestOfLine();
        } else {
            input[strlen(input) - 1] = '\0';
            if (strcmp(input, COMMAND_TURN_RIGHT) == 0 || strcmp(input, COMMAND_TURN_RIGHT_SHORTCUT) == 0) {
                turn = TURN_RIGHT;
                turnDirection(currentPlayer, turn);

            } else if (strcmp(input, COMMAND_TURN_LEFT) == 0 || strcmp(input, COMMAND_TURN_LEFT_SHORTCUT) == 0) {
                turn = TURN_LEFT;
                turnDirection(currentPlayer, turn);

            } else if (strcmp(input, COMMAND_FORWARD) == 0 || strcmp(input, COMMAND_FORWARD_SHORTCUT) == 0) {
                movePlayerForward(board, currentPlayer);

            } else if (strcmp(input, COMMAND_QUIT) == 0) {
                printf("Total Player moves: %d\n", currentPlayer->moves);
                stop = TRUE;
                displayMenu();
            } else {
                printf("Invalid Input...\n");
            }
        }
    }
}

/*method that prints the instructions while player plays the game
which will be called after the player either moves forward or changes direction*/
void printInstructionsAfterPlayerMoves()
{
    printf("You can use the following commands to play the game:\n");
    printf("load <g>\n");
    printf("   g:number of the game board to load\n");
    printf("init <x>,<y>,<direction>\n");
    printf("x:horizontal position of the car on the board (between 0 and 9)\n");
    printf("direction:direction of the car's movement (north, east, south, west)\n");
    printf("forward (or f)\n");
    printf("turn_left (or l)\n");
    printf("turn_right (or r)\n");
    printf("quit\n");
}

/*method that initialises and displays the board*/
void displayEmptyBoard(Cell board[BOARD_HEIGHT][BOARD_WIDTH], Player *player)
{
    initialiseBoard(board);
    displayBoard(board, 0);
}
