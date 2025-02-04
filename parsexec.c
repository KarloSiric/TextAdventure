/*
 * @Author: karlosiric
 * @Date:   2025-02-04 20:08:48
 * @Last Modified by:   karlosiric
 * @Last Modified time: 2025-02-04 22:59:29
 */

/*
 * this here will be the parseAndExecute function and it is in another file,
 * because it will be changing from chapter to chapter And it might grow and so
 * forth so it is better to have it in another file just to keep things clean
 * and neat.
 */

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

bool parseAndExecute(const char *input) // this is a function that takes as a
                                        // param a string and returns a boolean
{
    // we will use something called strtok function from string.h that is used
    // to split a string into tokens strtok is used to split a string into
    // tokens First token is the verb going to be used

    char *verb = strtok(input, " \n"); // this will split the string into
                                       // tokens, the first token is the verb
    char *noun = strtok(NULL, " \n");  // the second token is the noun, NULL is used here
                                       // to continue from the last call of strtok
                                    
    // we will use the strcmp function from string.h to compare the verb and
    // noun
    
    /*
     * Also we can try doing the following, we can try making the tolower work for the verb so we can make the verb case insensitive
     */
    
    for (char *p = verb; *p != '\0'; p++)
    {
        *p = tolower(*p);
    }
    
    if (verb != NULL) // if the verb is not null
    {
        if (strcmp(verb, "quit") == 0) 
        {
            return false; // if the verb is quit we return false and then that will break the while loop inside main.c
        }
        else if (strcmp(verb, "look") == 0) 
        {
            printf("It is very dark in here.\n");
        }
        else if (strcmp(verb, "go") == 0) 
        {
            printf("It's too dark to go anywhere.\n");
        }
        else if (strcmp(verb, "take") == 0) 
        {
            if (noun != NULL) 
            {
                printf("I don't see a %s here.\n", noun);
            }
            else 
            {
                printf("Take what?\n");
            }
        }
        else if (strcmp(verb, "drop") == 0) 
        {
            if (noun != NULL) 
            {
                printf("You don't have a %s.\n", noun);
            }
            else 
            {
                printf("Drop what?\n");
            }
        }
        else 
        {
            printf("I don't know how to '%s'.\n", verb); // here '%s' acts as a placeholder for the verb
        }
    }
    
    return true;
}

/*
 * Point of this is the following, so that the player can freely use and type in some commands such as quit look and go without the program caring about what else comes after those verbs, brilliant!
 */