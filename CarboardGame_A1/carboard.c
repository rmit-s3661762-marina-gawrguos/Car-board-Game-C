/******************************************************************************
** Student name: 	Marina Gawrguos
** Student number: 	s3661762
** Course: 			Advanced Programming Techniques - S1 2018
******************************************************************************/

#include "carboard.h"

int main()
{
    displayMenu();
    return EXIT_SUCCESS;
}
void displayMenu() {

/*an array of characters which equals to 3(character +\n +\0)*/
    char userInput[INPUTSIZE];
    printf("Welcome to Car Board\n");
    printf("--------------------\n");
    printf("1. Play Game\n");
    printf("2. Show Student's Information\n");
    printf("3. Quit\n");
    printf("\n");
    printf("Please enter your choice:\n");
    /*getting input from user*/
    fgets(userInput, INPUTSIZE, stdin);
    /*an if statement which ultimately checks to see if the last character inputted by the user is a \n to detect buffer overflow*/
    if (userInput[strlen(userInput) - 1] != '\n') {
        readRestOfLine();
    }
    else {
        userInput[strlen(userInput) - 1] = '\0';
        if (strlen(userInput) != INPUT_LENGTH) {
            displayMenu();
        }
        if (strcmp(userInput, "1") == 0) {
            playGame();
        } else if (strcmp(userInput, "2") == 0) {
            showStudentInformation();
        } else if (strcmp(userInput, "3") == 0) {
            printf("Exiting Carboard Game...\n");
            exit(0);
        } else {
            displayMenu();
        }
    }
}

/*method which displays my Student Information*/
void showStudentInformation()
{
    printf("-------------------------\n");
    printf("Name: " STUDENT_NAME"\n");
    printf("No: " STUDENT_ID"\n");
    printf("Email: "STUDENT_EMAIL"\n");
    printf("-------------------------\n");
    displayMenu();
}
