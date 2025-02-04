/*
 * @Author: karlosiric
 * @Date:   2025-02-04 19:17:06
 * @Last Modified by:   karlosiric
 * @Last Modified time: 2025-02-04 19:42:55
 */

/*
 * Here I will be coding the game called text adventure I will be following
 * alongside a tutorial. I will be coding the game in C and learning C alongside
 * as I code. This is for me to learn C and a project to work on for myself to
 * keep me busy.
 *
*/
#include <stdbool.h>
#include <stdio.h>
#include "parsexec.h" // we need to have a function where the user parses and it executes the command from the user

/*
 * We started off with the simple code, moving on to next:
 * We have a function getInput, also the parse and execute function for executing the user commands and also main
 */
static char input[100] = "look around"; // this is for storing the user input

static bool getInput(void) 
{
    printf("\n--> ");
    return fgets(input, sizeof(input), stdin) != NULL;
}

int main(void)
{
    
    
    printf("Welcome to the Little Cave Adventure\n");
    printf("It is very dark in here.\n");
    printf("\nBye!\n");
    return 0; // this included that indicates the program ran successfully
}
